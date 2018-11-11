#pragma GCC optimize ("O3")

//  4166.cpp
//  Created on 2018-11-09 15:31

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=305,inf=0x3f3f3f3f;
int n,m,p;
vector<pair<pair<int,int>,int>> v[mx*mx];

inline int dis(pair<int,int> a,pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

inline void work(){
	n=read(),m=read(),p=read();
	f(i,0,n-1) f(j,0,m-1){
		int cur=read();
		if(cur==1) v[cur].push_back({{i,j},i+j});
		else v[cur].push_back({{i,j},inf});
	}
	f(i,2,p){
		for(auto j=v[i].begin();j!=v[i].end();j++){
			for(auto k=v[i-1].begin();k!=v[i-1].end();k++){
				int tmp=k->second+dis(j->first,k->first);
				if(j->second>tmp) j->second=tmp;
			}
		}
	}
	printf("%d\n",v[p][0].second);
	f(i,1,p) v[i].clear();
}

int main(){
	freopen("4166.in","r",stdin);
	//freopen("4166.out","w",stdout);
	int T=read();while(T--) work();
	return 0;
}

