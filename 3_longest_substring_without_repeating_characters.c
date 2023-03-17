#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char *s) {
  int cur_length = 1;
  int test_length = 1;
  int max_length = 1;
  for (int i = 1; i < strlen(s) && s[i] != '\0'; i++) {
    for (int j = i - 1; j >= i - test_length; j--) {
      if (s[i] != s[j]) {
        cur_length++;
      } else if (j != i - test_length) {
        i = j;
        test_length = 1;
        cur_length = 1;
        break;
      }
    }
    if (cur_length >= test_length) {
      test_length = cur_length;
    }
    if (test_length >= max_length) {
      max_length = test_length;
    }
    cur_length = 1;
  }
  return max_length;
}

int main() {
  char *s1 = "abcabcbb"; // 3
  printf("%d\n", lengthOfLongestSubstring(s1));
  char *s2 = "bbbbb"; // 1
  printf("%d\n", lengthOfLongestSubstring(s2));
  char *s3 = "pwwkew"; // 3
  printf("%d\n", lengthOfLongestSubstring(s3));
  char *s4 = "atmmzuxt"; // 5
  printf("%d\n", lengthOfLongestSubstring(s4));
  char *s5 = "ggububgvfk"; // 6
  printf("%d\n", lengthOfLongestSubstring(s5));
  return 0;
}
