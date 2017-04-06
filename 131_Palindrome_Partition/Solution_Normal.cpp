/*
 * 这道题其实就是一个简单的搜索 对于每个位置 判断 这个位置 和 之后的位置是不是一个回文字符串
 * 用 dfs 应该就能写出来
 * 当然简单的dfs中有许多重复的搜索
 * 比如在判断 2-6 的位置中 其实我们就能得到 3-5 位置是回文字符串 所以还能优化
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> iter;
        vector<vector<string>> result;
        dfs(0, s, iter, result);
        return result;
    }

    void dfs(int start, string& s, vector<string> iter, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(iter);
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(start, i, s)) {
                iter.push_back(s.substr(start, i - start + 1));
                dfs(i+1, s, iter, result);
                iter.pop_back();
            }
        }
    }

    bool isPalindrome(int start, int end, string s) {
        while(start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};