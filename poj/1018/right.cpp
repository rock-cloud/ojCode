#include<iostream>  
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include<algorithm>  
#include<iomanip>  
using namespace std;  
class info  
{  
    public:  
        int B;   //带宽  
        double P;   //价格  
        int id;  //设备号码  
};  
int cmp(const void* a,const void* b)  
{  
    info* x=(info*)a;  
    info* y=(info*)b;  
    if((x->B)==(y->B))   //当带宽相等时  
    {  
        if((x->P)==(y->P))   //当价格也相等时  
            return (x->id)-(y->id);   //以编号为第三优先升序排序  
        return (x->P)-(y->P);   //以价格为第二优先升序排序  
    }  
    return (x->B)-(y->B);   //以带宽为第一优先升序排序  
}  
double max(double a,double b)  
{  
    return a>b?a:b;  
}  
int main(int i,int j)  
{  
    int test;  
    cin>>test;  
    for(int t=1;t<=test;t++)  
    {  
        int n;  //设备数  
        int m=0;  //生产商总数  
        cin>>n;  
        int* MaxB=new int[n+1];  //各种设备对应的带宽最大值  
        info* dev=new info[100*100+1];     //记录所有厂家生产的产品信息  
        int pd=0;  //dev[]指针  
        /*Input*/  
        for(i=1;i<=n;i++)  
        {  
            int mi;  
            cin>>mi;  
            m+=mi;  
            MaxB[i]=-1;  
            for(j=1;j<=mi;j++)  
            {  
                pd++;  
                cin>>dev[pd].B>>dev[pd].P;  
                dev[pd].id=i;  
                MaxB[i]=max(MaxB[i],dev[pd].B);  
            }  
        }  
        /*Qsort*/  
        qsort(dev,m+1,sizeof(info),cmp);  
        /*Enum*/  
        for ( i = 1; i <= pd; i++ ) 
        {
            cout<<i<<" "<<dev[i].B<<" "<<dev[i].P<<" "<<dev[i].id<<endl;
        }
        bool flag=false;  
        double ans=0;  // B/P的最大值  
        for(i=1;i<=m-(n-1);i++)  //枚举所有设备带宽的最小带宽B  
        {                        //m-(n-1)是剪枝，因为当设备数>生产商数时就不必枚举了  
            bool* vist=new bool[n+1];  
            memset(vist,false,sizeof(bool)*(n+1));  
            vist[ dev[i].id ]=true;  
            double price=dev[i].P;  //设备总价  
            int count=1;   //计数器，记录已经选取的设备个数  
            for(j=i+1;j<=m;j++)  
            {  
                if(vist[ dev[j].id ])  
                    continue;  
                if(dev[i].B > MaxB[ dev[j].id ])  //剪枝  
                {  
                    flag=true;  //当前枚举的 "所有设备带宽的最小带宽Bi" 比 "设备j的最大带宽MaxBj" 要大  
                    break;      //说明当前Bi已经越界，无需继续往后枚举  
                }  
                vist[ dev[j].id ]=true;  
                price+=dev[j].P;  
                count++;  
            }  
            if(flag || count<n)  
                break;  
            ans=max(ans,(dev[i].B/price));  
        }  
        cout<<fixed<<setprecision(3)<<ans<<endl;  
        delete MaxB;  
        delete dev;  
    }  
    return 0;  
}  
