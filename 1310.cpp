#include <bits/stdc++.h>
using namespace std;

const int mx=2e5+233;
int n,m,f[mx],bk[mx],id[mx],l[mx],idtt;
struct E{
	int s, t, v, id, ans;
}e[mx];
bool cmp1 (const E x, const E y) {return x.v < y.v;}
bool cmp2 (const E x, const E y) {return x.id < y.id;}
vector<int> tp;
vector<pair<int,int>> v[mx];

inline int gtf (int x) {return f[x] == x ? x : f[x] = gtf(f[x]);}

void dfs(int cu,int fa){
	id[cu]=l[cu]=++idtt;
	for(auto j:v[cu]){
		// printf("....%d %d    %d %d %d\n",cu,j,e[j].t,id[e[j].t],l[e[j].t]);
		if(!id[j.first]){
			dfs(j.first,j.second);
			l[cu]=min(l[cu],l[j.first]);
			if(l[j.first]>id[cu]) e[j.second].ans=1;
		}else if(j.second^fa){
			l[cu]=min(l[cu],id[j.first]);
		}
	}
}
void dfs2(int cu,int fa){
	bk[cu]=1,f[cu]=fa;
	for(auto j:v[cu]){
		if(!bk[j.first]) dfs2(j.first,fa);
	}
}

int main(){
	freopen("1310.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].v),e[i].id=i;
	sort(e+1,e+1+m,cmp1);
	for(int i=1,cu;i<=m;i++){
		cu=i;while(cu<m&&e[cu+1].v==e[i].v) cu++;
		for(int j=i;j<=cu;j++){
			int s=gtf(e[j].s),t=gtf(e[j].t);
			if(s==t){
				e[j].ans=2;
				continue;
			}
			v[s].push_back({t,j});
			v[t].push_back({s,j});
			if(!bk[s]) tp.push_back(s),bk[s]=1;
			if(!bk[t]) tp.push_back(t),bk[t]=1;
		}
		for(auto j:tp) bk[j]=0;
		for(auto j:tp) if(!id[j]) idtt=0,dfs(j,0);
		for(auto j:tp) if(!bk[j]) dfs2(j,j);
		for(auto j:tp) id[j]=0,bk[j]=0,v[j].clear();
		tp.clear();
		i=cu;
	}
	sort(e+1,e+1+m,cmp2);
	for(int i=1;i<=m;i++) printf("%d\n",2-e[i].ans);
	return 0;
}