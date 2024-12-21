class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int currentNode )
    {
        visited[currentNode] = true;
        for(int i = 0 ; i < isConnected.size() ; i++)
        {
            if(isConnected[currentNode][i] == 1 && !visited[i])
            {
                DFS(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size() , false);
        int provinceCount = 0;
        for(int i = 0 ; i < isConnected.size() ; i++)
        {
            if(!visited[i])
            {
                ++provinceCount;
                DFS(isConnected, visited, i);
            }
        }
        return provinceCount;
    }
};