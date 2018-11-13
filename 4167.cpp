
//  4167.cpp
//  Created on 2018-11-13 14:01

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e3+5;
int n,f[mx],tot,ans;
pair<int,pair<int,int>> e[mx*mx];
inline int gtf(int cu){return f[cu]==cu?cu:f[cu]=gtf(f[cu]);}
int main(){
	//freopen("4167.in","r",stdin);
	//freopen("4167.out","w",stdout);
	n=read();f(i,1,n) f(j,i,n) e[++tot]={read(),{i-1,j}};
	sort(e+1,e+1+tot);
	f(i,1,n) f[i]=i;
	f(i,1,tot){
		int f1=gtf(e[i].second.first),f2=gtf(e[i].second.second);
		if(f1^f2) f[f1]=f2,ans+=e[i].first;
	}
	cout<<ans<<endl;
	return 0;
}

