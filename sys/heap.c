#include "heap.h"
#include "../libc/mem.h"
#include "../drivers/display.h"
#include "../libc/string.h"

sys_heap_t heap;
sys_heap_index_t heap_index;

int set_heap(sys_heap_t *heap, sys_heap_index_t * index) {
  int entries_size = (HEAP_KERNEL_TOTAL_SIZE / HEAP_KERNEL_BLOCK_SIZE);
  int index_size = sizeof(HEAP_KERNEL_ENTRY) * entries_size;
  memset(index->entries, index_size, 0);

  index->entries_size = entries_size;
  heap->start_address = (void *) HEAP_KERNEL_START_ADDRESS + entries_size;
  heap->index = index;

  HEAP_KERNEL_ENTRY entry = (HEAP_KERNEL_ENTRY) index->entries[0];
  if ((entry & (1 << 7)) != 0 ) {
    return -1;
  }

  return 0;
}

/*
 * initilialization of heap and index
 * index is on real mode memory space (the first 1mb bytes)
 * heap chunk is on other memory space > of 1 mega byte
 */
void init_heap() {

  HEAP_KERNEL_ENTRY * entries = (HEAP_KERNEL_ENTRY *) HEAP_KERNEL_START_ADDRESS;

  memset(&heap_index, sizeof(sys_heap_index_t), 0);
  heap_index.entries = entries;

  memset(&heap, sizeof(sys_heap_t), 0);

  if (set_heap(&heap, &heap_index) == -1) {
    kprint("error with heap index initialization.\n");
    return;
  }
}

/*
 * real kmalloc function
 * use a size for getting a block pos (only one for now, one=4096bytes)
 * also we set a block as taken with a first high bit to one
 */
void  * _kmalloc(int size) {
  int block_pos = search_available_block(&heap, size);
  if (set_block_taken(&heap, block_pos) == -1) {
    kprint("error in set block to taken...\n");
    return;
  }
  void * block_address = heap.start_address + (block_pos * HEAP_KERNEL_BLOCK_SIZE);
  return block_address;
}

/*
 * real kfree function
 * this function use a ptr in argument
 * this ptr is a memory pointer in heap, we get a block position with ptr - start / 4096
 * we memset to 0 a block size
 * and final we mark a block to free in index
 */
int _kfree(void * ptr) {
  int block_pos = ((int) ptr - (int)heap.start_address) / HEAP_KERNEL_BLOCK_SIZE;
  int size_to_free = sizeof(HEAP_KERNEL_ENTRY) * (block_pos * HEAP_KERNEL_BLOCK_SIZE);
  memset(ptr, size_to_free, 0);
  if (set_block_free(&heap, block_pos) == -1) {
    kprint("error in free.\n");
    return -1;
  }

  return 0;
}

/*
 * set a high bit of index to zero, this equal to block free
 * also we check is a 8th bit is really with 0 value
 */
int set_block_free(sys_heap_t * p_heap, int block_pos) {
  p_heap->index->entries[block_pos] &= HEAP_KERNEL_ENTRY_FREE;

  if((p_heap->index->entries[block_pos] & (1 << 7)) != 0) {
    return -1;
  }
  return 0;
}

/*
 * set a high bit of index to one, this equal to block taken
 * also we check if a 8th bit (start at 0) is really set to 1
 */
int set_block_taken(sys_heap_t * p_heap, int block_pos) {
  p_heap->index->entries[block_pos] |= HEAP_KERNEL_ENTRY_TAKEN;

  if ((p_heap->index->entries[block_pos] & (1 << 7)) == 0) {
    return -1;
  }
  return 0;
}

/*
 * here we searching a first available block available in heap index
 */
int search_available_block(sys_heap_t * p_heap, int size) {
  char entries_size[3];
  itoa(p_heap->index->entries_size, entries_size);
  kprint("total entries = ");
  kprint(entries_size);
  kprint("\n");
  for (int x = 0; x <= p_heap->index->entries_size; x++) {
    if ((p_heap->index->entries[x] & (1 << 7)) == 0) {
      return x;
    }
  }
  return -1;
}
