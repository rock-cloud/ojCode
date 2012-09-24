#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(int argc, char *argv[])
{
    int i, j, k, l;
    int flip[4][4];
    char map[4][5];
    memset(flip, 0, sizeof(flip));
    for( i = 0 ; i < 4 ; i++ )
    {
        scanf("%s", map[i]);
        for( j = 0 ; j < 4 ; j++ )
        {
            if( map[i][j] == '+' )
            {
                for( k = 0 ; k < 4 ; k++ )
                {
                    flip[k][j]++;
                }
                for( k = 0 ; k < 4 ; k++ )
                {
                    flip[i][k]++;
                }
                flip[i][j]--;
            }
        }
    }
    l = 0;
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            if(flip[i][j]%2 !=0)
            {
                l++;
            }
        }
    }
    printf("%d\n", l);
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            if( flip[i][j]%2 != 0 )
            {
                printf("%d %d\n", i+1, j+1);
            }
        }
    }
    return 0;
}
