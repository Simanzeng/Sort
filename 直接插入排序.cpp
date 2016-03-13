//直接插入排序
#include <iostream>
#include<vector>

using namespace std;

void insort(vector<int> &vec)
{
    vector<int>::size_type n=vec.size();
    for(vector<int>::size_type i=1;i!=n;++i)   //下标从1开始，因为vec[0]一个数据没有可比性
    {
        vector<int>::size_type j=i-1;
        int s=vec[i];      //设置监视硝s，并复值vec[i]
        for(;(vec[j]>s)&&(j>=0);--j)  //vec[i]前面的数逐个与vec[i]比较，使小的数前移
        {
            vec[j+1]=vec[j];
        }
        vec[j+1]=s;   //在比vec[i]小的数的后面插入s,即vec[i]
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    insort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}
