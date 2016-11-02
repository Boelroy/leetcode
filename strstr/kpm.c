#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int kmp(char* haystack, char * needle);

int main(int argc, char *argv[])
{
  printf("%d\n",kmp("ababaa", "ab"));
  printf("%d\n",kmp("ababaa", "ababa"));
  printf("%d\n",kmp("aaa", "bb"));
  return 0;
}

int *calculate_prefix_func_table(char* needle) {
  int length = strlen(needle);
  int *prefix_func_table = (malloc(sizeof(int) * (length + 1)));
  int k = -1;
  prefix_func_table[0] = -1;
  for (int q = 0; q < length; ) {
    while( k >= 0 && needle[k + 1] != needle[q]) {
      k = prefix_func_table[k];
    }
    k++;q++;
    prefix_func_table[q] = k;
  }
  for (int i = 0; i < length; ++ i) {
    printf("%d ", prefix_func_table[i]);
  }
  printf("\n");
  return prefix_func_table;
}

int kmp(char* haystack, char * needle) {
  int *prefix_func_table = calculate_prefix_func_table(needle);
  int k = 0;
  int i = 0;
  char* haystackIter = haystack;
  while(*haystackIter != '\0') {
    while(k >= 0 && *haystackIter != needle[k]) k = prefix_func_table[k];
    k++;i++;
    printf("%d\n", k);
    if (*(needle + k) == '\0') return i - k;
    haystackIter++;
  }
  return -1;
}
