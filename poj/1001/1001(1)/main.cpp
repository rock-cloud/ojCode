#include<iostream>
#define max 1000
using namespace std;

int length(int num)//找出num的整数部分的位数
{
    int k=0;
    while(num/10!=0)
    {
        k++;
        num/=10;
    }
    return k+1;
}
void multiply(int result[],int &resultlen,int digit[],int k);

int main()
{
    double r; //存放去掉小数点后的数
    int n;
    int dot;//小数部分的位数
    int i,j,k,m;
    int digit[max];
    int result[max];
    int resultlen;
    bool flag=true;
    while(cin>>r>>n)
    {
        i=length((int)r);//当前数的整数部分有i位
        if(i==1)//整数部分只有一位
        {
            dot=4;
            r=r*10000;
        }
        else
        {
            dot=3;
            r=r*1000;
        }
        long int number=(long int)r;

        dot=dot*n; //最终结果的小数点位数
        if(number==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(i=0; i<max; i++)
        {
            digit[i]=0;
            result[i]=0;
        }
        k=length(number);//无小数点的数的长度
        resultlen=k;

        //将当前要计算的无小数点的底数按从低位到高位放进digit[]和result[]中
        for(i=0; i<k; i++)
        {
            digit[i]=result[i]=number%10;
            number/=10;
        }
        for(i=0; i<n-1; i++)
            multiply(result,resultlen,digit,k);
        i=0;
        while(i<dot)//从后向前去掉小数点后末尾的零
        {
            if(result[i]!=0)break;
            i++;
        }
        if(i==dot)flag=false;//结果是整数,没有小数点
        else
        {
            flag=true;
            m=i;
        }

        if(resultlen>dot)//有整数部分
        {
            for(i=resultlen-1; i>=dot; i--) //整数部分循环
                cout<<result[i];
            if(flag)
            {
                cout<<".";
                for(i=dot-1; i>=m; i--)cout<<result[i];
            }
        }
        else
        {
            if(flag)
            {
                cout<<".";
                for(i=dot-1; i>=m; i--)cout<<result[i];
            }
        }
        cout<<endl;
    }

    return 0;
}

void multiply(int result[],int &resultlen,int digit[],int k)
{
    //k表示当前底数的位数，resultlen表示当前结果的位数
    int i,j,len,re[max];
    for(i=0; i<max; i++) re[i]=0;
    for(i=0; i<k; i++) //乘数位数循环
        for(j=0; j<resultlen; j++) //被乘数位数循环
        {
            re[i+j]+=result[j]*digit[i];
            re[i+j+1]+=re[i+j]/10;
            re[i+j]%=10;
        }
    len=resultlen+k;//一个resultlen位的数与一个k位的数相乘，结果最大位数为len,最小位数为len-1;
    if(re[len-1]==0)len--;
    resultlen=len;
    for(i=0; i<len; i++)
    {
        result[i]=re[i];
    }
}
