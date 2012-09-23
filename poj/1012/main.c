#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int main(int argc, char *argv[])
{
    int k, i, m, j, killed;
    int mod = 0;
    int array[32], before[32], dead[32];
    while(1) {
        scanf("%d", &k);
        if( k == 0 ) { 
            return 0;
        }
        for ( i = 0; i < k*2 - 1; i++) {
            array[i] = i+1; 
        }
        array[2*k-1] = 0;
        for ( i = k*2-1; i > 0; i-- ) {
            before[i] = i-1;
        }
        before[0] = 2*k-1;
        memset(dead, 0, sizeof(dead));
        //simulation
        mod = 0;
        for ( m = k + 1; ; m = m + mod*k+(1-mod), mod = 1-mod ) {
            printf("m: %d\n", m);
            for ( i = 0; i < k*2-1; i++ ) {
                array[i] = i+1;
            }
            array[2*k-1] = 0;
            for ( i = k*2-1; i > 0; i-- ) {
                before[i] = i-1;
            }
            before[0] = 2*k-1;
            memset(dead, 0, sizeof(dead));
            for ( i = 2*k-1, killed = 0; killed < k; killed++ ) {
                i = (i+m-1)%(2*k-killed)+1;
                printf("killed: %d\n", i);
                //get the m turn
                if ( i >= k ) {
                } else {
                    //kill the wrong person
                    break;
                }
                i--;
            } 
            if ( killed == k ) {
                printf("%d\n", m+1);
                break;
            }
        }
    }
}
