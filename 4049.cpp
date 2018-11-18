
//  4049.cpp
//  Created on 2018-11-13 14:12

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e6+233,mod=1e9+7;
int n,pr[mx];
vector<int> v;

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline void sol(int k){
	int a=n,b=k,re=1;ll ans=0;
	while(b){
		int k=a/b;
		ans=ans*pr[b==1?k-1:k]%mod;
		if(re) ans=(ans+pr[b==1?k-1:k]-1+mod)%mod;
		a-=k*b,swap(a,b),re^=1;
	}
	v.push_back((int)((ans+ans+1)%mod));
}

int main(){
	freopen("4049.in","r",stdin);
	//freopen("4049.out","w",stdout);
	n=read();
	pr[0]=1;
	f(i,1,n){
		pr[i]=pr[i-1]+pr[i-1];
		if(pr[i]>=mod) pr[i]-=mod;
	}
	f(i,1,n) if(gcd(i,n)==1) sol(i);
	sort(v.begin(),v.end());
	for(auto i:v) printf("%d\n",i);
	return 0;
}

