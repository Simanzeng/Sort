//ϣ������
#include <iostream>
#include<vector>

using namespace std;

void shellsort(vector<int> &vec)
{
    int n=vec.size(),j;
    for(int d=n/2;d>=1;d=d/2)       //ȷ���̶�����ֵd
        for(int i=d;i<n;++i)
        {
            int temp=vec[i];                //ע��
            for(j=i-d;(j>=0)&&(vec[j]>temp);j=j-d)
            {
                vec[j+d]=vec[j];
            }
            vec[j+d]=temp;
        }

}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    shellsort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}
