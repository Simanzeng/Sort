///ð������
#include <iostream>
#include<vector>

using namespace std;

void bubbling_sort(vector<int> &vec)
{
    vector<int>::size_type n=vec.size();
    for(vector<int>::size_type i=1;i!=n;++i)   //����i����Ƚϵ�����
    {
        for(vector<int>::size_type j=0;j!=n-i;++j)     //����j����ÿ�������ȽϵĴ���
        {
            if(vec[j]>vec[j+1])      //�Ѵ����������
            {
                int temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    bubbling_sort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //���vec�е�ֵ
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
