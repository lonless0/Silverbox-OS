#include <stdio.h>

FILE _std_files[3] =
{
  { 0, ACCESS_RD, _IONBF, 0, 0, 0, 0, { '\0' }, 0, 0, 0, 0, NULL, BUFSIZ, 0 },
  { 0, ACCESS_WR, _IOLBF, 0, 0, 0, 0, { '\0' }, 0, 0, 0, 0, NULL, BUFSIZ, 0 },
  { 0, ACCESS_WR, _IONBF, 0, 0, 0, 0, { '\0' }, 0, 0, 0, 0, NULL, BUFSIZ, 0 }
};
