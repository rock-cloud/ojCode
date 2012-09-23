#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
int main(int argc, char *argv[])
{
    long idx, num, i, length, base;
    base = 9;
    for ( i = 1; i < 8; i++) {
        printf("%ld %ld\n", i, base);
        base += (pow(10,i+1)-pow(10,i))*(i+1);
    }
}
