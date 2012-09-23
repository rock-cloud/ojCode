#include  <stdio.h>
#include  <string.h>
#include  <math.h>
int main(int argc, char *argv[])
{
    unsigned long idx, baseidx, nheight;
    unsigned long num;
    int numLength, i, n;
    idx = 45;
    baseidx = 9;
    printf("%d, %11lu\n", 1, idx);
    for ( n = 2; n < 10; n++)
    {
        nheight = (unsigned long)(powl(10, n-1)*9);
        idx = idx + baseidx * nheight + ((unsigned long)n)*(1+nheight)*nheight/2;
        printf("%d, %20lu\n", n, idx);
        baseidx = baseidx + (unsigned long)n*nheight;
    }
}
