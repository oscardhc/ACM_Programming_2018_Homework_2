//#pragma GCC optimize ("O3")

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
vector<pair<pair<short,short>,int>> v[mx*mx];

inline short dis(pair<short,short> a,pair<short,short> b){
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
		int s1=v[i].size(),s2=v[i-1].size();
		f(j,0,s1-1){
			f(k,0,s2-1){
				int tmp=v[i-1][k].second+dis(v[i][j].first,v[i-1][k].first);
				if(v[i][j].second>tmp) v[i][j].second=tmp;
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

