#include<stdio.h>
#include<math.h>

struct node
{
	double a,b,c,d,e,g,h,ii,jj,k;
	int id;
}as[6000];

double sd[6000][6000];
double num,nu,s;
int aa[20][3000][6];
int ab[20]={0,11,101,4,28,46,403,23,208,95,81,406,229,38,2808,677,141,89,50,162};
int im1,im2,im3,im11,im22,im33,ji1,ji2; 
int im[620][6][6];
double answerr,answerr1;

double mo1(int mm,int nn)
{
	double answer;
	for(int j=1;j<=mm;++j)
	{
		for(int k=1;k<=mm;++k)
		{
			answer+=sd[aa[nn][j][2]][aa[nn][k][2]];	
		}	
	}
	return answer/mm/mm;
}

double mo2(int mm1,int nn1,int mm2,int nn2)
{
	double answer1;
	for(int j=1;j<=mm1;++j)
	{
		for(int k=1;k<=mm2;++k)
		{
			answer1+=sd[aa[nn1][j][2]][aa[nn2][k][2]];	
		}	
	}
	return answer1/mm1/mm2;
}

int main()
{
	freopen("data_by_artist.txt","r",stdin);
	freopen("answer.txt","w",stdout);
	for(int i=1;i<=19;++i) 
	{
		for(int j=1;j<=ab[i];++j)
		{
			scanf("%d",&aa[i][j][1]);
		} 
	}
	for(int i=1;i<=5854;++i)
	{
		scanf("%d",&as[i].id);
		bool flag=0;
		for(int j=1;j<=19;++j) 
		{
			for(int k=1;k<=ab[j];++k)
			{
				if(as[i].id==754032)
				{
					im1=i;
					im2=j;
					im3=k;
				}
				if(as[i].id==858827)
				{
					im11=i;
					im22=j;
					im33=k;
				}
				if(aa[j][k][1]==as[i].id) 
				{
					aa[j][k][2]=i;
					flag=1;
					break;
				}	
			} 
			if(flag) break;
		}
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&as[i].a,&as[i].b,&as[i].c,&as[i].d,&as[i].e,&as[i].g,&as[i].h,&as[i].ii,&as[i].jj,&as[i].k);
	}
	for(int i=1;i<=5854;++i)
	{
		for(int j=1;j<=5854;++j)
		{
			sd[i][j]=(sqrt((as[i].a-as[j].a)*(as[i].a-as[j].a)+(as[i].b-as[j].b)*(as[i].b-as[j].b)+(as[i].c-as[j].c)*(as[i].c-as[j].c)+(as[i].d-as[j].d)*(as[i].d-as[j].d)+(as[i].e-as[j].e)*(as[i].e-as[j].e)+(as[i].g-as[j].g)*(as[i].g-as[j].g)+(as[i].h-as[j].h)*(as[i].h-as[j].h)+(as[i].ii-as[j].ii)*(as[i].ii-as[j].ii)+(as[i].jj-as[j].jj)*(as[i].jj-as[j].jj)+(as[i].k-as[j].k)*(as[i].k-as[j].k)));
		}
	}//754032
	for(int i=1;i<=615;++i)
	{
		scanf("%d",&im[i][1][1]);
		bool flag1=0;
		for(int j=1;j<=19;++j) 
		{
			for(int k=1;k<=ab[j];++k)
			{
				if(im[i][1][1]==aa[j][k][1]) 
				{
					aa[j][k][1]=0;
					//im[i][1][2]=aa[j][k][2];
					//im[i][2][1]=j;
					//im[i][2][2]=k;
					flag1=1;
					break;
				}	
			} 
			if(flag1) break;
		}
	}
	for(int i=1;i<=300;++i)
	{
		if(aa[14][i][1]==0) continue;
		num+=sd[aa[14][i][2]][aa[14][im3][2]];
		ji1++;
	}
	nu=num/ji1;
	for(int i=1;i<=300;++i)
	{
		if(aa[14][i][1]==0) continue;
		s+=(sd[aa[14][i][2]][aa[14][im3][2]]-nu)*(sd[aa[14][i][2]][aa[14][im3][2]]-nu);
		ji2++;
	}
	s=s/ji2;
	s=sqrt(s);
	if(sd[aa[14][im33][2]][aa[14][im3][2]]<nu-(1.65*s)) printf("1");
	else if(sd[aa[14][im33][2]][aa[14][im3][2]]>nu+(1.65*s)) printf("-1");
	else printf("0");
	/* 
	for(int i=1;i<=19;++i)
	{
		answerr=mo1(ab[i],i);
		printf("%d %.6lf\n",i,answerr);
	}
	for(int i=1;i<=19;++i)
	{
		for(int j=1;j<=i;++j) 
		{
			answerr1=mo2(ab[i],i,ab[j],j);
			printf("%d->%d %.6lf\n",i,j,answerr1);
		}
	}
	*/ 
	/*for(int i=1;i<=5854;++i)
	{
		for(int j=1;j<=5854;++j)
		{
			printf("%d,%d,%.6lf\n",as[i].id,as[j].id,sd[i][j]);
		}
	}
	*/ 
	return 0;
} 
