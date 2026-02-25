#include <stdlib.h>

char *smash (const char *const words[/* count */], size_t count)
{
// allocate a string on the heap, memory will be freed
  size_t mem_size = 1;
  size_t string_size = 0;
	char *head = *p = calloc(1, mem_size);
  if (sizeof(words) > 0) {
    for (int i = 0; i < count; i++) {
      int j = 0;
      while (words[i][j] != '\0') {
        if (mem_size < string_size) {
          mem_size *= 2;
          head = realloc(head, mem_size);
          
        }
        *p++ = words[i][j];
        j++;
      }
      *p++ = ' ';
    }
    *--p = '\0';
  }
  return head;
}