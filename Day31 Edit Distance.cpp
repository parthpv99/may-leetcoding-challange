/* Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
	
Example 1:
	Input: word1 = "horse", word2 = "ros"
	Output: 3
	Explanation: horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 2:
	Input: word1 = "intention", word2 = "execution"
	Output: 5
	Explanation: intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int a[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                a[i][j] = 0;
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(!i)
                    a[i][j] = j;
                else if(!j)
                    a[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    a[i][j] = a[i-1][j-1];
                else
                    a[i][j] = 1 + min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1]);
            }
        }
                
        return a[n][m];
    }
};