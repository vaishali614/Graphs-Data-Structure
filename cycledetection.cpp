#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// cycle - if there is more than one way to visit a node

class Graph{
    ll V;
    list<ll>* l;
    public:
        Graph(ll V){
            this->V = V;
            l = new list<ll>[V];
        }
        void addEdge(ll x, ll y){
            l[x].pb(y);
            l[y].pb(x);
        }

        bool cycle_helper(ll node, bool* visited, ll parent){
            visited[node] = true;
            for(auto it : l[node]){
                if(!visited[it]){
                    //Recursively visit the neighbour
                    bool cycle = cycle_helper(it, visited, node);
                    if(cycle)
                        return true;
                } else if(it != parent){
                    return true;
                }
            }
            return false;
        }

        bool check_cycle(){
            bool* visited = new bool[V];
            for(ll i = 0; i < V; i++){
                visited[i] = false;
            }
            return cycle_helper(0, visited, -1);
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    bool isCycle = g.check_cycle();
    if(isCycle)
        cout << "YES\n";
    else
        cout << "NO\n";
}