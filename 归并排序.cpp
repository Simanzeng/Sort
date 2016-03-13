///归并排序:
/*归并（Merge）排序法是将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列分为若干个有序的子序列，再把
有序的子序列合并为整体有序序列。归并排序是稳定的排序.即相等的元素的顺序不会改变,这也是它比快速排序优势的地方.*/
///以下是二路归并排序算法
#include <iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &vec1,vector<int> &vec2,int s,int m,int t)    //实现一次归并排序的函数
{
    int i=s;    //第一个有序数列的开始位置
    int j=m+1;  //第二个有序数列的开始位置
    int k=s;    //两个数列合并后的有序数列vec2的开始位置
    while((i<=m)&&(j<=t))     //当i和j都在二个要合并的有序数列的部分时
    {
        if(vec1[i]<vec1[j])   //筛选两部分最小的数放在合并后的有序数列vec2的相应位置
        {
            vec2[k++]=vec1[i++];
        }
        else    //筛选两部分最小的数放在合并后的有序数列vec2的相应位置
        {
            vec2[k++]=vec1[j++];
        }
    }
    if(i<=m)    //把两部分剩余的部分放入合并后的有序数列vec2中
       while(i<=m)
       {
            vec2[k++]=vec1[i++];
       }
    else     //把两部分剩余的部分放入合并后的有序数列vec2中
        while(j<=t)
        {
            vec2[k++]=vec1[j++];
        }
    for(int n=s;n<=t;++n)      //把合并后的有序数列vec2赋值给数列vec1
        vec1[n]=vec2[n];
}

void MergeSort(vector<int> &vec1,vector<int> &vec2,int s,int t)
{
    if(s<t)
    {
        int m=(s+t)/2;
        MergeSort(vec1,vec2,s,m);     //递归调用MergeSort函数，使vec1[s]~vec1[m]归并成有序的vec1[s]~vec1[m]
        MergeSort(vec1,vec2,m+1,t);   //递归调用MergeSort函数，使vec1[m+1]~vec1[t]归并成有序的vec1[m+1]~vec1[t]
        Merge(vec1,vec2,s,m,t);       //调用Merge函数，合并有序的数列vec1[s]~vec1[m]和vec1[m+1]~vec1[t]
    }
}


int main()
{
    vector<int> vec1;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)        //输入数组
        vec1.push_back(n);
    vector<int>::size_type s=vec1.size();     //计算vec1的长度，即元素的个数
    vector<int> vec2(s,0);        //定义包含s个值为0的向量vec2。
    MergeSort(vec1,vec2,0,s-1);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec1.begin();iter!=vec1.end();++iter)    //输出数组
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
