#include <stdio.h>
/*#include <time.h>*/
#include <string.h>
int main()
{
    int arr[15];
    int mod = 0;
    memset(arr,0,15*sizeof(int));
    while(1)
    {
        int k,m=0;
        scanf("%d",&k);
        if(k==0)break;
        if(arr[k]==0)
        {
            for ( m = k+1, mod = 0; ; m = m+mod*k+(1-mod), mod = 1- mod )
            {
                int bad=k*2,now=0;
                while(1)
                {
                    now=(now+m-1)%bad+1;
                    if(now>k)
                    {
                        bad--;
                        now--;
                    }
                    else
                        break;
                }
                if(bad==k){arr[k]=m;break;}
            }
        }
        printf("%d\n",arr[k]);
    }
}
