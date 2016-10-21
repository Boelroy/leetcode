#include "stdlib.h"
#include "stdio.h"

int* twoSum(int* nums, int numsSize, int target);

int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
  int nums[] = {4, 4, 0, 3};
  int* result = twoSum(nums, 4, 3);
  printf("%d %d\n", result[0], result[1]);
  return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
  int* result = (int*)malloc(sizeof(int) * 2);
  qsort(nums, numsSize, sizeof(int), cmp);
  int low = 0, high = numsSize - 1;
  while(low < high) {
    int sum = nums[low] + nums[high];
    if (sum == target) {
      result[0] = nums[low];
      result[1] = nums[high];
      break;
    } else if (sum > target){
      high--;
    } else {
      low++;
    }
  }
  return result;
}
