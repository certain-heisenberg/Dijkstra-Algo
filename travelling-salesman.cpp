#include <bits/stdc++.h>
using namespace std;
 
#define kk
//#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
typedef pair<int, int> pi;

int arr[11][11];
int dp[11][1<<11];

int bitmask(int mask, int i, int& n){
	int to_visit=__builtin_popcount(mask);
	if(to_visit==0) return arr[i][0];
	
	if(dp[i][mask]!=-1) return dp[i][mask];
	
	int ans=INT_MAX;
	REP(city, 0, n-1){
		if(mask & (1<<city)){
			ans=min(ans, arr[i][city]+bitmask(mask ^ (1<<city), city, n));
		}
	}
	return dp[i][mask]=ans;
}

void solve(){
	int n;
	cin>>n;
	n++;
	
	REP(i, 0, n-1) REP(j, 0, n-1) if(i!=j) cin>>arr[i][j];
	
	memset(dp, -1, sizeof dp);
		
	int mask=(1<<n)-1;
	
	cout<<bitmask(mask ^ 1, 0, n)<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	cin>>T;
	
	while(T--){
		solve();
	}
}
