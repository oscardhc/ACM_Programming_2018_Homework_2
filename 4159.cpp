#include <bits/stdc++.h>
using namespace std;
 
const int mx=1e5+233;
 
int n,m,rt,fl[mx],hh[mx];
 
struct E{int t,nx;}e[mx<<1];
int tot,fir[mx];
inline void ade(int s,int t){
	e[++tot]=E{t,fir[s]},fir[s]=tot;
	e[++tot]=E{s,fir[t]},fir[t]=tot;
}
 
int f[mx][20],d[mx];
inline void dfs(int cu,int fa){
	hh[cu]=f[cu][0]=fa,d[cu]=d[fa]+1;
	for(int i=1;i<20;i++) f[cu][i]=f[f[cu][i-1]][i-1];
	for(int i=fir[cu];i;i=e[i].nx){
		if(e[i].t^fa){
			dfs(e[i].t,cu);
		}
	}
}
 
inline int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(f[x][i]&&d[f[x][i]]>=d[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
 
int main(){
	freopen("4159.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		if(!a) rt=i;
		else ade(a,i);
	}
	dfs(rt,0);
	scanf("%d",&m);
	for(int T=1;T<=m;T++){
		int ty;scanf("%d",&ty);
		if(ty==1){
			int x;scanf("%d",&x);
			fl[x]=T;
		}else{
			int a,b,k,y;scanf("%d%d%d%d",&a,&b,&k,&y);
			int _a=a;
			int l=lca(a,b);
			vector<int> va,vb;
			va.clear(),vb.clear();
			while(a^l){
				a=f[a][0];
				if(fl[a]<=y) va.push_back(a);
			}
			while(b^l){
				b=f[b][0];
				if(fl[b]<=y) vb.push_back(b);
			}
			if(_a==l&&fl[l]<=y) vb.pop_back();
			else if(fl[l]<=y) va.pop_back();
			reverse(vb.begin(),vb.end());
//			for(int i=0;i<va.size();i++) printf("%d ",va[i]);
//			for(int i=0;i<vb.size();i++) printf("%d ",vb[i]);
//			printf("\n");
			if(k>va.size()+vb.size()) printf("-1\n");
			else if(k<=va.size()) printf("%d\n",va[k-1]);
			else printf("%d\n",vb[k-va.size()-1]);
		}
	}
	return 0;
}
