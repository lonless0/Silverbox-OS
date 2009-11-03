#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
  unsigned char *str1, *str2;

  str1 = (unsigned char *)s1;
  str2 = (unsigned char *)s2;

  if( s1 == NULL || s2 == NULL )
    return -1;

  while(*str1++ == *str2++ && n--);

  return (int)(*(unsigned char *)--str1 - *(unsigned char *)--str2);
}
