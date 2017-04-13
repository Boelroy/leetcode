class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();

        int sum = 0, start = 0;
        for (int i = 0; i < N * 2 - 1; i++) {
            if (i - start == N) break;

            sum = sum + gas[i % N] - cost[i % N];

            if (sum < 0) { 
                start = i+1;
                sum = 0;
            }
        }
        return start + N < N * 2 ? start : -1;
    }
};