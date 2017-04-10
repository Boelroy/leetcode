/*
 * 简单的用dp来做
 * cuts[i] 表示 以 i 结尾的 最小分割。
 * 所以 当 i, j (i >= j) 位是 回文字符串的话 cut[i] = min(cut[j-1] + 1, cuts[i])
 */

class Solution {
public:
    int minCut(string s) {
        int size = s.length();

        bool pal[size+1][size+1];
        memset(pal, 0, sizeof(pal));

        int cuts[size+1];
        for (int i = 0; i < size; i++) cuts[i] = i;
        

        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 1 || pal[i-1][j+1])) {
                    pal[i][j] = 1;
                    cuts[i] = j > 0 ? min(cuts[j-1] + 1, cuts[i]) : 0;
                }
            }
        }

        return cuts[size-1];
    }
};