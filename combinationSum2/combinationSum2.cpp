#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector< vector<int> > combinationSum2(vector<int> &num, int target) {
      vector< vector<int> > result;
      sort(num.begin(), num.end());
      combinationSumInternal(num, 0, num.size(), target, vector<int>(), result);
      return result;
    }

    void combinationSumInternal(vector<int> &num, int start, int end, int target,
        vector<int> cur_vec, vector< vector<int> > & result) {
      if (target == 0) {
        result.push_back(cur_vec);
      }
      for (int i = start; i < end && target - num[i] >= 0; i++) {
        cur_vec.push_back(num[i]);
        combinationSumInternal(num, i+1, end, target-num[i], cur_vec, result);
        cur_vec.pop_back();
      }
    }
};

