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
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,a[mx][mx],bk[mx][mx],x,y,b,s0,s,flag;
queue<pair<int,int>> q;
char str[mx];

void bfs(int x,int y){
	while(!q.empty()) q.pop();
	q.push({x,y}),bk[x][y]=1;
	while(!q.empty()){
		int cx=q.front().first,cy=q.front().second;
		q.pop(),s++;
		if(a[cx][cy]==2) a[cx][cy]=3;
		for(int i=0;i<4;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if(a[nx][ny]&&!bk[nx][ny]){
				bk[nx][ny]=1;
				q.push({nx,ny});
			}
		}
	}
}
int main(){
	freopen("1606.in","r",stdin);
	//freopen("1606.out","w",stdout);
	n=read(),m=read();
	f(i,1,n){
		scanf("%s",str+1);
		f(j,1,m){
			if(str[j]=='.') a[i][j]=1;
			else if(str[j]=='?') a[i][j]=2;
		}
	}
	f(i,1,n) f(j,1,m){
		if(a[i][j]==1&&!bk[i][j]){
			b++,bfs(i,j),x=i,y=j;
		}
	}
	if(b==1){
		s0=s;
		for(int i=1;i<=n&&!flag;i++){
			for(int j=1;j<=m&&!flag;j++){
				if(a[i][j]==3){
					mem(bk,0),s=a[i][j]=0;
					bfs(x,y);
					if(s==s0-1) flag=1;
					a[i][j]=1;
				}
			}
		}
		if(flag) printf("Ambiguous");
		else{
			f(i,1,n){
				f(j,1,m){
					if(a[i][j]==1) printf(".");
					else printf("#");
				}
				printf("\n");
			}
		}
	}else printf("Impossible");
	return 0;
}