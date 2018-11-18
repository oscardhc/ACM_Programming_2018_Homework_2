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

const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int mp[mx][mx],d[mx][mx],dd[mx][mx];
vector<pair<int,pair<int,int>>> vc;
queue<pair<int,int>> q;
inline void work1(){
	mem(d,0);
	f(i,0,n-1) f(j,0,m-1) mp[i][j]=read();
	vc.push_back({1,{0,0}});
	f(kk,1,p){
		mem(dd,0);
		f(i,0,n-1) f(j,0,m-1) if(mp[i][j]==kk-1) vc.push_back({d[i][j],{i,j}});
		sort(vc.begin(),vc.end());
		int cup=0,cud=vc[0].first;
		q.push(vc[0].second);
		dd[vc[0].second.first][vc[0].second.second]=vc[0].first;
		while(cup+1<vc.size()&&vc[cup+1].first<=cud){
			cup++;
			dd[vc[cup].second.first][vc[cup].second.second]=vc[cup].first;
			q.push(vc[cup].second);
		}
		while(!q.empty()){
			int cux=q.front().first,cuy=q.front().second;
			q.pop();
			if(mp[cux][cuy]==kk) d[cux][cuy]=dd[cux][cuy];
			cud=dd[cux][cuy];
			while(cup+1<vc.size()&&vc[cup+1].first<=cud){
				cup++;
				dd[vc[cup].second.first][vc[cup].second.second]=vc[cup].first;
				q.push(vc[cup].second);
			}
			f(k,0,3){
				int nx=cux+dx[k],ny=cuy+dy[k];
				if(nx<0||ny<0||nx>=n||ny>=m) continue;
				if(!dd[nx][ny]){
					dd[nx][ny]=cud+1;
					q.push({nx,ny});
				}
			}
		}
		vc.clear();
	}
	f(i,0,n-1) f(j,0,m-1) if(mp[i][j]==p) printf("%d\n",d[i][j]-1);
}

int main(){
	freopen("4166.in","r",stdin);
	//freopen("4166.out","w",stdout);
	int T=read();while(T--){
		n=read(),m=read(),p=read();
		if(n*m*p<500000) work1();
		else work();
	}
	return 0;
}

