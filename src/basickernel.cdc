#define SORT_NAME int64
#define SORT_TYPE int64_t
#define SORT_CMP(x, y) ((x) - (y))
#include "sort.h"
#include "mini_uart.h"

void* realloc(void* ptr, size_t size)
{
	void* new_data = NULL;

	if(size)
	{
		if(!ptr)
		{
			return ta_alloc(size);
		}

		new_data = ta_alloc(size);
		if(new_data)
		{
			memcpy(new_data, ptr, size); // TODO: unsafe copy...
			ta_free(ptr); // we always move the data. free.
		}
	}

	return new_data;
}

void* reallocf(void* ptr, size_t size)
{
	void* p = realloc(ptr, size);

	if((p == NULL) && (ptr != NULL))
	{
		ta_free(ptr);
	}

	return p;
}

void *
memcpy (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}

void *
memmove (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
    {
      char *lasts = s + (len-1);
      char *lastd = d + (len-1);
      while (len--)
        *lastd-- = *lasts--;
    }
  return dest;
}

void kernel_main(void)
{
	uart_init();
	uart_send_string("Hello, world!\r\n");

    int i = 0;
	while (i <= 1000) {
		uart_send_string("Counted Up!\n");
	}
}
