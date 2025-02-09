#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;
void preparedadjlist(unordered_map<int,unordered_set<int>>&adjlist,vector<pair<int,int>>&edges){
for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjlist[u].insert(v);
    adjlist[v].insert(u);
}
}

void bfs(unordered_map<int,unordered_set<int>>&adjlist,unordered_map<int,bool> &visited,vector<int>&ans,int node ){
         queue<int>q;
         q.push(node);
         visited[node] = 1;
         while(!q.empty()){
             int frontnode = q.front();
             q.pop();

             ans.push_back(frontnode);


             for(auto i:adjlist[frontnode]){
                 if(!visited[i]){
                     q.push(i);
                     visited[i] = 1;
                 }
             }
         }
}

vector<int>bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int,bool> visited;
    unordered_map<int,unordered_set<int>>adjlist;
    vector<int>ans;

    
    vector<pair<int, int>> edges;
    for (int i = 0; i < adj.size(); i++) {
        int u = adj[i][0];
        int v = adj[i][1];
        edges.push_back({u, v});
    }
    
    preparedadjlist(adjlist, edges);

    // traverse all components of a graph
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}

int main() {
    int n = 7; // Number of nodes (assumed labeled 0 to 6)
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };
    
    vector<int> result = bfsTraversal(n, edges);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}