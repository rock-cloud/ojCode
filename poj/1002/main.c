#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 120000

/*
A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V map to 8
W, X, and Y map to 9
*/

int cmp( const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int hash[MAX];
    int map[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
    int mount, i, j, num, flag;
    char input;
    scanf("%d", &mount);
    memset(hash, 0, sizeof(hash));
    for ( i = 0; i < mount; i++)
    {
        num = 0;
        for ( j = 0; j < 7; )
        {
            scanf("%c", &input);
            if ( input >= 'A' && input <= 'Z' )
            {
                num = num*10 + map[input-'A'];
                j++;
            }
            else if ( input >= '0' && input <= '9' )
            {
                num = num*10 + (input - '0');
                j++;
            }
        }

        hash[i] = num;
    }
    qsort(hash, mount, sizeof(int), cmp);
    if ( mount == 1 )
    {
        printf("No duplicates.\n");
    }
    flag = 0;
    num = 1;
    for ( i = 1; i < mount; i++)
    {
        if ( hash[i] == hash[i-1] )
        {
            num++;
        }
        else if ( num > 1 )
        {
            printf("%03d-%04d %d\n", hash[i-1]/10000, hash[i-1]%10000, num);
            flag = 1;
            num = 1;
        }
        else
        {
            num = 1;
        }
    }
    if ( num > 1 )
    {
        printf("%03d-%04d %d\n", hash[mount-1]/10000, hash[mount-1]%10000, num);
        flag = 1;
    }
    if ( flag == 0 )
    {
        printf("No duplicates.\n");
    }
    return 0;
}
