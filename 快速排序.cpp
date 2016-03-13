///��������  ��������죬�鲢�����֮������������� ������
/*����������Ҫ�����������A[0]����A[N-1]����������ѡȡһ�����ݣ�ͨ��ѡ������ĵ�һ��������Ϊ�ؼ����ݣ�
Ȼ�����б���С�������ŵ���ǰ�棬���б�����������ŵ������棬������̳�Ϊһ�˿�������ֵ��ע����ǣ�
����������һ���ȶ��������㷨��Ҳ����˵�������ͬ��ֵ�����λ��Ҳ������㷨����ʱ�����䶯��*/
#include <iostream>
#include<vector>

using namespace std;

void QuickSort(vector<int> &vec ,int m,int n)
{
    int i=m,j=n-1;    //��ÿ���׸�Ԫ�ظ�ֵ��i����ÿ��ĩβԪ�ظ�ֵ��j
    int k=vec[m];     //���û�׼ֵ
    for(;j!=i;--j)    ///�ѱȻ�׼ֵС�������ڻ�׼ֵ����ߣ��Ȼ�׼ֵ��������ڻ�׼ֵ���ұ�
    {
        if(k>vec[j])
        {
            vec[i]=vec[j];
            for(i=i+1;i!=j;++i)
            {
                if(k<vec[i])
                {
                    vec[j]=vec[i];
                    break;
                }
            }
            if(i==j)
                break;
        }
    }
    vec[j]=k;         //�ѻ�׼ֵ����vec[i]=vec[j]�ĵط�
    if(j>m+1)        ///ע�⣺�Էָ����ǰһ���ֵݹ����QuickSort����
    {
        QuickSort(vec,m,j);
    }
    if(j+1<n)         ///ע�⣺�Էָ���ĺ�һ���ֵݹ����QuickSort����
    {
        QuickSort(vec,j+1,n);
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)        //��������
        vec.push_back(n);
    QuickSort(vec,0,vec.size());
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)    //�������
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
