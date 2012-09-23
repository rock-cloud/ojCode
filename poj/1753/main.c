#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(int argc, char *argv[])
{
    char map[6][6];
    int wmap[6][6], bmap[6][6];
    int i, j, m, wstep, bstep, mstep;
    for( i = 1 ; i < 5 ; i++ ) {
        scanf("%s", map[i]+1);
    }
    mstep = 17;
    for ( m = 0; m < 16; m++ ) {
        for ( i = 1; i < 5; i++) {
            for ( j = 1; j < 5; j++) {
                if( map[i][j] == 'b' ) {
                    wmap[i][j] = 1;
                    bmap[i][j] = 0;
                } else {
                    wmap[i][j] = 0;
                    bmap[i][j] = 1;
                }
            }
        }
        bstep = 0;
        wstep = 0;
        for ( i = 1, j = 1; i < 16; i *= 2, j++ ) {
            if ( (m & i) != 0 ) {
                wstep++;
                bstep++;
                wmap[1][j-1] = 1 - wmap[1][j-1];
                wmap[2][j]   = 1 - wmap[2][j];
                wmap[1][j+1] = 1 - wmap[1][j+1];
                wmap[1][j]   = 1 - wmap[1][j];
                bmap[1][j-1] = 1 - bmap[1][j-1];
                bmap[2][j]   = 1 - bmap[2][j];
                bmap[1][j+1] = 1 - bmap[1][j+1];
                bmap[1][j]   = 1 - bmap[1][j];
            }
        }
        for( i = 2 ; i < 5 ; i++ ) {
            for( j = 1 ; j < 5 ; j++ ) {
                if( wmap[i-1][j] == 1 ) {
                    wstep++;
                    wmap[i-1][j] = 1 - wmap[i-1][j];
                    wmap[i][j-1] = 1 - wmap[i][j-1];
                    wmap[i+1][j] = 1 - wmap[i+1][j];
                    wmap[i][j+1] = 1 - wmap[i][j+1];
                    wmap[i][j] = 1 - wmap[i][j];
                } 
                if( bmap[i-1][j] == 1 ) {
                    bstep++;
                    bmap[i-1][j] = 1 - bmap[i-1][j];
                    bmap[i][j-1] = 1 - bmap[i][j-1];
                    bmap[i+1][j] = 1 - bmap[i+1][j];
                    bmap[i][j+1] = 1 - bmap[i][j+1];
                    bmap[i][j] = 1 - bmap[i][j];
                }
            }
        }
        if ( bmap[4][4]+bmap[4][3]+bmap[4][2]+bmap[4][1] == 0 ) {
            if ( wmap[4][4]+wmap[4][3]+wmap[4][2]+wmap[4][1] == 0 ) {
                mstep = ( mstep < wstep ? mstep : wstep);
                mstep = ( mstep < bstep ? mstep : bstep);
            } else {
                mstep = ( mstep < bstep ? mstep : bstep);
            }
        } else if ( wmap[4][4]+wmap[4][3]+wmap[4][2]+wmap[4][1] == 0 ) {
            mstep = ( mstep < wstep ? mstep : wstep);
        }   
    } 
    if ( mstep != 17 ) {
        printf("%d\n", mstep);
    } else {
        printf("Impossible\n");
    }
}
