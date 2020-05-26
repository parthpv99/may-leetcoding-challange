/* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
	Input: [0,1]
	Output: 2
	Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
	Input: [0,1,0]
	Output: 2
	Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int answer = 0;
        int sum = 0;
        map <int, int> m;
        m[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 1) ? 1: -1;
            
            if(m.count(sum))
                answer = max(answer, i - m[sum]);
            else 
                m[sum] = i;
        }
        
        return answer;
    }
};