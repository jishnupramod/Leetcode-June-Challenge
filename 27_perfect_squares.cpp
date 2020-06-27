/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/


class Solution {
private:
    int minSq(int n, vector<int> sq) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int s : sq) {
                if (i >= s) 
                    dp[i] = min(dp[i], dp[i-s] + 1);
            }
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i=1; i*i<=n; ++i) {
            squares.push_back(i*i);
        }
        return minSq(n, squares) - 1;
    }
};