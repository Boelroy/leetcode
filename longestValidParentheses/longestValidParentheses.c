int longestValidParentheses(char* s) {
  if (s == NULL) return 0;

  int bottom = 0, max = 0, i = 0, left = -1;
  int stack[strlen(s)];

  char *iter = s;

  while(*iter != '\0') {
    if(*iter == '(') {
        stack[bottom++] = i;
    }
    else {
        if (bottom > 0){
            bottom--;
            if (bottom == 0){
                if (i - left > max) {
                    max = i - left;
                }
            } else {
                if (i - stack[bottom - 1] > max) {
                    max = i - stack[bottom - 1];
                }
            }
        } else {
            left = i;
        }
    }
    i++;
    iter++;
  }
  return max;
}
