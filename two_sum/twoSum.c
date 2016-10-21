#include "stdlib.h"
#include "stdio.h"

int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char const *argv[])
{
  int nums[] = {0, 4, 3, 0};
  int* result = twoSum(nums, 4, 0);
  printf("%d %d\n", result[0], result[1]);
  return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
  int* result = (int*)malloc(sizeof(int) * 2);

  for (int i = 0; i < numsSize; ++i)
  {
    for (int j = i + 1; j < numsSize; ++j)
    {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
      }
    }
  }
  return result;
}
