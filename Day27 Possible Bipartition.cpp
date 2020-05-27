/* Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:
	Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
	Output: true
	Explanation: group1 [1,4], group2 [2,3]

Example 2:
	Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
	Output: false
	
Example 3:
	Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
	Output: false

Note:
-> 1 <= N <= 2000
-> 0 <= dislikes.length <= 10000
-> 1 <= dislikes[i][j] <= N
-> dislikes[i][0] < dislikes[i][1]
-> There does not exist i != j for which dislikes[i] == dislikes[j].

/*Concept of graph coloring algorithm*/
/*Used reference of https://www.tutorialspoint.com/possible-bipartition-in-cplusplus
To learn Graph coloring algorithm : https://www.youtube.com/watch?v=052VkKhIaQ4
*/

class Solution {
public:
    set<int> g[2];
    
    bool dfs(int i,vector<int> graph[],int c) {
        if(g[1-c].count(i))
            return false;
        
        g[c].insert(i);
        
        for(int j=0; j<graph[i].size();j++)
            if(!g[1-c].count(graph[i][j]) && !dfs(graph[i][j],graph,c^1))
                return false;
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> graph[N+1];
        
        for(int i=0;i<dislikes.size();i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1;i<=N;i++){
            if(!g[0].count(i) && !g[1].count(i) && !dfs(i,graph,0))
                return false;
        }
        
        return true;
    }
};