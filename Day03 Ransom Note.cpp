/* Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters. */

/* Examples: 
	canConstruct("a", "b") -> false
	canConstruct("aa", "ab") -> false
	canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int flag = true;
        for(int i=0;i<ransomNote.length();i++) {
            if(count(ransomNote.begin(),ransomNote.end(),ransomNote[i]) <= count(magazine.begin(),magazine.end(),ransomNote[i]))
                flag = true;
            else {
                flag = false;
                break;
            }
        }
        
        if(flag)
            return true;
        else
            return false;
    }
};