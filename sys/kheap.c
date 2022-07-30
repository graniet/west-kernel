#include "heap.h"

void * kmalloc(int size) {
  _kmalloc(size);
}

void kfree(void * ptr) {
  _kfree(ptr);
}
