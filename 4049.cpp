
//  4049.cpp
//  Created on 2018-11-13 14:12

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

int n,f[1000005];
vector<int> v[1000000];

int main(){
	//freopen("4049.in","r",stdin);
	//freopen("4049.out","w",stdout);
	n=read();
	f[1]=1;f(i,2,1000000) f[i]=(i&1)?f[i>>1]+f[(i+1)>>1]:f[i>>1],(i&1)?(v[f[i]].push_back(i),0):0;
	f(i,1,30){
		printf("%4d: ",i);
		for(auto j:v[i]) printf("%d ",j);
		printf("\n");
	}
	f(i,1,100) printf("%d ",f[i]);
	printf("\n");
	return 0;
}

