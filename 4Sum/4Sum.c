#include "stdio.h"
#include "stdlib.h"

int twoSum(int* nums, int numsSize, int target,int* num1, int* num2) {
  int low = 0, high = numsSize;
  while(low < high) {
    int sum = nums[low] + nums[high];
    if (sum == target) {
      *num1 = nums[low];
      *num2 = nums[high];
      return 1;
    } else if (sum > target) {
      high--;
    } else {
      low++;
    }
  }
  return 0;
}
int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
  int (**map1) = (int**)malloc(sizeof(int) * numsSize * 4);
  int (*map)[4] = map1;
  *returnSize = 0;
  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize - 1; ++j) {
      int other = target - nums[i] - nums[j];
      int low = j + 1, high = numsSize - 1;
      while(low < high) {
        int sum = nums[low] + nums[high];
        if (sum == other) {
          map[*returnSize][0] = nums[i];
          map[*returnSize][1] = nums[j];
          map[*returnSize][2] = nums[low];
          map[*returnSize][3] = nums[high];
          *returnSize = *returnSize + 1;
          while(map[*returnSize - 1][3] == nums[high] && high > low) high--;
          while (map[*returnSize - 1][2] == nums[low] && high > low) low++;
        } else if (sum > other) {
          high--;
        } else {
          low++;
        }
      }
      while(nums[j] == nums[j+1] && j < numsSize - 1) { j++; }
    }
    while(nums[i + 1] == nums[i] && i < numsSize - 1) { i++; }
  }

  for(int i = 0; i < *returnSize; i++) {
    printf("%d %d %d %d\n", map[i][0],map[i][1],map[i][2],map[i][3]);
  }
  return map1;
}

int main(int argc, char const *argv[])
{
  int a;
  int arr[] = {-1,0,-5,-2,-2,-4,0,1,-2};
  fourSum(arr, 9, -9, &a);
  return 0;
}


