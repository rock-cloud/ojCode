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
	int pairs[MAX_PAIRS][2];
	unsigned char lines[2][MAX_LENGTH], startLine, startNode;
	unsigned char absNum[2][MAX_LENGTH];
	int recentNum, recentMount;
	int dir[6][4][2] =
	{
		{{1, 0}, {1, 1}, {0, 1}, {0, 0}},
		{{1, 0}, {1, 1}, {0, 1}, {-1, 1}},
		{{0, 1}, {-1, 1}, {0, 0}, {0, 0}},
		{{1, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 1}, {0, 0}, {0, 0}, {0, 0}}
	};
	int idx, i, j, k, a, b, pairMount, tempWidth, idir, tempValue, lineValue, nextLine, lastLineLength;
	while(1)
	{
		memset(pairs, 0, sizeof(pairs));
		memset(absNum, 0, sizeof(absNum));
		memset(lines, 0, sizeof(lines));
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
        recentMount = 0;
        recentNum = 0;
        lastLineLength = 0;
        printf("%d\n", width);
		//parepar first line
		while( idx < pairMount )
		{
			if ( width - startNode < pairs[idx][1] )
			{
				memset(&lines[0][startNode], pairs[idx][0], width-startNode);
				pairs[idx][1] = pairs[idx][1] - (width - startNode);
				startNode = 0;
				startLine ^= 1;
				lastLineLength += width-startNode;
				break;
			}
			else if ( width - startNode == pairs[idx][1] )
			{
				memset(&lines[0][startNode], pairs[idx][0], width-startNode);
				pairs[idx][1] = 0;
				idx++;
				startNode = 0;
				startLine ^= 1;
				lastLineLength += width-startNode;
				break;
			}
			else
			{
				memset(&lines[0][startNode], pairs[idx][0], pairs[idx][1]);
				startNode += pairs[idx][1];
				pairs[idx][1] = 0;
				lastLineLength += pairs[idx][1];
				idx++;
			}
		}

		//parepar next lines
		while(idx < pairMount)
		{
		    lastLineLength = 0;
			while(idx < pairMount)
			{
				if( width - startNode < pairs[idx][1] )
				{
					memset(&lines[startLine][startNode], pairs[idx][0], width-startNode);
					pairs[idx][1] = pairs[idx][1] - (width - startNode);
					startNode = 0;
					startLine ^= 1;
					lastLineLength += width-startNode;
					break;
				}
				else if ( width - startNode == pairs[idx][1] )
				{
					memset(&lines[startLine][startNode], pairs[idx][0], width-startNode);
					pairs[idx][1] = 0;
					idx++;
					startNode = 0;
					startLine ^= 1;
					lastLineLength += width-startNode;
					break;
				}
				else
				{
					memset(&lines[startLine][startNode], pairs[idx][0], pairs[idx][1]);
					startNode += pairs[idx][1];
					pairs[idx][1] = 0;
					lastLineLength += pairs[idx][1];
					idx++;
				}
			}
			lineValue = lines[startLine][0];
			memset(absNum[startLine^1], 0, MAX_LENGTH);
			for( j = 0 ; j < 3 ; j++ )
			{
				tempValue = abs(lines[ dir[0][j][DIRY] ^ startLine ][ dir[0][j][DIRX] ] - lineValue);
				if ( tempValue > absNum[ dir[0][j][DIRY] ^ startLine ][ dir[0][j][DIRX] ])
				{
					absNum[ dir[0][j][DIRY] ^ startLine ][ dir[0][j][DIRX] ] = tempValue;
				}
				if ( tempValue > absNum[startLine][0] )
				{
					absNum[startLine][0] = tempValue;
				}
			}
			if ( absNum[startLine][0] == recentNum )
			{
                recentMount++;
			}
			else if ( recentMount > 0 )
			{
                printf("%d %d\n", recentNum, recentMount);
                recentNum = absNum[startLine][0];
                recentMount = 1;
			}
			else
			{
                recentNum = absNum[startLine][0];
                recentMount = 1;
			}
			for( i = 1 ; i < width-1 ; i++ )
			{
				lineValue = lines[startLine][i];
				for( j = 0 ; j < 4 ; j++ )
				{
					tempValue = abs(lines[ dir[1][j][DIRY] ^ startLine ][ i + dir[1][j][DIRX] ] - lineValue);
					if ( tempValue > absNum[ dir[1][j][DIRY] ^ startLine ][ i + dir[1][j][DIRX] ])
					{
						absNum[ dir[1][j][DIRY] ^ startLine ][ i + dir[1][j][DIRX] ] = tempValue;
					}
					if ( tempValue > absNum[startLine][i] )
					{
						absNum[startLine][i] = tempValue;
					}
				}
                if ( absNum[startLine][i] == recentNum )
                {
                    recentMount++;
                }
                else if ( recentMount > 0 )
                {
                    printf("%d %d\n", recentNum, recentMount);
                    recentNum = absNum[startLine][i];
                    recentMount = 1;
                }
                else
                {
                    recentNum = absNum[startLine][i];
                    recentMount = 1;
                }
			}
			lineValue = lines[startLine][i];
			for( j = 0 ; j < 2 ; j++ )
			{
				tempValue = abs(lines[ dir[2][j][DIRY] ^ startLine ][ i + dir[2][j][DIRX] ] - lineValue);
				if ( tempValue > absNum[ dir[2][j][DIRY] ^ startLine ][ i + dir[2][j][DIRX] ])
				{
					absNum[ dir[2][j][DIRY] ^ startLine ][ i + dir[2][j][DIRX] ] = tempValue;
				}
				if ( tempValue > absNum[startLine][i] )
				{
					absNum[startLine][i] = tempValue;
				}
			}
			if ( absNum[startLine][i] == recentNum )
            {
                recentMount++;
            }
            else if ( recentMount > 0 )
            {
                printf("%d %d\n", recentNum, recentMount);
                recentNum = absNum[startLine][i];
                recentMount = 1;
            }
            else
            {
                recentNum = absNum[startLine][i];
                recentMount = 1;
            }
			/*for ( i = 0; i < width; i++)
			{
				printf("%3d ", absNum[startLine][i]);
			}
			printf("\n");*/
        }
        for( i = 0 ; i < lastLineLength - 1; i++ )
		{
			lineValue = lines[1^startLine][i];

			tempValue = abs(lines[ 1 ^ startLine ][ i + 1 ] - lineValue);
			if ( tempValue > absNum[ 1 ^ startLine ][ i + 1 ])
			{
				absNum[ 1 ^ startLine ][ i + 1 ] = tempValue;
			}
			if ( tempValue > absNum[1^startLine][i] )
			{
				absNum[1^startLine][i] = tempValue;
			}
			if ( absNum[1^startLine][i] == recentNum )
            {
                recentMount++;
            }
            else if ( recentMount > 0 )
            {
                printf("%d %d\n", recentNum, recentMount);
                recentNum = absNum[1^startLine][i];
                recentMount = 1;
            }
            else
            {
                recentNum = absNum[1^startLine][i];
                recentMount = 1;
            }
		}
		if ( absNum[1^startLine][lastLineLength-1] == recentNum )
        {
            recentMount++;
        }
        else if ( recentMount > 0 )
        {
            printf("%d %d\n", recentNum, recentMount);
            recentNum = absNum[1^startLine][lastLineLength-1];
            recentMount = 1;
        }
        else
        {
            recentNum = absNum[1^startLine][lastLineLength-1];
            recentMount = 1;
        }
        printf("%d %d\n", recentNum, recentMount);
        printf("0 0");
	}
	return 0;
}
