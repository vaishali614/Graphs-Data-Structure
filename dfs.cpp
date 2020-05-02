#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > m;
    public:
        void addEdge(T x, T y, bool bidir){
            m[x].pb(y);
            if(bidir){
                m[y].pb(x);
            }
        }

        void dfs_helper(T src, map<T, bool> &visited){
            // Recursive function to traverse the graph
            cout << src << " ";
            visited[src] = true;
            for(auto it : m[src]){
                if(!visited[it])
                    dfs_helper(it, visited);
            }
        }

        void dfs(T src){
            map<T, bool> visited;
            for(auto it : m){
                visited[it.first] = false;
            }
            dfs_helper(src, visited);
        }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1, true);
    g.addEdge(0, 3, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 4, true);
    g.addEdge(4, 5, true);

    g.dfs(0);
}