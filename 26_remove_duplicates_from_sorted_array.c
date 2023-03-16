#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) { // O(n^2)
  int i = 0;
  while (i + 1 < numsSize) {
    if (nums[i] == nums[i + 1]) {
      for (int j = i; j < numsSize - 1; j++) {
        nums[j] = nums[j + 1];
      }
      numsSize--;
    } else {
      i++;
    }
  }
  return numsSize;
}

int main() {
  int nums1[3] = {1, 1, 2};
  int nums2[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int expected1[2] = {1, 2};
  int expected2[5] = {0, 1, 2, 3, 4};
  int k = removeDuplicates(nums1, 3);
  for (int i = 0; i < k; i++) {
    printf("%d ", nums1[i]);
  }
  printf("\n");
  k = removeDuplicates(nums2, 10);
  for (int i = 0; i < k; i++) {
    printf("%d ", nums2[i]);
  }
  printf("\n");
  return 0;
}
