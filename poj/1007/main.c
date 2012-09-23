#include  <stdio.h>
#include  <string.h>
#define		MAXX 60
#define		MAXY 120
int main(int argc, char *argv[])
{
	int count[MAXY];
	char input[MAXY][MAXX];
	int pos[MAXY];
	int temp[4], full;
	int i, j, k, x, y;
	memset(count, 0, sizeof(count));
	memset(input, 0, sizeof(input));
	memset(pos, 0, sizeof(pos));
	memset(temp, 0, sizeof(temp));
	scanf("%d %d", &x, &y);
	for( i = 0 ; i < y ; i++ )
	{
		scanf("%s", input[i]);
	}
	for( i = 0 ; i < y ; i++ )
	{
		memset(temp, 0, sizeof(temp));
		for( j = 0 ; j < x ; j++ )
		{
			switch ( input[i][j] )
			{
				case 'A':
					temp[0]++;	
					break;
				case 'C':
					temp[1]++;
					break;
				case 'G':
					temp[2]++;
					break;
				case 'T':
					temp[3]++;
					break;
				default :
					break;
			}
		}
		full = 0;	
		for( j = 0 ; j < x ; j++ )
		{
			switch ( input[i][j] )
			{
				case 'A':
					temp[0]--;	
					break;
				case 'C':
					temp[1]--;
					full+=temp[0];
					break;
				case 'G':
					temp[2]--;
					full+=(temp[0]+temp[1]);
					break;
				case 'T':
					temp[3]--;
					full+=(temp[0]+temp[1]+temp[2]);
					break;
				default :
					break;
			}
		}
		count[i] = full;
//		printf("%s %d\n", input[i], count[i] );
	}
//sort
	for( i = 0 ; i < y ; i++ )
	{
		pos[i] = i;
	}
	for( i = y-1 ; i >= 0 ; i-- )
	{
		for( j = 0 ; j < i ; j++ )
		{
			if ( count[j] > count[j+1] )
			{
				count[j] ^= count[j+1];
				count[j+1] ^= count[j];
				count[j] ^= count[j+1];
				pos[j] ^= pos[j+1];
				pos[j+1] ^= pos[j];
				pos[j] ^= pos[j+1];
			}
		}
	}
	for( i = 0 ; i < y ; i++ )
	{
		printf("%s\n", input[pos[i]]);
	}
	
}
