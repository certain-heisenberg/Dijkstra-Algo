#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

vector<pi> arr[1001];
vector<int> dist(1001, INT_MAX);

struct comp{
    bool operator()(pi &a, pi &b){
        return a.first<b.first;
    }
};

priority_queue<pi, vector<pi>, comp> pq;

void dijkstra(int v, int d, int money){
	dist[v]=d;
	
	if(money<=0) return;
	
	for(pi c: arr[v]){
		int child=c.first;
		int weight=c.second;
		int dist_from_node=dist[v]+weight;
		if(dist_from_node<dist[child]){
			pq.push({dist_from_node, child});
		}
	}
	
	while(!pq.empty()){
		int node=pq.top().second;
		int node_d=pq.top().first;
		pq.pop();
	
		dijkstra(node, node_d, money-node);
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, M;
    cin>>n>>m>>M;
    for(int i=1; i<=m; i++){
        int a, b, weight;
        cin>>a>>b>>weight;
        arr[a].push_back({b,weight});
        arr[b].push_back({a,weight});
    }
    
    dijkstra(1, 0, M-1);
    
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}
/*
6 9 8(M)

1 2 4
1 6 2
2 3 5
2 6 1
3 6 8
6 5 10
5 4 5
5 3 3
3 4 6
 */
