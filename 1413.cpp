
//  1413.cpp
//  Created on 2018-11-11 15:00

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=505;
int n,m,ok[mx],c[mx],c1,c2,f[mx],ans=0x3f3f3f3f;
int e[mx][mx];
vector<pair<int,int>> v;

inline int pre(int cu){
	ok[cu]=1;if(c[cu]==1) c1++; else c2++;
	f(i,1,n) if(i!=cu&&e[cu][i]==0){
		if(!c[i]) c[i]=3-c[cu];
		else if(c[i]==c[cu]) return -1;
		if(ok[i]) continue;
		if(pre(i)==-1) return -1;
	}
	return 0;
}

int main(){
	//freopen("1413.in","r",stdin);
	//freopen("1413.out","w",stdout);
	n=read(),m=read();
	f(i,1,m){
		int a=read(),b=read();
		e[a][b]=e[b][a]=1;
	}
	if(n<=10){
		f(s,0,(1<<n)-1){
			vector<int> v1,v2;
			f(i,1,n){
				if(s&(1<<(i-1))) v1.push_back(i);
				else v2.push_back(i);
			}
			int flag=1;
			for(int i:v1){
				for(int j:v1){
					if(i!=j&&e[i][j]==0) flag=0;
				}
			}
			for(int i:v2){
				for(int j:v2){
					if(i!=j&&e[i][j]==0) flag=0;
				}
			}
			if(flag){
				ans=min(ans,abs((int)v1.size()-(int)v2.size()));
			}
		}
		if(ans==0x3f3f3f3f) printf("No Answer\n"); else printf("%d\n",ans);
		return 0;
	}
	f(i,1,n){
		if(!ok[i]){
			c1=c2=0,c[i]=1;
			if(pre(i)==-1) return printf("No Answer\n"),0;
			v.push_back({c1,c2});
		}
	}
	f[0]=1;
	for(auto p:v){
		fd(i,n,0){
			if(i-p.first>=0&&f[i-p.first]) f[i]=1;
			if(i-p.second>=0&&f[i-p.second]) f[i]=1;
		}
	}
	f(i,0,n) if(f[i]) ans=min(ans,abs(i+i-n));
	printf("%d\n",ans);
	return 0;
}

