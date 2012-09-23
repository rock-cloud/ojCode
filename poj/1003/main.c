#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float f, sum;
    for ( ; ; )
    {
        scanf("%f", &f);
        if ( f == 0 )
        {
            break;
        }
        else
        {
            sum = 0.0;
            for ( i = 1; sum < f; i++)
            {
                sum += 1.0/(i+1);
            }
            printf("%d card(s)\n", i-1);
        }
    }
    return 0;
}
