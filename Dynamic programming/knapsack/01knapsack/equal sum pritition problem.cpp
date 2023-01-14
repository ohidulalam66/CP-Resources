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

bool subproblem(int ar[],int n,int sum)
{
	bool sub[n+1][sum+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			if(i==0)sub[i][j]=false;
			if(j==0)sub[i][j]=true;
			if(ar[i-1]<=j)
			{
				sub[i][j]=sub[i-1][j] || sub[i-1][j-ar[i-1]];
			}
			else sub[i][j]=sub[i-1][j];
		}
	}
	return sub[n][sum];
}

int main()
{
	faster;
	int n;
	cin>>n;
	int i,ar[n+1],sum=0;
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
		sum+=ar[i];
	}
	if(sum%2==1)cout<<"Not possible"<<nl;
	else{
		bool z=subproblem(ar,n,sum/2);
		if(z==true)cout<<"possible"<<nl;
		else cout<<"Not possible"<<nl;
	}
	return 0;
}
