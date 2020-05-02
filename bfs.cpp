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

        void bfs(T src){
            queue<T> q;
            map<T, bool> visited;

            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                T front = q.front();
                q.pop();
                cout << front << " ";
                for(auto it : m[front]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
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

    g.bfs(0);
}