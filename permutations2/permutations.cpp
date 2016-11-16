vector<vector<int >> permute(vector<int>& nums) {
  vector<vector<int >> result;
  permuteImpl(nums, result, 0);
  return result;
}

void permuteImpl(vector<int> nums, vector<vector<int>> &result, int start) {
  if (start == nums.size()) {
    result.push_back(nums);
    return;
  }
  for (int i = start; i < nums.size(); i++) {
    int iter = start;
    while(iter < i) {
      if (nums[iter] == nums[i]) break;
      iter++;
    }
    if (iter < i) continue;
    swap(nums[start], nums[i]);
    permuteImpl(nums, result, start + 1);
    swap(nums[start], nums[i]);
  }
}
