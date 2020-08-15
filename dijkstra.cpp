#include <bits/stdc++.h>
typedef pair<int,int> pi;
using namespace std;

vector<pi> arr[1001];
vector<int> dist(1001, INT_MAX);

struct comp{
    bool operator()(pi &a, pi &b){
        return a.first<b.first;
    }
};

void dijkstra(int v, int d){
    priority_queue<pi, vector<pi>, comp> pq;
    pq.push({d, v});
    
    while(!pq.empty()){
        int node=pq.top().second;
        int node_d=pq.top().first;
        dist[node]=node_d;
        pq.pop();
        
        for(pi c: arr[node]){
            int child=c.first;
            int weight=c.second;
            int dist_from_node=dist[node]+weight;
            if(dist_from_node<dist[child]){
                pq.push({dist_from_node, child});
            }
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a, b, weight;
        cin>>a>>b>>weight;
        arr[a].push_back({b,weight});
        // #IMPORTANT: If the graph is directed then below line will not be written.
        // Only upper line will be written to show [a->b] a is reachable to b but b is not reachable to a.
        arr[b].push_back({a,weight});
    }
    dijkstra(1, 0);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}
