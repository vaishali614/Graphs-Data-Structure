#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// without dp : O((n-1)!)

// with dp : O(2^n.n)

ll dp[16][4]; // dp of 2^n x n

ll n = 4;
ll dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

// define mask to mark which cities are visited
ll visited = (1<<n) - 1;

ll tsp(ll mask, ll pos){
    // base case
    if(mask == visited)
        return dist[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    ll ans = INT_MAX;
    // traverse to unvisited cities
    for(ll city = 0; city < n; city++){
        // checking if the city is visited or not : 0011 & 0100 = 0000 i.e city 2 is not visited
        if((mask & (1<<city)) == 0){
            // mask | (1<<city) : 0001 | 0010 = 0011 i.e city 1 added to city 0 (both cities are visited now)
            ll newans = dist[pos][city] + tsp((mask | (1<<city)), city);
            ans = min(ans, newans);
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    for(ll i = 0; i < (1<<n); i++){
        for(ll j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }

    cout << tsp(1, 0) << endl;  // initial mask = 0001, intial position at city 0
    return 0;
}