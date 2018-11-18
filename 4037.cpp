#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double maxv[400005];
int cntv[400005];
double max(double a,double b)
{
	if(a>b) return a;
	return b;
}
int count(double M,int o,int left,int right)
{
	int mid=(left+right)/2;
	if(left==right) return M<maxv[o];
	if(M>=maxv[o*2]) return count(M,o*2+1,mid+1,right);
	return cntv[o]-cntv[o*2]+count(M,o*2,left,mid);//巧妙 
}
void xg(double p,int x,int o,int left,int right)
{
	int mid=(left+right)/2;
	if(left==right)
	{
		cntv[o]=1;
		maxv[o]=p;
		return;
	}
	if(x<=mid) xg(p,x,o*2,left,mid);
	if(x>mid) xg(p,x,o*2+1,mid+1,right);
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
	cntv[o]=cntv[o*2]+count(maxv[o*2],o*2+1,mid+1,right);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		memset(maxv,0,sizeof maxv);
		memset(cntv,0,sizeof cntv);
		double x,y;
		int n,m,i;
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lf%lf",&x,&y);
			xg(y/x,(int)x,1,1,n);
			printf("%d\n",cntv[1]);
		}
	}
	return 0;
}
