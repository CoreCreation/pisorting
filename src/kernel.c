//These are the CONSTS for the memory management
//There is currently no memory management in this code, but if there SHOULD be memory
//these consts should point to where various memory is
//For example, the start and end of the heap
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

//The sorts
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "bubbleSort.h"
#include <stddef.h>

//This is for the connection to the uart
#include "mini_uart.h"
#include "printf.h"

//Change the input
#include "100K10.h"
#define NUMLENGTH 100000
#define RUNS 20


// This function is required by printf function
//It put prints characters to the console
void putc(void *p, char c)
{
  uart_send(c);
}

void * memcpy(void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
//This is the main program, it runs this
void kernel_main(void)
{

  uart_init(); //Starts the connection to UART
  init_printf(0, putc); //Inits the printf, must be run before using printf
  printf("Starting\n");
  int dst[NUMLENGTH];
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
