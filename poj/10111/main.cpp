
#include <iostream>
#include <algorithm>
#include <functional>
#include  <stdio.h>
#include  <string.h>
using namespace std;
int n;
int stick[70];
int used[70];
int num;
int length;
int quick[70];
int xa = 0, xb = 0, xbb = 0, xc = 0, xd = 0, xe = 0, xf = 0, xg = 0, fa = 0, fb = 0, fc = 0, fd = 0;
bool dfs(int left,int i,int total)
{
 	if (total == num)
 	{
		xa++;
 		return true;
 	}
 	for (int j = i; j <= n;j++)
 	{
		if (left < stick[j])
 		{
			if ( j < quick[j] - 1 )
			{
				j = quick[j] -1;
			}
			xb++;
 			continue;
 		}
 		else if ( used[j] == 1 )
 		{
			xbb++;
 		    continue;
 		}
 		else if(left == stick[j])
 		{
			fa++;
			//printf("%d ", stick[j]);
 			used[j] = true;
 			if (dfs(length, 1, total + 1))
 			{
				fb++;
				xc++;
 				return true;
 			}
 			else
 			{
				fc++;
 				used[j] = false;
 				xd++;
 				break;
 			}
 		}
 		else
 		{
			//printf("%d ", stick[j]);
 			used[j] = true;
 			if ( dfs(left - stick[j], j + 1, total))
 			{
				xe++;
 				return true;
 			}
 			else
 			{
				fd++;
 				used[j] = false;
 				if (left == length || j == n)
 				{
					xf++;
 					return false;//在搜索一根全新的小棒不成功，那么停止搜索，剪枝//当j = n时候也停止搜索
 				}
 				j = quick[j] - 1 ;//同样长的小棒不再同样搜索，掠过，剪枝，后面有j++，所以需要减一
 			}
 		}
 	}
 	xg++;
 	return false;
}
int main()
{
 	while (scanf("%d",&n) && n != 0)
 	{
 		int longest = 0,sum = 0;
 		memset(stick,0,sizeof(stick));
 		for (int i = 1; i <= n; i++)
 		{
 			scanf("%d",&stick[i]);
 			sum += stick[i];
 			if (stick[i] > longest)
 			{
 				longest = stick[i];
 			}
 		}
 		sort(stick + 1,stick + 1 + n,greater<int>());
		/*printf("\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%3d ", stick[i]);
		}
		printf("\n");*/
 		{
 			int began = 1;
 			int temp = stick[n];stick[n] = -1;
 			for (int i = 1; i < n ;i++)
 			{
 				if (stick[i] > stick[i + 1])
 				{
 					for ( int j = began; j <= i; j++)
 					{
 						quick[j] = i + 1;
 					}
 					began = i + 1;
 				}
 			}
 			stick[n] = temp;
 		}
		/*for (int i = 1; i <= n; i++)
		{
			printf("%3d ", quick[i]);
		}
		printf("\n");*/
 		for (int i = longest; i <= sum; i++)
 		{
 			if (sum % i == 0)
 			{
 				memset(used,false,sizeof(used));
 				num = sum / i;length = i;
 				//printf("[%d]\n", length);
 				if (dfs(length,1,0))
 				{
 					cout<<i<<endl;
 					break;
 				}
 			}
 		}
 	}
 	/*printf("%d %d %d %d %d %d %d %d\n", xa, xb, xbb, xc, xd, xe, xf, xg);
 	printf("%d %d %d %d\n", fa, fb, fc, fd);*/
 	return 0;
}
