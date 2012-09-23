#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>
int main(int argc, char *argv[])
{
    int t, i, j, k, l;
    unsigned long idx;
    unsigned long len[6] = {0,45,9045,1395495,189414495,23939649495};
    unsigned long size[8] = {0,9,189,2889,38889,488889,5888889,68888889};
    unsigned long left, right, mid, before;
    unsigned long mod, targetNum, result;
    char targetNumStr[10];
    double leftfloat, tempfloat;
    scanf("%d", &t);
    for ( i = 0; i < t; i++) {
        scanf("%lu", &idx);
        for ( j = 0; j < 6; j++) {
            if ( idx <= len[j] ) {
//                printf("%d位数以内\n", j);
                idx -= len[j-1];
//                printf("除去所有%d位数还有%lu个\n", j-1, idx);
                break;
            }
        }
        left = 0;
        right = powl(10, j)-powl(10,j-1);
        tempfloat = (size[j-1]*2+j)*1.0/2/j;
//        printf("temp为%lf\n", tempfloat);
        leftfloat = sqrt(tempfloat*tempfloat+2.0*idx/j)-tempfloat;
//        printf("方程根为%lf\n", leftfloat);
        left = (int)(leftfloat-0.000001);
        /*for ( ; ; ) {
            printf("left %lu, right %lu\n", left, right);
            mid = (left+right)/2;
            printf("mid is %lu\n", mid);
            before = (size[j-1]+j+size[j-1]+j*mid)*mid/2;
            printf("before has %lu\n", before);
            if ( before < idx ) {
                left = mid;
            } else {
                right = mid;
            }
            if ( left >= right || left + 1 == right ) {
                printf("%lu == %lu\n", left, right);
                break;
            }
        } */
//        printf("在本区间内之前有%lu行\n", left);
        idx -= (size[j-1]+j+size[j-1]+j*left)*left/2;
//        printf("位于%d位数中的第%lu行，还剩余%lu个\n", j, left+1, idx);
        for ( k = 0; k < 8; k++ ) {
            if ( idx <= size[k] ) {
//                printf("%dnums\n", k);
                idx -= size[k-1];
//                printf("位于%lu行中的%d位数区，剩余%lu个\n", left+1, k, idx);
                break;
            }
        }
        mod = (idx-1) % k;
        if ( k == 1 ) {
            l = (int)idx;
        } else {
            l = (int)idx/k-1;
            if ( mod != k-1 ) {
                l++;
            }
        }
//        printf("位于目标数字的第[%lu]位，是%d位数的第%d个\n", mod, k, l);
        if ( k == 1 ) {
            targetNum = l;
        } else {
            targetNum = powl(10,k-1)+l;
        } 
//        printf("目标数字是%lu\n", targetNum);
        memset(targetNumStr, 0, sizeof(targetNumStr));
        sprintf(targetNumStr, "%lu", targetNum);
        printf("%c\n", targetNumStr[mod]);
    }
}
