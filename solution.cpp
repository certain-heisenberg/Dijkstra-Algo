#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

struct comp{
    bool operator()(ppi &a, ppi &b){
        return a.first<b.first;
    }
};

vector<pi> arr[101];
int Min[101][101];
int S[101];
int vis[101][101];

int n, m, M;

void dijkstra(){
	priority_queue<ppi, vector<ppi>, comp> pq;
	pq.push({0, {1, M}});
	
	while(!pq.empty()){
		pi temp=pq.top().second;
		pq.pop();
		int k=temp.first;
		int l=temp.second;
		
		if(vis[k][l]==0){
			vis[k][l]=1;		
			for(pi c: arr[k]){
				int p=c.first;
				int weight=c.second;
				
				if(l-S[p]>=0 && Min[p][l-S[p]]>Min[k][l]+weight){
					Min[p][l-S[p]]=Min[k][l]+weight;
					pq.push({Min[p][l-S[p]], {p, l-S[p]}});
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>n>>m>>M;
    for(int i=1; i<=m; i++){
        int a, b, weight;
        cin>>a>>b>>weight;
        arr[a].push_back({b,weight});
        arr[b].push_back({a,weight});
    }
    
    for(int i=1; i<=n; i++){
		cin>>S[i];
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=M; j++){
			Min[i][j]=INT_MAX;
		}
	}
    
    Min[1][M]=0;
    dijkstra();
    
    int res=-1;
    for(int j=0; j<=M; j++){
		if(Min[n][j]<INT_MAX) res=Min[n][j];
	}
	
	cout<<res<<endl;
}

/*
6 9 16

1 2 4
1 6 2
2 3 5
2 6 1
3 6 8
6 5 10
5 4 5
5 3 3
3 4 6

1 2 3 4 5 6
 */
