int trap(int* height, int size) {
  int left = 0, right = size - 1;
  int leftMax = 0, rightMax = 0;
  int trappingWater = 0;
  while(left < right) {
    if (height[left] <= height[right]) {
      if (height[left] >= leftMax) leftMax = height[left];
      if (leftMax - height[left] >= 0) trappingWater += (leftMax - height[left]);
      left++;
    } else {
      if (height[right] >= rightMax) rightMax = height[right];
      if (rightMax - height[right] >= 0) trappingWater += (rightMax - height[right]);
      right++;
    }
  }
  return trappingWater;
}
