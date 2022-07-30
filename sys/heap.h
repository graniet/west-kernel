#include "../lib/type.h"

#define HEAP_KERNEL_START_ADDRESS 0x01000000
#define HEAP_KERNEL_BLOCK_SIZE 4096
#define HEAP_KERNEL_TOTAL_SIZE 104857600 // 100mb ((1024*1024) * 100)

#define HEAP_KERNEL_ENTRY_FREE 0b00000000
#define HEAP_KERNEL_ENTRY_TAKEN 0b10000000
#define HEAP_KERNEL_ENTRY_HAS_NEXT 0b01000000

typedef u8 HEAP_KERNEL_ENTRY;

typedef struct sys_heap_index {
  HEAP_KERNEL_ENTRY * entries;
  int entries_size;
} sys_heap_index_t;

/*
 * kernel heap data struct
 * entries is 8 bits flags
 * entries_size is a amount of entries available
 * start_adress is a start_address for the heap
 */
typedef struct sys_heap {
  sys_heap_index_t * index;
  void * start_address;
} sys_heap_t;


void init_heap();

int set_block_free(sys_heap_t *, int);
int set_block_taken(sys_heap_t *, int);
int search_available_block(sys_heap_t *, int);
void * _kmalloc(int);
int _kfree(void * ptr);
