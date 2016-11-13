int jump(vector<int>& nums) {
  int dp[nums.size()];
  memset(dp, 0, sizeof(int) * nums.size());

  int currMaxWithMinStep = 0, acturalMax = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (acturalMax < i - 1 + nums[i - 1]) {
      acturalMax = i - 1 + nums[i -1];
    }

    if (currMaxWithMinStep < i) {
      dp[i] = dp[i - 1] + 1;
      currMaxWithMinStep = acturalMax;
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[nums.size() - 1];
}
