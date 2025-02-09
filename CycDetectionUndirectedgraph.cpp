#include<unordered_map>
#include<queue>
#include<list>
#include<queue>
#include<string>
using namespace std;
bool iscyclicBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjlist){
            unordered_map<int,int>parent;
            parent[src] = -1;
            visited[src] = 1;
            queue<int>q;
            q.push(src);

            while(!q.empty()){
                int front = q.front();
                  q.pop();

                for(auto neighbour:adjlist[front]){
                    if(visited[neighbour] == true && neighbour != parent[front]){
                        return true;
                    }
                    else if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = front;
                    }
                }
            }
     return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adjlist;
    for(int i = 0; i< m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    for(int i = 0; i<n ; i++){
        if(!visited[i]){
            bool ans = iscyclicBFS(i,visited,adjlist);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
   
}