#include<bits/stdc++.h>
using  namespace  std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'

typedef long long int ll;
typedef unsigned long long int  llu;
int in[101],low[101],vis[101];
vector<int>v[101];
int timer;
void dfs(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]=timer++;
	for(int child: v[node])
	{
		if(child==par)continue;
		if(vis[child]==1)
		{
			low[node]=min(low[node],in[child]);
		}
		else{
			dfs(child,node);
			if(low[child]>in[node])
			{
				cout<<node<<" -> "<<child<<"  is a bridge"<<nl;
			}
			low[node]=min(low[node],low[child]);
		}
	}
}
int main()
{
	int n,m,x,y,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
}
