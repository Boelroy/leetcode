#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int isValid(char* s);

int main(int argc, char *argv[])
{
  printf("%d\n", isValid("()"));
  return 0;
}

int isValid(char* s) {
  if (s == NULL) return 1;
  int bottom = 0;
  char stack[strlen(s)];
  char *iter = s;
  while(*iter != '\0') {
    switch( *iter ) {
      case '(':
      case '[':
      case '{':
        stack[bottom++] = *iter;
        break;
      case ')':
        if (bottom == 0) return false;
        if (stack[bottom -1 ] == '(') bottom--;
        else return 0;
        break;
      case ']':
        if (bottom == 0) return false;
        if (stack[bottom - 1] == '[') bottom--;
        else return 0;
        break;
      case '}':
        if (bottom == 0) return false;
        if (stack[bottom - 1] == '}') bottom--;
        else return 0;
        break;
    }
    iter++;
  }
  return bottom == 0;
}
