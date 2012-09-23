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

int main(int argc, char *argv[])
{
	int t = 0, w = 0;
	int line = 0;
	Device devices[128*128];
	int inputNum;
	int denum;
	int mi[128];
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
				scanf("%d %d", &devices[inputNum].bandwidth, &devices[inputNum].price);
				devices[inputNum].device = j;
				if( devices[inputNum].bandwidth > maxBandwidth[j] ) { 
					maxBandwidth[j] = devices[inputNum].bandwidth; 
				}                
				inputNum++;
			}
			if ( minMaxBandwidth == -1 || maxBandwidth[j] < minMaxBandwidth ) {
				minMaxBandwidth = maxBandwidth[j];
			}
		}
		qsort(devices, inputNum, sizeof(Device), comp);        
		        for ( j = 0; j < inputNum; j++) {
		            printf("%d: %d %d %d\n", j, devices[j].bandwidth, devices[j].price, devices[j].device);
		        }
		lastBandwidth = -1;
		maxBP = 0.0;
		memset(maxBPs, 0, sizeof(maxBPs));
		w = 0;
		for ( j = 0; j < inputNum; j++) {
			for ( k = 0; k < denum; k++) {
				hasDev[k] = -1;
			}
			tempPrice = 0;
//			if ( devices[j].bandwidth == lastBandwidth ) {
//				continue;
//			}
			lastBandwidth = devices[j].bandwidth;
			if ( devices[j].bandwidth > minMaxBandwidth ) {
				break;
			}
//			      printf("lastBandwidth = %d\n", lastBandwidth);
			for ( k = j; k < inputNum; k++ ) {
//				printf("test %d:%d %d %d\n", k, devices[k].bandwidth, devices[k].price, devices[k].device);
				//if ( hasDev[devices[k].device] >= 0 && lastBandwidth*1.0/(tempPrice-devices[hasDev[devices[k].device]].price + devices[k].price) > maxBPs[w] ) {
				//	maxBPs[w] = lastBandwidth*1.0/(tempPrice-devices[hasDev[devices[k].device]].price + devices[k].price); 
				//	tempPrice -= devices[hasDev[devices[k].device]].price; 
                 //   tempPrice += devices[k].price;
				//	z = hasDev[devices[k].device];
//					   printf("drop %d:%d %d %d\n", z, devices[z].bandwidth, devices[z].price, devices[z].device);
				//	hasDev[devices[k].device] = k;
//				//	  printf("use %d:%d %d %d\n", k, devices[k].bandwidth, devices[k].price, devices[k].device);
				/*} else */if ( hasDev[devices[k].device] < 0 ) {
//					   printf("use %d:%d %d %d\n", k, devices[k].bandwidth, devices[k].price, devices[k].device);
					tempPrice += devices[k].price;
					maxBPs[w] = lastBandwidth*1.0/tempPrice; 
					hasDev[devices[k].device] = k;
				}
//				getchar();
			}
//			for ( k = 0; k < denum; k++) {
//			    printf("%d %d %d\t", devices[hasDev[k]].bandwidth, devices[hasDev[k]].price, devices[hasDev[k]].device);
//			}
//			printf("%.3lf %d", maxBPs[w], lastBandwidth);
//			printf("\n");
			w++;
		}
		for ( j = 0; j < w; j++) {
			if ( maxBPs[j] > maxBP ) {
				maxBP = maxBPs[j];
			}
		}
		printf("%.3lf\n", maxBP);
	}
}
