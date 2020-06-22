/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/


// Using extra memory - unordered_map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) mp[i]++;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            if (it->second == 1) return it->first;
        }
        return -1;
    }
};