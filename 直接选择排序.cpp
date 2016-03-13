///简单直接选择排序
#include <iostream>
#include<vector>

using namespace std;

void  OptionSort(vector<int> &vec)
{
    int n=vec.size();  //这组数的总长度，既有多少个数
    int i,j,k;      //k为记录这组数中剩余无序部分的最小数的下标
    for(i=0;i!=n-1;++i)   //从首元素开始，共遍历n-1次
    {
        k=i;     //k初始化为剩余组数中无序部分的第一个数的下标
        for(j=i+1;j!=n;++j)    //从剩余组数中无序部分中开始寻找最小的数
        {
            if(vec[k]>vec[j])
            {
                k=j;      //令k等于比vec[k]更小的数的下标
            }
        }
        int temp=vec[i];         //剩余组数中无序部分中最小的数与剩余组数中无序部分的第一个数置换
        vec[i]=vec[k];
        vec[k]=temp;
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    OptionSort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //输出vec中的值
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
