#include "heap.h"
#include "../libc/mem.h"
#include "../drivers/display.h"
#include "../libc/string.h"

sys_heap_t heap;
sys_heap_index_t heap_index;
/*
 * initilialization of heap and index
 * index is on real mode memory space (the first 1mb bytes)
 * heap chunk is on other memory space > of 1 mega byte
 */
void init_heap() {

  int entries_size = (HEAP_KERNEL_TOTAL_SIZE / HEAP_KERNEL_BLOCK_SIZE);
  HEAP_KERNEL_ENTRY * entries = (HEAP_KERNEL_ENTRY *) HEAP_KERNEL_START_ADDRESS;

  void *start_address = (void *) HEAP_KERNEL_START_ADDRESS + entries_size;

  heap_index.entries = entries;
  heap_index.entries_size = entries_size;

  memset(&heap, sizeof(sys_heap_t), 0);
  heap.index = &heap_index;
  heap.start_address = start_address;

  int index_size = sizeof(HEAP_KERNEL_ENTRY) * entries_size;
  memset(heap_index.entries, index_size, 0);
  return;
}


void test_malloc(int size) {
  search_available_block(&heap, size);
}

int search_available_block(sys_heap_t * p_heap, int size) {
  for (int x = 0; x <= p_heap->index->entries_size; x++) {
    HEAP_KERNEL_ENTRY entry = p_heap->index->entries[x];

    if ((entry & 0x0f) == HEAP_KERNEL_ENTRY_FREE) {
      HEAP_KERNEL_ENTRY taken = HEAP_KERNEL_ENTRY_TAKEN;
      p_heap->index->entries[x] |= taken;
    } else {
      kprint("TAKEN !\n");
    }
  }

  kprint("ret\n");
  return 0;
}
