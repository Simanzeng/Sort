///堆排序
#include <iostream>
#include<vector>

using namespace std;

//整理节点
void MinHeapify(vector<int> &arry,int size,int element)
{
    int lchild=element*2+1,rchild=lchild+1;//左右子树
    while(rchild<size)//子树均在范围内
    {
        if(arry[element]<=arry[lchild]&&arry[element]<=arry[rchild])   //如果比左右子树都小，完成整理
        {
            return;
        }
        if(arry[lchild]<=arry[rchild])//如果左边最小
        {
            swap(arry[element],arry[lchild]);//把左面的提到上面
            element=lchild;//循环时整理子树
        }
        else//否则右面最小
        {
            swap(arry[element],arry[rchild]);//同理
            element=rchild;
        }
        lchild=element*2+1;
        rchild=lchild+1;//重新计算子树位置
    }
    if((lchild<size)&&(arry[lchild]<arry[element]))//只有左子树且子树小于自己
    {
        swap(arry[lchild],arry[element]);
    }
    return;
}

void HeapSort(vector<int> &arry)
{
    int size=arry.size();
    int i;
    for(i=size-1;i>=0;i--)//从子树开始整理树
    {
        MinHeapify(arry,size,i);
    }
    while(size>0)//拆除树
    {
        swap(arry[size-1],arry[0]);//将根（最小）与数组最末交换
        size--;//树大小减小
        MinHeapify(arry,size,0);//整理树
    }
    return;
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    HeapSort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.end()-1;iter!=vec.begin()-1;--iter)   //输出vec中的值
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
