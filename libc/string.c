#include "../drivers/display.h"
/*
 * convert int to string
 */
void itoa(int n, char str[]) {
  int i, sign;
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    str[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    str[i++] = '-';
  str[i] = '\0';

  reverse(str);
}

/*
 * reverse a string order
 */
void reverse(char *s) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


    /*
     * just compare string and return -1 if not equal.
     */
int strcmp(char *str1, char *str2) {
  if (strlen(str1) != strlen(str2)) {
    return -1;
  }


  for (int x = 0; str1[x] != 0; x++) {
    if (str1[x] != str2[x]) {
      return -1;
    }
  }

  return 0;
}

/*
 * count a char available into string
*/
int strlen(char *s) {
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
