#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Graph{
    ll V;
    list<ll> *l;
    public:
        Graph(ll V){
            this->V = V;
            l = new ll[V];
        }

        void addEdge(int x, int y){
            l[x].pb(y);
            l[y].pb(x);
        }

        void printGraph(){
            for(ll i = 0; i < V; i++){
                cout << "Vertex " << i << " --> ";
                for(auto it : l[i]){
                    cout << it << " , ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();
}