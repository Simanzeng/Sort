///��������
#include <iostream>
#include<vector>

using namespace std;


int maxbit(vector<int> &vec) //���������������ݵ����λ��
{
    int n=vec.size();
    int d = 1; //��������λ��
    int p =10;
    for(int i = 0;i < n; ++i)
    {
        while(vec[i]>= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(vector<int> &vec) //��������
{
    int n=vec.size();
    int d = maxbit(vec);
    int * tmp = new int[n];
    int * count = new int[10]; //������
    int i,j,k;
    int radix = 1;
    for(i = 1; i<= d;i++) //����d������
    {
        for(j = 0;j < 10;j++)
            count[j] = 0; //ÿ�η���ǰ��ռ�����
        for(j = 0;j < n; j++)
        {
            k = (vec[j]/radix)%10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for(j = 1;j < 10;j++)
            count[j] = count[j-1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j = n-1;j >= 0;j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (vec[j]/radix)%10;
            tmp[count[k]-1] = vec[j];
            count[k]--;
        }
        for(j = 0;j < n;j++) //����ʱ��������ݸ��Ƶ�data��
            vec[j] = tmp[j];
        radix = radix*10;
    }
    delete [] tmp;
    delete [] count;
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    radixsort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //���vec�е�ֵ
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
