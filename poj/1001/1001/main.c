#include  <stdio.h>
#include  <string.h>

#define LEN	1024

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
	printf("\n");
}

int main()
{
	int 	tempnum[6][LEN];
	int 	input[LEN];
	char    charinput[LEN];
	int     charlen;    //len of charinput
	char    tempchar;
	int		xiaoshu;
	int		mi;
	int		i, j, numi, k;
	int 	ret[LEN], a[LEN], b[LEN];

	while(1)
	{
        memset(input, 0, sizeof(input));
        memset(tempnum, 0, sizeof(tempnum));
        memset(charinput, 0, sizeof(charinput));
        memset(ret, 0, sizeof(ret));
        if ( scanf("%s%d", charinput, &mi) != 2 )
        {
            return 0;
        }
        if ( mi == 0 )
        {
            printf("1\n");
            continue;
        }
       // printf("<%s> %d\n", charinput, mi);
        for ( i = 5, k = 0, xiaoshu = 0; i >= 0; i--)
        {
            if ( charinput[i] > '0' && charinput[i] <= '9' )
            {
                k = 1;
            }
            else if ( charinput[i] == '.' )
            {
                break;
            }
            xiaoshu += k;
        }
        //find from back
        for ( i = strlen(charinput); ; i--)
        {
            if ( charinput[i] == '.' )
            {
                charinput[i] = 0;
                break;
            }
            else if ( charinput[i] > '0' && charinput[i] <= '9' )
            {
                charinput[i+1] = 0;
                break;
            }
        }

        //printf("B%sB\n", charinput);
        if ( strlen(charinput) == 0 )
        {
            printf("0\n");
            continue;
        }

        //find from front
        for ( i = 0; i < strlen(charinput); i++)
        {
            if ( charinput[i] > '0' && charinput[i] <= '9')
            {
                break;
            }
        }
        if ( i != 0 )
        {
            for ( j = 0; j < strlen(charinput); j++)
            {
                charinput[j] = charinput[i+j];
            }
        }
        //printf("F%sF\n", charinput);
        if ( strlen(charinput) == 0 )
        {
            printf("0\n");
            continue;
        }
        //printf("<%s>\n", charinput);
        for ( i = strlen(charinput)-1, j = 0; i >= 0; i--)
        {
            if ( charinput[i] == '.' )
            {
                continue;
            }
            else
            {
                input[j] = charinput[i] - '0';
                j++;
            }
        }
        //printNum(input);
        //printf("%d\n", xiaoshu);
        memcpy( tempnum[0], input, 7*sizeof(int));
        for( i = 0, j = 1; i < 4 && j <= mi/2; i++, j<<=1)
        {
            cheng(tempnum[i], tempnum[i], tempnum[i+1]);
            //printf("%d %d ", i, j);
            //printNum(tempnum[i]);
        }
        //printf("%d %d ", i, j);
        //printNum(tempnum[i]);
        memset(ret, 0, sizeof(ret));
        ret[0] = 1;
        for ( i = 1, j = 0; i <= mi; i<<=1, j++)
        {
            if ( (mi&i)!=0 )
            {
                cheng(ret, tempnum[j], ret);
            }
        }
       // printf(":\n");
        //printNum(ret);
        //printf("%d [", xiaoshu*mi);
        if ( intlen(ret) > xiaoshu*mi )
        {
            for ( i = intlen(ret) - 1; i >= xiaoshu*mi; i--)
            {
                printf("%d", ret[i]);
            }
            if ( i >= 0 )
            {
                printf(".");
            }
            for ( ; i >= 0; i--)
            {
                printf("%d", ret[i]);
            }
            printf("\n");
        }
        else
        {
            printf(".");
            for ( i = 0; i < xiaoshu*mi-intlen(ret); i++)
            {
                printf("0");
            }
            for ( i = intlen(ret)-1; i >= 0; i--)
            {
                printf("%d", ret[i]);
            }
            printf("\n");
        }
       // printf("]");
	}
	return 0;
}
