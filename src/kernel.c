//These are the CONSTS for the memory management
#define _P_BASE_H

#define PBASE 0x3F000000
#define PAGE_SHIFT 12
#define TABLE_SHIFT 9
#define SECTION_SHIFT (PAGE_SHIFT + TABLE_SHIFT)

#define PAGE_SIZE (1 << PAGE_SHIFT)
#define SECTION_SIZE (1 << SECTION_SHIFT)

#define LOW_MEMORY (2 * SECTION_SIZE)
#define HIGH_MEMORY PBASE

#define PAGING_MEMORY (HIGH_MEMORY - LOW_MEMORY)
#define PAGING_PAGES (PAGING_MEMORY / PAGE_SIZE)

#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "bubbleSort.h"
#include <stddef.h>
//#include "tinyalloc.h"

/*
//These are the options for the sorting algos
#define SORT_NAME int64
#define SORT_TYPE int64_t
#define SORT_CMP(x, y) ((x) - (y))
#include "sort.h" */
//This is for the connection to the uart
#include "mini_uart.h"
#include "printf.h"

//Change the input
#include "100K10.h"
#define NUMLENGTH 100000
#define RUNS 20

//These are the helper functions that the sorting algos need to run!
// This function is required by printf function
void putc(void *p, char c)
{
  uart_send(c);
}

void *
memcpy(void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}
/*void *realloc(void *ptr, size_t size)
{
  void *new_data = NULL;

  if (size)
  {
    if (!ptr)
    {
      return ta_alloc(size);
    }

    new_data = ta_alloc(size);
    if (new_data)
    {
      memcpy(new_data, ptr, size); // TODO: unsafe copy...
      ta_free(ptr);                // we always move the data. free.
    }
  }

  return new_data;
}

void *reallocf(void *ptr, size_t size)
{
  void *p = realloc(ptr, size);

  if ((p == NULL) && (ptr != NULL))
  {
    ta_free(ptr);
  }

  return p;
}

void *
memmove(void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
  {
    char *lasts = s + (len - 1);
    char *lastd = d + (len - 1);
    while (len--)
      *lastd-- = *lasts--;
  }
  return dest;
}
*/
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/*
size_t int2size_t(int val) {
    return (val < 0) ? __SIZE_MAX__ : (size_t)((unsigned)val);
}
*/

void kernel_main(void)
{

  uart_init();
  init_printf(0, putc);
  printf("Starting\n");
  int dst[NUMLENGTH];
  //size_t split_thresh = 16;
  //size_t heap_blocks = 256;
  //size_t alignment = 64;
  //printf("initing heap\n");
  //ta_init(LOW_MEMORY, HIGH_MEMORY, heap_blocks, split_thresh, alignment);

  //printf("entering for loop\n");
  for (int i = 0; i < RUNS; i++)
  {
    //printf("Moving the numbers\n");
    memcpy(dst, nums, sizeof(int) * NUMLENGTH);
    //printf("Sorting the numbers #%d out of %d\n", i + 1, RUNS);
    heapSort(dst, NUMLENGTH);
    //quickSort(dst, 0, NUMLENGTH - 1);
    //mergeSort(dst, 0, NUMLENGTH - 1);
    //bubbleSort(dst, NUMLENGTH);
  }
  printf("Sort is done\n");
  /*for (int i = 0; i < NUMLENGTH; i++)
  {
    printf("%d\n", dst[i]);
  }*/
}
