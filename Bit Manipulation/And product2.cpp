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


int main()
{
	//problem lik:  https://www.hackerrank.com/challenges/and-product/problem
	int t;
	cin>>t;
	while(t--)
	{
		llu a,b,i,sum=0,f=1;
		cin>>a>>b;
		llu d=b-a;
		for(i=0;i<32;i++)
		{
			if(d>(f<<i))continue;
			else
				if(a&(f<<i)  &&  b&(f<<i))sum+=(f<<i);
		}
		cout<<sum<<nl;
	}
	return 0;
}
