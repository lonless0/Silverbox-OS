#ifndef ADDR_SPACE_H
#define ADDR_SPACE_H

#include <os/bitmap.h>
#include "list.h"
#include "phys_alloc.h"
#include <os/os_types.h>
#include <os/region.h>
#include <stddef.h>
#include <oslib.h>

#define MEM_RO		1	// Read-only memory range
#define MEM_COW		2	/* Range is copy-on-write (if written to, copy 
				   range to another set of pages & mark that
				   range as read-write [implies read-only]). */
#define MEM_LAZY	4	// Do not immediately map the range into memory
#define MEM_MAP		8	/* Map virtual addresses to a specific physical 
                                   addresses (as opposed to mapping virtual 
				   addresses to any physical addresses. */
#define MEM_ZERO	16	// Clear an address range before mapping it.

#define NUM_PTABLES     1024

#define REG_NOEXIST	0
#define REG_PHYS	1
#define REG_FILE	2

/*
  Addresses in an address space can be non-existant, correspond to physical
  memory, or file. An address region may be swapped out to disk.

*/

struct AddrRegion
{
  struct MemRegion virtRegion;
  struct MemRegion physRegion;
  int flags;
};

struct AddrSpace
{
  void *phys_addr;
  struct ListType mem_region_list;
  SBArray memoryRegions;
  bitmap_t bitmap[NUM_PTABLES / 8];
};

struct _Thread
{
  tid_t tid;
  void *aspace_phys;
};

struct Executable
{
  char *codeStart;
  char *dataStart;
  char *bssStart;

  size_t codeLen;
  size_t dataLen;
  size_t bssLen;
};

struct ListNode *free_list_nodes;
struct ListType addr_space_list;

SBAssocArray addrSpaces; // phys_addr -> struct AddrSpace
SBAssocArray threadTable; // tid -> struct _Thread

void *list_malloc( size_t size );
void list_free( void *node );

void init_addr_space(struct AddrSpace *addr_space, void *phys_addr);
int addAddrSpace(struct AddrSpace *addrSpace);
struct AddrSpace *lookupPhysAddr(void *phys_addr);
struct AddrSpace *removeAddrSpace(void *phys_addr);

bool get_ptable_status(void *aspace_phys, void *virt);
int set_ptable_status(void *aspace_phys, void *virt, bool status);

int attach_tid(void *aspace_phys, tid_t tid);
int detach_tid(tid_t tid);
void *lookup_tid(tid_t tid);
struct AddrSpace *_lookup_tid(tid_t tid);

int attach_mem_region(void *aspace_phys, struct AddrRegion *region);
int _attach_mem_region(struct AddrSpace *addr_space, struct AddrRegion *region);
bool _region_overlaps(struct AddrSpace *addr_space, struct MemRegion *region);
bool region_overlaps(void *aspace_phys, struct MemRegion *region);
bool find_address(void *aspace_phys, void *addr);
bool _find_address(struct AddrSpace *addr_space, void *addr);

#endif /* ADDR_SPACE_H */
