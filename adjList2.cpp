#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Graph{
    unordered_map<string, list<pair<string, ll> > > m;
    public:
        void addEdge(string x, string y, bool bidir, ll wt){
            m[x].pb(make_pair(y, wt));
            if(bidir){
                m[y].pb(make_pair(x, wt));
            }
        }

        void printGraph(){
            for(auto itr : m){
                cout << "Vertex " << itr.first << " --> ";
                for(auto it : itr.second){
                    cout << it.first << ": " << it.second << ", ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 30);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printGraph();
}