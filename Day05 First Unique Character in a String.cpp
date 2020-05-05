/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

	s = "leetcode"
	return 0.

	s = "loveleetcode",
	return 2.

Note:
1) You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        set<char> st;
        for(int i=0;i<s.length();i++) {
            int first = s.find(s[i]);
            int last = s.rfind(s[i]);
            if(first == last)
                return i;
        }
        return -1;
    }
};