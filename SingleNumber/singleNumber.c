int singleNumber(int* nums, int numsSize) {
  int result = 0;
  for (int i = 0; i < numsSize; i++) {
    result ^= nums[i];
  }
  result ^= 0;
  return result;
}
