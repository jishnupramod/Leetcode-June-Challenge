/*
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> q(people.size(), vector<int>(2, -1));
        sort(people.begin(), people.end(), [&](vector<int> a, vector<int> b) {
            return (a[0] < b[0] or (a[0] == b[0] and a[1] < b[1]));
        });
        for (vector<int> man : people) {
            int i=0, pos=0;
            while (i < q.size()) {
                if (pos == man[1] and q[i][0] == -1)
                    break;
                if (q[i][0] == -1 or q[i][0] >= man[0])
                    ++pos;
                ++i;
            }
            q[i] = man;
        }
        return q;
    }
};
 