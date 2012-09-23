#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int printBe(int be[16]) {
    int j;
    for ( j = 0; j < 12; j++) {
        printf("%d ", be[j]);
    }
    printf("\n");
    return 0;
}
int main(int argc, char *argv[])
{
    int mount, i, j, k;
    int max, idx;
    int l1, l2;
    int be[16], temp[16];
    char str[3][16];
    scanf("%d", &mount);
    for ( i = 0; i < mount; i++) {
        for ( k = 0; k < 16; k++ ) {
            be[k] = 1;
        }
        for ( j = 0; j < 3; j++) {
            memset(str, 0, sizeof(str));
            scanf("%s %s %s", str[0], str[1], str[2]);
            l1 = strlen(str[0]);
            l2 = strlen(str[1]);
            if ( str[2][0] == 'e' ) {
                for ( k = 0; k < l1; k++) {
                    be[str[0][k]-'A'] = 0;
                }
                for ( k = 0; k < l2; k++) {
                    be[str[1][k]-'A'] = 0;
                }
        //        printBe(be);
            } else if ( str[2][0] == 'u' ) {
                memset(temp, 0, sizeof(temp));
                for ( k = 0; k < l1; k++) {
                    if ( be[str[0][k]-'A'] ) {
                        be[str[0][k]-'A'] += 2;
                    }
                    temp[str[0][k]-'A'] = 1;
                }
                for ( k = 0; k < l2; k++) {
                    if ( be[str[1][k]-'A'] ) {
                        be[str[1][k]-'A'] -= 2;
                    }
                    temp[str[1][k]-'A'] = 1;
                }
                for ( k = 0; k < 12; k++) {
                    be[k] *= temp[k];
                }
               // printBe(be);
            } else if ( str[2][0] == 'd' ) { 
                memset(temp, 0, sizeof(temp));
                for ( k = 0; k < l1; k++) {
                    if ( be[str[0][k]-'A'] ) {
                        be[str[0][k]-'A'] -= 2;
                    }
                    temp[str[0][k]-'A'] = 1;
                }
                for ( k = 0; k < l2; k++) {
                    if ( be[str[1][k]-'A'] ) {
                        be[str[1][k]-'A'] += 2;
                    }
                    temp[str[1][k]-'A'] = 1;
                }
                for ( k = 0; k < 12; k++) {
                    be[k] *= temp[k];
                }
               // printBe(be);
            } 
        }
        idx = 0;
        for ( max = -1, j = 0; j < 12; j++) {
            if ( be[j] >= 0 && be[j] > max ) {
                max = be[j];
                idx = j;
            } else if ( be[j] < 0 && 0-be[j] > max ) {
                max = 0-be[j];
                idx = j;
            } 
        }
        if ( be[idx] > 0 ) {
            printf("%c is the counterfeit coin and it is heavy.\n", idx+'A');
        } else {
            printf("%c is the counterfeit coin and it is light.\n", idx+'A');
        }
    }
}

