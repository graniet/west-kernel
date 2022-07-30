#include "../lib/type.h"

void * memset(void * ptr, int c, int v) {

  char * c_ptr = (char *) ptr;
  for (int x = 0; x <= c; x++) {
    c_ptr[x] = (char) v;
  }
  return ptr;
}
