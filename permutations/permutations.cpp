vector<vector<int >> permute(vector<int>& nums) {
  vector<vector<int >> result;
  permuteImpl(nums, vector<int>(), result, 0);
  return result;
}

void permuteImpl(vector<int> nums, vector<int> cur, vector<vector<int>> &result, int start) {
  if (start == nums.size()) {
    result.push_back(cur);
    return;
  }
  for (int i = start; i < nums.size(); i++) {
    cur.push_back(cur);
    swap(nums[start], nums[i]);
    permuteImpl(nums, cur, result, start + 1);
    swap(nums[start], nums[i]);
    cur.pop_back();
  }
}
