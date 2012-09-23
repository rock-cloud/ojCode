#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

#define MAX_PAIRS	1024
#define MAX_LENGTH	1024
#define DIRX	0
#define DIRY	1

int main(int argc, char *argv[])
{
	int width;
	unsigned char pairs[MAX_PAIRS][2];
	unsigned char lines[2][MAX_LENGTH], startLine, startNode;
	unsigned char absNum[2][MAX_LENGTH];
	char dir[6][4][2] = 
	{
		{{1, 0}, {1, 1}, {0, 1}, {0, 0}},
		{{1, 0}, {1, 1}, {0, 1}, {-1, 1}},
		{{0, 1}, {-1, 1}, {0, 0}, {0, 0}},
		{{1, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 1}, {0, 0}, {0, 0}, {0, 0}}
	};
	int idx, i, j, k, a, b, pairMount, tempWidth, idir, tempValue, lineValue, nextLine;
	while(1)
	{
		memset(pairs, 0, sizeof(pairs));
		scanf("%d", &width);
		if( width == 0 )
		{
			break;
		}
		for( pairMount = 0 ; pairMount < MAX_PAIRS ; pairMount++ )
		{
			scanf("%d %d", &a, &b);
			if ( a == 0 && b == 0 )
			{
				break;
			}
			pairs[pairMount][0] = a;
			pairs[pairMount][1] = b;
		}
		idx = 0;
		startNode = 0;
		startLine = 0;
		memset(absNum, 0, sizeof(absNum));
		//parepar first line
		while( idx < pairMount )
		{
			if ( width - startNode < pairs[idx][1] )
			{
				memset(&lines[0][startNode], pairs[idx][0], width-startNode);
				pairs[idx][1] = pairs[idx][1] - (width - startNode);
				startNode = 0;
				startLine = 1;
				break;
			}
			else if ( width - startNode == pairs[idx][1] )
			{
				memset(&lines[0][startNode], pairs[idx][0], width-startNode);
				pairs[idx][1] = 0;
				idx++;
				startNode = 0;
				startLine ^= 1;
				break;
			}
			else
			{
				memset(&lines[0][startNode], pairs[idx][0], pairs[idx][1]);
				startNode += pairs[idx][1];
				pairs[idx][1] = 0;
				idx++;
			}
		}
		//parepar next lines
		while(idx < pairMount)
		{
			while(idx < pairMount)
			{
				//printf("{%d %d}\n", idx, pairMount);
				if( width - startNode < pairs[idx][1] )
				{
					memset(&lines[startLine][startNode], pairs[idx][0], width-startNode);
					pairs[idx][1] = pairs[idx][1] - (width - startNode);
					startNode = 0;
					startLine ^= 1;
					for( i = 0 ; i < width ; i++ )
					{
						//printf("%3d ", lines[startLine^1][i]);
					}
					printf("\n");
					break;
				}
				else if ( width - startNode == pairs[idx][1] )
				{
					memset(&lines[startLine][startNode], pairs[idx][0], width-startNode);
					pairs[idx][1] = 0;
					idx++;
					startNode = 0;
					startLine ^= 1;
					for( i = 0 ; i < width ; i++ )
					{
						//printf("%3d ", lines[startLine^1][i]);
					}
					printf("\n");
					break;
				}
				else 
				{
					memset(&lines[startLine][startNode], pairs[idx][0], pairs[idx][1]);
					startNode += pairs[idx][1];
					pairs[idx][1] = 0;
					idx++;
				}
			}
			lineValue = lines[startLine][0];
			if ( startLine == 0 )
			{
				nextLine = 1;
			}
			else
			{
				nextLine = -1;
			}
			printf("nextLine %d\n", nextLine);
			for( j = 0 ; j < 3 ; j++ )
			{
				tempValue = abs(lines[ nextLine*dir[0][j][DIRY] + startLine ][ dir[0][j][DIRX] ] - lineValue);	
				if ( tempValue > absNum[ nextLine*dir[0][j][DIRY] + startLine ][ dir[0][j][DIRX] ])
				{
					absNum[ nextLine*dir[0][j][DIRY] + startLine ][ dir[0][j][DIRX] ] = tempValue;
				}
				if ( tempValue > absNum[startLine][0] )
				{
					absNum[startLine][0] = tempValue;
				}
			}
			for( i = 1 ; i < width-1 ; i++ )
			{
				lineValue = lines[startLine][i];
				for( j = 0 ; j < 4 ; j++ )
				{
					tempValue = abs(lines[ nextLine*dir[1][j][DIRY] + startLine ][ i + dir[1][j][DIRX] ] - lineValue);	
					if ( tempValue > absNum[ nextLine*dir[1][j][DIRY] + startLine ][ i + dir[1][j][DIRX] ])
					{
						absNum[ nextLine*dir[1][j][DIRY] + startLine ][ i + dir[1][j][DIRX] ] = tempValue;
					}
					if ( tempValue > absNum[startLine][0] )
					{
						absNum[startLine][i] = tempValue;
					}
				}
			}
			for( j = 0 ; j < 2 ; j++ )
			{
				tempValue = abs(lines[ nextLine*dir[2][j][DIRY] + startLine ][ dir[2][j][DIRX] ] - lineValue);	
				if ( tempValue > absNum[ nextLine*dir[2][j][DIRY] + startLine ][ dir[2][j][DIRX] ])
				{
					absNum[ nextLine*dir[2][j][DIRY] + startLine ][ dir[2][j][DIRX] ] = tempValue;
				}
				if ( tempValue > absNum[startLine][0] )
				{
					absNum[startLine][0] = tempValue;
				}
			}
			for ( i = 0; i < width; i++)
			{
				printf("%3d ", absNum[startLine][i]);
			}
			printf("\n");
			for ( i = 0; i < width; i++)
			{
				printf("%3d ", absNum[startLine+nextLine][i]);
			}
			printf("\n");
			getchar();
		}
	}
	return 0;
}
