/* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
	Input: "tree"

	Output: "eert"
	Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
	Input: "cccaaa"
	Output: "cccaaa"
	Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
	Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
	Input: "Aabb"
	Output: "bbAa"
	Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
	Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    static bool compare(pair<char,int> a, pair<char,int> b) {
        return a.second>=b.second;
    }
    
    string frequencySort(string s) {
        map<char,int> m;
        for(auto i:s) {
            m[i]++;
        }
        
        vector<pair<char,int>> v;
        for(auto i:m)
            v.push_back({i.first,i.second});
        
        sort(v.begin(),v.end(),compare);
        
        s="";
        for(int i=0;i<v.size();i++)
        {
            // cout<<v[i].first<<"\t"<<v[i].second<<endl;
            int k=v[i].second;
            while(k--)
                s+=v[i].first;
        }
        return s;
    }
};