#include "../lib/type.h"

void * memset(void * ptr, int size, int value) {

  char * c_ptr = (char *) ptr;
  for (int x = 0; x <= size; x++) {
    c_ptr[x] = (char) value;
  }
  return ptr;
}
