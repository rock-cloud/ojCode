#include <stdio.h>
int main()
{
    int p, e, i, d;
    int num, index;
    for ( index = 1; ; index++)
    {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if ( p == -1 && e == -1 && i == -1 && d == -1 )
        {
            return 0;
        }
        num = (5544*p + 14421*e + 1288*i-d+21252)%21252;
        if ( num == 0 )
        {
            num = 21252;
            printf("Case %d: the next triple peak occurs in %d days.\n", index, num);
        }
        else
        {
            printf("Case %d: the next triple peak occurs in %d days.\n", index, num);
        }
    }
}
