#include<iostream>
#define max 1000
using namespace std;

int length(int num)//�ҳ�num���������ֵ�λ��
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
    double r; //���ȥ��С��������
    int n;
    int dot;//С�����ֵ�λ��
    int i,j,k,m;
    int digit[max];
    int result[max];
    int resultlen;
    bool flag=true;
    while(cin>>r>>n)
    {
        i=length((int)r);//��ǰ��������������iλ
        if(i==1)//��������ֻ��һλ
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

        dot=dot*n; //���ս����С����λ��
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
        k=length(number);//��С��������ĳ���
        resultlen=k;

        //����ǰҪ�������С����ĵ������ӵ�λ����λ�Ž�digit[]��result[]��
        for(i=0; i<k; i++)
        {
            digit[i]=result[i]=number%10;
            number/=10;
        }
        for(i=0; i<n-1; i++)
            multiply(result,resultlen,digit,k);
        i=0;
        while(i<dot)//�Ӻ���ǰȥ��С�����ĩβ����
        {
            if(result[i]!=0)break;
            i++;
        }
        if(i==dot)flag=false;//���������,û��С����
        else
        {
            flag=true;
            m=i;
        }

        if(resultlen>dot)//����������
        {
            for(i=resultlen-1; i>=dot; i--) //��������ѭ��
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
    //k��ʾ��ǰ������λ����resultlen��ʾ��ǰ�����λ��
    int i,j,len,re[max];
    for(i=0; i<max; i++) re[i]=0;
    for(i=0; i<k; i++) //����λ��ѭ��
        for(j=0; j<resultlen; j++) //������λ��ѭ��
        {
            re[i+j]+=result[j]*digit[i];
            re[i+j+1]+=re[i+j]/10;
            re[i+j]%=10;
        }
    len=resultlen+k;//һ��resultlenλ������һ��kλ������ˣ�������λ��Ϊlen,��Сλ��Ϊlen-1;
    if(re[len-1]==0)len--;
    resultlen=len;
    for(i=0; i<len; i++)
    {
        result[i]=re[i];
    }
}
