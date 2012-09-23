#include  <stdio.h>
#include  <string.h>

#define LEN	512

int intlen(int a[LEN])
{
    int i;
    for ( i = LEN-1; i >= 0; i--)
    {
		if ( a[i] > 0 )
		{
			return i+1;
		}
    }
    return 0;
}

void cheng( int a[LEN], int b[LEN], int ret[LEN])
{
	int add;
	int len_a = intlen(a), len_b = intlen(b);
	int i, j, k;
	int tempRet[LEN];
	memset(tempRet, 0, LEN*sizeof(int));
	for ( i = 0; i < len_b; i++)
	{
		for( j = 0; j < len_a ; j++ )
		{
			k = j;
			tempRet[i+k] += a[j]*b[i];
			while(tempRet[i+k]>=10)
			{
				tempRet[i+k+1] += (tempRet[i+k])/10;
				tempRet[i+k] = (tempRet[i+k])%10;
				k++;
			}
		}
	}
	memcpy(ret, tempRet, LEN*sizeof(int));
	return;
}

void printNum(int a[LEN])
{
    int i;
	for ( i = intlen(a)-1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}

int main()
{
	int 	tempnum[6][LEN];
	int 	input[LEN];
	char    tempchar;
	int		xiaoshu;
	int		mi;
	int		i, j, numi;
	int 	ret[LEN], a[LEN], b[LEN];
	memset(input, 0, sizeof(input));
	for ( i = 4, xiaoshu = 0; i >= 0; i--)
	{
		tempchar = getchar();
		if ( tempchar >= '0' && tempchar <= '9' )
		{
			input[i] = tempchar-'0';
		}
		else if (tempchar == '.')
		{
			xiaoshu = i+1;
			i++;
		}
		else
		{
			i++;
		}
	}
	getchar();
	scanf("%d", &mi);
	printNum(input);
	printf("^%d %d\n", mi, xiaoshu);
	memcpy( tempnum[0], input, 7*sizeof(int));
	for( i = 0, j = 1; i < 4 && j < mi*2; i++, j<<=2)
	{
		cheng(tempnum[i], tempnum[i], tempnum[i+1]);
	}
	memset(ret, 0, sizeof(ret));
	ret[0] = 1;
	for ( i = 1, j = 0; i <= 32; i<<=1, j++)
	{
		if ( (mi&i)!=0 )
		{
//			printNum(ret);
//			printf("\n");
//			printNum(tempnum[j]);
//			printf("\n");
			cheng(ret, tempnum[j], ret);
		}
	}
	printNum(ret);
}
