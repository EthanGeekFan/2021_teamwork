#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
using namespace std;
int n;
bool mapp[10010];
bool mappp[5610][5610];
int name[80000010];
struct node{
	int id;
	int rd_num,cd_num;
	int rd[8610],cd[8610];
	double val;
}e[5610];

int q[2000010];
//5603 , 5603
//id=754032

int main()
{
	freopen("data.in","r",stdin);
	freopen("data_2-7.out","w",stdout);
	n=5603;
	for(int i=1;i<=n;i++)
	{
		e[i].val=1;
		scanf("%d",&e[i].id);
		name[e[i].id]=i;
		scanf("%d",&e[i].cd_num);
		for(int j=1;j<=e[i].cd_num;j++)
		{
			scanf("%d",&e[i].cd[j]);
		}
		scanf("%d",&e[i].rd_num);
		for(int j=1;j<=e[i].rd_num;j++)
		{
			scanf("%d",&e[i].rd[j]);
		}
//		scanf("%d",&e[i].year);
	}
	for(int i=1;i<=n;i++)
	{
		int x_id;
		double x_val;
		scanf("%d%lf",&x_id,&x_val);
		e[name[x_id]].val=x_val;
	}
	int l=1,r=1;
	q[r]=754032;
	mapp[name[754032]]=true;
	int mun=0;
	while(l<=r)
	{
		int now=name[q[l]];
		for(int i=1;i<=e[now].cd_num;i++)
		{
			int n_now=name[e[now].cd[i]];
			if(mappp[now][n_now]==true)break;
			if(mapp[n_now]==false)
			{
				mapp[n_now]=true;
				r++;
				q[r]=e[now].cd[i];
			}
			printf("%d %d %.2lf %.2lf\n",e[now].id,e[n_now].id,e[now].val,e[n_now].val);
			mappp[now][n_now]=true;
			mappp[n_now][now]=true;
			mun++;
		}
		l++;
	}
	memset(q,0,sizeof(q));
	memset(mapp,false,sizeof(mapp));
//	memset(mappp,false,sizeof(mappp));
	l=1,r=1;
	q[r]=754032;
	mapp[name[754032]]=true;
	int mmun=0;
	while(l<=r)
	{
		int now=name[q[l]];
		for(int i=1;i<=e[now].rd_num;i++)
		{
			int n_now=name[e[now].rd[i]];
			if(mappp[now][n_now]==true)break;
			if(mapp[n_now]==false)
			{
				mapp[n_now]=true;
				r++;
				q[r]=e[now].rd[i];
			}
			printf("%d %d %.2lf %.2lf\n",e[n_now].id,e[now].id,e[n_now].val,e[now].val);
			mappp[n_now][now]=true;
			mappp[now][n_now]=true;
			mmun++;
		}
		l++;
	}
	printf("-------------\n%d %d\n------------\n",mun,mmun);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
