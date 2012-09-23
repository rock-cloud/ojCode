#include <iostream>
#include <algorithm>
#include <cmath>
#include  <stdio.h>
using namespace std;

int n;
int t;
int len[111];
int b[111][111];
int p[111][111];
int a[222222];
int m;

double calc(int x)
{
	double sum(0);
	for (int i=1; i<=n; i++)
	{
		int xiao = 2147483647;
		for (int j=1; j<=len[i]; j++)
			if (b[i][j] >= x) xiao = min(xiao, p[i][j]);
		sum += xiao;
	}
	return x / sum;
}
int main(void)
{
	int i,j,k,ci,cici,cicici;

	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i=1; i<=n; i++)
		{
			scanf("%d", &len[i]);
			for (j=1; j<=len[i]; j++)
			{
				scanf("%d%d", &b[i][j], &p[i][j]);
				a[++m] = b[i][j];
			}			
		}

		sort(a+1, a+1+m);

		int left = 1, right = m, mid1, mid2;
		double f1, f2;
		while(left + 1 < right)
		{
			mid1 = (left + right) / 2;
			mid2 = (mid1 + right) / 2;
			f1 = calc(a[mid1]);
			f2 = calc(a[mid2]);
			if (f1 < f2) left = mid1;
			else right = mid2;
		}
		printf("%.3lf\n", max(calc(a[left]), calc(a[right])));
	}
	return 0;
}
