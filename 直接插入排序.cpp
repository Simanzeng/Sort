//ֱ�Ӳ�������
#include <iostream>
#include<vector>

using namespace std;

void insort(vector<int> &vec)
{
    vector<int>::size_type n=vec.size();
    for(vector<int>::size_type i=1;i!=n;++i)   //�±��1��ʼ����Ϊvec[0]һ������û�пɱ���
    {
        vector<int>::size_type j=i-1;
        int s=vec[i];      //���ü�����s������ֵvec[i]
        for(;(vec[j]>s)&&(j>=0);--j)  //vec[i]ǰ����������vec[i]�Ƚϣ�ʹС����ǰ��
        {
            vec[j+1]=vec[j];
        }
        vec[j+1]=s;   //�ڱ�vec[i]С�����ĺ������s,��vec[i]
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    insort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}
