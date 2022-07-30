#include "heap.h"

void * kmalloc(int size) {
  test_malloc(size);
}

void kfree(void * ptr) {}
