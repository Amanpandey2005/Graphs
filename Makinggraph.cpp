#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
public:
        unordered_map<int,list<int>>adj;
        void addedge(int u, int v, bool direction){
            adj[u].push_back(v);
            if (direction == 0){
                adj[v].push_back(u);
            }
        }
        void printedge(){
            for(auto i : adj){
                cout << i.first << "->" ;
                for(auto j : i.second){
                    cout << j << ",";
                }
                cout << endl;
            }
        }

};

int main(){
    int m,n;
        cout << "Enter the no of nodes" << endl;
        cin >> n;
        cout << "Enter the no of connecting lines"<< endl;
        cin >> m;
    graph g;
    for(int i = 0; i< n ; i++){
        int u, v;
        cin >> u>> v;
        g.addedge(u,v,0);
    }
    g.printedge();

    return 0;
}