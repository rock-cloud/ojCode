#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sum, f;
    int i;
    for ( i = 0, sum = 0.0; i < 12; i++)
    {
        scanf("%f", &f);
        sum += f;
    }
    printf("$%.2f\n", sum/12.0);
    return 0;
}
