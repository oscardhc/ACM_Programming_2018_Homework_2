
//  B.cpp
//  Created on 2018-11-10 18:05

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=25000+233;
int n,a[105],f[mx],ma,ans;

inline void work(){
	n=read(),ans=0;
	f(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	f(i,1,n){
		f(j,1,a[i]) f[j]=0;
		f[0]=1;
		f(j,1,i-1) if(a[j]){
			f(k,a[j],a[i]) if(f[k-a[j]]) f[k]=1;
		}
		if(f[a[i]]) a[i]=0; else ans++;
	}
	printf("%d\n",ans);
}

int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int T=read();while(T--) work();
	return 0;
}

