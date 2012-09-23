#include <iostream>
#include <set>
#include <algorithm>
#include  <stdio.h>
using namespace std;

struct Device
{
    int nChoice;
    int quality[102][2];
};

int main()
{
    int ncase;
    cin >> ncase;
    while ( ncase-- ){

        int n;
        double ratio = 0;
        set <int> intSet;
        set <int>::iterator sp;
        cin >> n;
        Device *s = new Device[n];
        
        for( int i = 0; i < n; i++ ) {
            cin >> s[i].nChoice;
            for( int j = 0; j < s[i].nChoice; j++ ){
                cin >> s[i].quality[j][0] >> s[i].quality[j][1];
                intSet.insert( s[i].quality[j][0] );
            }
        } 
        
        for( sp = intSet.begin(); sp != intSet.end(); sp++ ){
            int totalPrice = 0;
            int minBand = *sp;
            for( int i = 0; i < n; i++){//选每一种产品
                int min = 100000;
                for( int j = 0; j < s[i].nChoice; j++ ){
                    if( s[i].quality[j][0] >= minBand && min > s[i].quality[j][1] )
                        min = s[i].quality[j][1];
                }
                totalPrice += min;               
            } 
            if( ratio < (double) (minBand) / (double) totalPrice ){
                ratio = (double) (minBand) / (double) totalPrice;            
            }
        }
         printf( "%.3lf\n", ratio );

        delete s;
    }
    system("pause");
    return 0;
}
