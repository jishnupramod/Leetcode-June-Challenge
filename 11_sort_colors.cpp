/*
Given an array with n objects colored red, white or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, w=0, b=0;
        for (int i : nums) {
            if (i == 0)
                ++r;
            else if (i == 1)
                ++w;
            else if (i == 2)
                ++b;
        }
        for (int i=0; i<r; ++i)
            nums[i] = 0;
        for (int i=r; i<r+w; ++i) 
            nums[i] = 1;
        for (int i=r+w; i<nums.size(); ++i)
            nums[i] = 2;
    }
};