#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct device {
	int b, p, minp;
};
typedef struct device Device;

int comp(const void *a, const void *b) {
    Device *A = (Device *)a;
    Device *B = (Device *)b;
	return A->b - B->b;
}

int main(int argc, char *argv[])
{
	int t = 0, w = 0;
	int line = 0;
	Device devices[128][128];
	int inputNum;
	int denum;
	int mi[128];
	int i, j, k, z;
	int minMaxBandwidth = 0;
	int maxBandwidth[128];
	int lastBandwidth, tempPrice;
	int hasDev[128];
    int tempB, tempP;
	double maxBP, maxBPs[128*128];
	scanf("%d", &t);
	for ( i = 0; i < t; i++) {
        scanf("%d", &denum);
        for ( j = 0; j < denum; j++ ) {
            scanf("%d", &mi[j]);
            for ( k = 0; k < mi[j]; k++ ) {
                scanf("%d %d", &(devices[j][k].b), &(devices[j][k].p));
            }
            qsort( devices[j], mi[j], sizeof(Device), comp);
            devices[j][mi[j]-1].minp = devices[j][mi[j]-1].p;
            for ( k = mi[j]-2; k >= 0; k-- ) {
                if ( devices[j][k].p < devices[j][k+1].minp ) {
                    devices[j][k].minp = devices[j][k].p;
                } else {
                    devices[j][k].minp = devices[j][k+1].minp;
                }
            }
        }
        for ( j = 0; j < denum; j++ ) {
            for( k = 0; k < mi[j] ; k++ )
            {
                printf("%d %d %d\t", devices[j][k].b, devices[j][k].p, devices[j][k].minp);
            }
            printf("\n");
        } 
        for( j = 0 ; j < denum ; j++ )
        {
            for( k = 0 ; k < mi[j] ; k++ )
            {
                tempB = devices[j][k].b;
                tempP = devices[j][k].p
            }
        }
        
		//printf("%.3lf\n", maxBP);
	}
}
