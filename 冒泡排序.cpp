///冒泡排序
#include <iostream>
#include<vector>

using namespace std;

void bubbling_sort(vector<int> &vec)
{
    vector<int>::size_type n=vec.size();
    for(vector<int>::size_type i=1;i!=n;++i)   //变量i代表比较的趟数
    {
        for(vector<int>::size_type j=0;j!=n-i;++j)     //变量j代表每趟两两比较的次数
        {
            if(vec[j]>vec[j+1])      //把大的数往后移
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
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    bubbling_sort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //输出vec中的值
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
