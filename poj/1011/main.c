#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp( const void *q, const void *p)
{
    return (*(int *)p-*(int *)q);
}

int mount;
char used[100];
int quick[100];
int usedIndex = 0;
int sticks[100], length;
int xa = 0, xb = 0, xbb = 0, xc = 0, xd = 0, xe = 0, xf = 0, xg = 0, fa = 0, fb = 0, fc = 0, fd = 0;

int search(int mainTarget, int target, int start, int usefulStick, int left)
{
    if ( left == 0 && usefulStick == 0 )
    {
        return 1;
    }
    for ( ; start < mount; start++)
    {
        if ( sticks[start] > target )
        {
            if ( start < quick[start]-1 )
            {
                start = quick[start] - 1;
            }
            continue;
        }
        else if ( used[start] == 1 )
        {
            continue;
        }
        //printf("%d ", sticks[start]);
        target -= sticks[start];
        left -= sticks[start];
        used[start] = 1;
        usefulStick--;
        if ( target == 0 )
        {
            if ( search(mainTarget, mainTarget, 0, usefulStick, left) == 1 )
            {
                return 1;
            }
            else
            {
                used[start] = 0;
                break;
            }
        }
        else if ( search(mainTarget, target, start+1, usefulStick, left) == 1 )
        {
            return 1;
        }
        else
        {
            target += sticks[start];
            left += sticks[start];
            used[start] = 0;
            usefulStick++;
            if ( target == mainTarget || start == mount - 1 )
            {
                return 0;
            }
            start = quick[start] - 1;
        }
    }
    xg++;
    return 0;
}

int main()
{
    int i, j, target, tempLength, temp;
    while(1)
    {
        scanf("%d", &mount);
        if ( mount == 0 )
        {
            break;
        }
        length = 0;
        memset(sticks, 0, sizeof(sticks));
        memset(quick, 0, sizeof(quick));
        for ( i = 0; i < mount; i++)
        {
            scanf("%d", &sticks[i]);
            length += sticks[i];
        }
        qsort(sticks, mount, sizeof(int), comp);
        /*printf("\n");
        for ( i = 0; i < mount; i++ )
        {
            printf("%3d ", sticks[i]);
        }
        printf("\n");*/
        target = 0;
        temp = sticks[mount-1];
        sticks[mount-1] = -1;
        for ( i = 0; i < mount; i++ )
        {
            if ( sticks[i] > sticks[i+1] )
            {
                for ( j = target; j <= i; j++ )
                {
                    quick[j] = i+1;
                }
                target = i+1;
            }
        }
        sticks[mount-1] = temp;

        /*for ( i = 0; i < mount; i++ )
        {
            printf("%3d ", quick[i]);
        }
        printf("\n");*/
        for ( target = sticks[0]; target <= length; target++)
        {
            if ( length % target != 0 )
            {
                continue;
            }
            //printf("[%d] ", target);
            memset(used, 0, sizeof(used));
            usedIndex = 0;
            if (search(target, target, 0, mount, length) == 1)
            {
                printf("%d\n", target);
                break;
            }
        }
    }
    /*printf("%d %d %d %d %d %d %d %d\n", xa, xb, xbb, xc, xd, xe, xf, xg);
    printf("%d %d %d %d\n", fa, fb, fc, fd);*/
}
