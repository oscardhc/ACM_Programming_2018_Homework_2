
//  4165.cpp
//  Created on 2018-11-09 14:11

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=131072,inf=0x3f3f3f3f;
int n,a[mx],f[mx],t[mx<<1],p[mx<<1];ll ans;

int qry(int l,int r,int m=inf,int mp=0){
	for(l=l+mx-1,r=r+mx+1;l^r^1;l>>=1,r>>=1){
		assert(l);
		assert(r);
		if(l&1^1) t[l^1]<m?(m=t[l^1],mp=p[l^1]):0;
		if(r&1) t[r^1]<m?(m=t[r^1],mp=p[r^1]):0;
	}
	return mp;
}
void sol(int l,int r,int bs){
	if(l>r) return;
	if(l==r){ans+=t[l+mx]-bs;return;}
	int po=qry(l,r);
	//printf("sol %d %d   %d %d\n",l,r,po,a[po+mx]);
	ans+=t[po+mx]-bs;
	sol(l,po-1,t[po+mx]);
	sol(po+1,r,t[po+mx]);
}

int main(){
	//freopen("4165.in","r",stdin);
	//freopen("4165.out","w",stdout);
	n=read();
	f(i,1,n) a[i]=read();
	f(i,1,mx+mx-1) t[i]=inf;
	f(i,1,n) a[i]-=read(),f[i]=a[i]>0,t[i+mx]=abs(a[i]),p[i+mx]=i;
	fd(i,mx-1,1) t[i<<1]<t[i<<1|1]?(t[i]=t[i<<1],p[i]=p[i<<1]):(t[i]=t[i<<1|1],p[i]=p[i<<1|1]);
	f(i,1,n){
		int cur=i;
		while(cur<n&&f[cur+1]==f[i]) cur++;
		sol(i,cur,0);
		i=cur;
	}
	cout<<ans<<endl;
	return 0;
}

