#ifndef MM_H
#define MM_H

#include <types.h>
#include <kernel/multiboot.h>
#include <kernel/lowlevel.h>
#include <kernel/paging.h>

/* FIXME: Changing any of these values may require changing
   the asm code */

#define BOOTSTRAP_VSTART    	0x1000000
#define BOOTSTRAP_START     	0x1000000

#define KERNEL_VSTART       	((u32)&kVirtStart)
#define PHYSMEM_START       	((u32)&VPhysMemStart)
#define KERNEL_START        	((u32)&kPhysStart)
#define RESD_PHYSMEM	    	KERNEL_START

/* FIXME: Changing any of these values may require changing the 
   asm code. */

#define KERNEL_IDT		((u32)&_kernelIDT)
#define KERNEL_GDT		((u32)&_kernelGDT)
#define KERNEL_TSS		((u32)&_kernelTSS)

#define TSS_IO_PERM_BMP		(PHYSMEM_START + 0xC0000)
#define TEMP_PAGEADDR           (TSS_IO_PERM_BMP + 2 * PAGE_SIZE)
#define LAPIC_VADDR             (TEMP_PAGEADDR + PAGE_SIZE)
#define KERNEL_VAR_ADDR		(LAPIC_VADDR + PAGE_SIZE)

#define V_IDLE_STACK_TOP	(PHYSMEM_START + IDLE_STACK_TOP)
#define V_KERNEL_STACK_TOP	(PHYSMEM_START + KERNEL_STACK_TOP)

#define KERNEL_IO_BITMAP	((u32)&_kernelIOBitmap)
#define INIT_PDIR		((u32)&_initKrnlPDIR)
#define KERNEL_PAGE_TAB         ((u32)&_firstKrnlPTAB)
#define INIT_SERVER_PDIR        ((u32)&_initServPDIR)
#define INIT_SERVER_USTACK_PTAB ((u32)&_initServStackPTAB)
#define INIT_SERVER_USTACK_PAGE ((u32)&_initServStack)
#define INIT_SERVER_PTAB        ((u32)&_initServPTAB)
#define IDLE_STACK_TOP		((u32)&_idleStack + PAGE_SIZE)
#define KERNEL_STACK_TOP	((u32)&_kernelStack + PAGE_SIZE)
#define KERNEL_VAR_PAGE		((u32)&_kernelVars)
#define FIRST_PAGE_TAB		((u32)&_firstPTAB)
#define KERNEL_PAGE_TAB2	((u32)&_secondKrnlPTAB)
#define BOOTSTRAP_STACK_TOP	((u32)&_kernelBootStack + PAGE_SIZE)

#define INVALID_VADDR       (void *)0xFFFFFFFF
#define INVALID_ADDR        (void *)0xFFFFFFFF

/// Aligns an address to the next page boundary (if not already aligned)
#define PAGE_ALIGN(addr)    ALIGN(PAGE_SIZE, addr)

/// Aligns an address to the next boundary (if not already aligned)
#define ALIGN(mod, addr)    (((addr == ALIGN_DOWN(mod, addr)) ? (addr_t)addr : \
                               ((addr_t)(((u32)ALIGN_DOWN(mod, addr)) + mod)) ))

/// Aligns an address to the previous boundary (if not already aligned)
#define ALIGN_DOWN(mod, addr) ((addr_t)( (u32)addr & ~(mod - 1) ))

/// Maps a physical address to a virtual address into the current address space
#define kMapMem( virt, phys, flags ) ( kMapPage( virt, phys, flags ) )

/// Unmaps a virtual address from the current address space
#define kUnmapMem( virt ) ( kUnmapPage( virt ) )

/// Temporarily maps a physical page into the current address space
#define mapTemp( phys ) kMapMem((void *)(TEMP_PAGEADDR), phys, PAGING_RW)

/// Unmaps the temporary page
#define unmapTemp() 	kUnmapMem((void *)(TEMP_PAGEADDR))

bool tempMapped;

pdir_t *kernelAddrSpace;
/*
size_t totalPhysMem;
addr_t startPhysPages;
uint32 totalPages;
uint32 totalKSize;
multiboot_info_t *grubBootInfo;
addr_t modulesStart;
size_t totalModulesSize;
*/
HOT(int _writePDE( unsigned entryNum, pde_t *pde, void * addrSpace ));
HOT(int _readPDE( unsigned entryNum, pde_t *pde, void * addrSpace ));
HOT(int readPDE( void * virt, pde_t *pde, void * addrSpace ));
HOT(int readPTE( void * virt, pte_t *pte, void * addrSpace ));
HOT(int writePTE( void * virt, pte_t *pte, void * addrSpace ));
HOT(int writePDE( void * virt, pde_t *pde, void * addrSpace ));

int mapPageTable( void *virt, void *phys, u32 flags, void *addrSpace );
HOT(int kMapPage( void *virt, void *phys, u32 flags ));
HOT(int mapPage( void *virt, void *phys, u32 flags, void *addrSpace ));
HOT(addr_t kUnmapPage( void *virt ));
HOT(addr_t unmapPage( void *virt, void *addrSpace ));
addr_t unmapPageTable( void *virt, void *addrSpace );

HOT(int accessMem( void *address, size_t len, void *buffer, void *addrSpace, bool read ));
HOT(int peekMem( void *address, size_t len, void *buffer, void *addrSpace ));
HOT(int pokeMem( void *address, size_t len, void *buffer, void *addrSpace ));

bool is_readable( void *addr, void *addrSpace );
bool is_writable( void *addr, void *addrSpace );

//extern void addGDTEntry( word, addr_t, uint32, uint32 );

#endif
