
//  1606.cpp
//  Created on 2018-11-05 18:05

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=55;
const int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
char str[mx];
int n,m,mp[mx][mx],bk[mx][mx],tot,tot2;
queue< pair<int,int> > q;

int bfs(int sx,int sy,int cnt=0){
	mem(bk,0);
	while(!q.empty()) q.pop();
	q.push(make_pair(sx,sy)),bk[sx][sy]=1;
	while(!q.empty()){
		int cx=q.front().first,cy=q.front().second;
		cnt++,q.pop();
		f(k,0,3){
			int nx=cx+dx[k],ny=cy+dy[k];
			if(nx<1||ny<1||nx>n||ny>m) continue;
			if(!mp[nx][ny]) continue;
			if(!bk[nx][ny]){
				bk[nx][ny]=1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return cnt;
}

int main(){
	//freopen("1606.in","r",stdin);
	//freopen("1606.out","w",stdout);
	n=read(),m=read();
	f(i,1,n){
		scanf("%s",str+1);
		f(j,1,m) mp[i][j]=(str[j]=='.'?1:(str[j]=='?'?-1:0));
	}
	f(i,1,n) f(j,1,m) if(mp[i][j]) tot++;
	f(i,1,n) f(j,1,m) if(mp[i][j]==-1) tot2++;
	if(tot2==0){
		f(x,1,n){
			f(y,1,m) printf("%c",mp[x][y]==0?'#':'.');
			printf("\n");
		}
		return 0;
	}else if(tot==1&&tot2==1){
		printf("Ambiguous\n");
		return 0;
	}
	f(i,1,n) f(j,1,m) if(mp[i][j]){
		if(bfs(i,j)==tot){
			f(x,1,n) f(y,1,m){
				if(mp[x][y]==-1){
					mp[x][y]=0;
					int flag=0;
					f(p,1,n) f(q,1,m){
						if(flag) continue;
						if(mp[p][q]){
							flag=1;
							if(bfs(p,q)==tot-1){
								printf("Ambiguous\n");
								return 0;
							}
						}
					}
					mp[x][y]=-1;
				}
			}
			f(x,1,n){
				f(y,1,m) printf("%c",mp[x][y]==0?'#':'.');
				printf("\n");
			}
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}

