/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
	Input: numCourses = 2, prerequisites = [[1,0]]
	Output: true
	Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
	Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
	Output: false
	Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:
-> The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
-> You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

Hint #1 This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

Hint #2 Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.

Hint #3 Topological sort could also be done via BFS.
*/

class Solution {
private:
    vector<vector<int>> graph;
public:
    bool dfs(int c, vector<int>& v) {
        if(v[c] == 1)
            return true;
        if(v[c] == 2)
            return false;
        
        v[c] = 1;
        
        for(int i:graph[c]) {
            if(dfs(i,v))
                return true;
        }
        
        v[c] = 2;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> v = vector<int>(numCourses,0);
        
        for(int i=0;i<numCourses;i++) {
            if(dfs(i,v))
                return false;
        }
        return true;
    }
}; 	