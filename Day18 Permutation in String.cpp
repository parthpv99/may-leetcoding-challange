/* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
	Input: s1 = "ab" s2 = "eidbaooo"
	Output: True
	Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
	Input:s1= "ab" s2 = "eidboaoo"
	Output: False
 

Note:
-> The input strings only contain lower case letters.
-> The length of both given strings is in range [1, 10,000].

Hint #1  
Obviously, brute force will result in TLE. Think of something else.

Hint #2  
How will you check whether one string is a permutation of another string?

Hint #3  
One way is to sort the string and then compare. But, Is there a better way?

Hint #4  
If one string is a permutation of another string then they must one common metric. What is that?

Hint #5  
Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?

Hint #6  
What about hash table? An array of size 26?
*/

/*It can be solved same as previous day's (Day 17's) question.*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int flag;
        if(s2.length()<s1.length())
            return false;
        
        vector<int> m(26,0),n(26,0);
        for(int i=0;i<s1.length();i++) {
            m[s1[i]-'a']++;
            n[s2[i]-'a']++;
        }
        
        if(m==n)
            return true;
        int len = s1.length();
        
        for(int i=len;i<s2.length();i++) {
            n[s2[i]-'a']++;
            n[s2[i-len]-'a']--;
            if(m==n)
                return true;
        }
        
        return false;
    }
};