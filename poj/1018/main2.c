#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct device {
	int bandwidth, price, device;
};
typedef struct device Device;

int comp(const void *a, const void *b) {
	Device *A = (Device *)a;
	Device *B = (Device *)b;
	if ( A->bandwidth == B->bandwidth ) {
		if ( A->price == B->price ) {
			return A->device - B->device;
		} else {
			return A->price - B->price;
		}
	} else {
		return A->bandwidth - B->bandwidth;
	}
}
int denum;
double maxAns = 0.0; 
Device devices[128][128];
int mi[128];
void comput(int minb, int p, int dev) {
	int i, j;
	double tempBP;
	int tempb;
	for ( i = 0; i < mi[dev]; i++ ) {
		for ( j = 0; j < dev && i != 0; j++ ) {
			printf("\t\t");
		}
		printf("%d %d %d\t", devices[dev][i].bandwidth, devices[dev][i].price, dev);
		if ( devices[dev][i].bandwidth < minb ) {
			tempb = devices[dev][i].bandwidth;
		} else {
			tempb = minb;
		} 
		if ( dev >= denum-1 ) {
			tempBP = tempb*1.0/(p+devices[dev][i].price);
			if ( tempBP > maxAns ) {
				maxAns = tempBP;	
			}
			printf(" %d:%.3lf\n", minb, maxAns);
		} else {
			comput( tempb, p+devices[dev][i].price, dev+1);
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	int t = 0, w = 0;
	int line = 0;
	int inputNum;
	int i, j, k, z;
	int minMaxBandwidth = 0;
	int maxBandwidth[128];
	int lastBandwidth, tempPrice;
	int hasDev[128];
	double maxBP, maxBPs[128*128];
	scanf("%d", &t);
	for ( i = 0; i < t; i++) {
		scanf("%d", &denum);
		memset(devices, 0, sizeof(devices));
		memset(maxBandwidth, 0, sizeof(maxBandwidth));
		inputNum = 0;
		minMaxBandwidth = -1;
		for ( j = 0; j < denum; j++) {
			scanf("%d", &mi[j]); 
			for ( k = 0; k < mi[j]; k++ ) {
				scanf("%d %d", &devices[j][k].bandwidth, &devices[j][k].price);
			}
		}
		comput(9999999, 0, 0);
	}
}

