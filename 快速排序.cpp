///快速排序  此排序最快，归并排序次之，基数排序第三 、、、
/*快速排序：设要排序的数组是A[0]……A[N-1]，首先任意选取一个数据（通常选用数组的第一个数）作为关键数据，
然后将所有比它小的数都放到它前面，所有比它大的数都放到它后面，这个过程称为一趟快速排序。值得注意的是，
快速排序不是一种稳定的排序算法，也就是说，多个相同的值的相对位置也许会在算法结束时产生变动。*/
#include <iostream>
#include<vector>

using namespace std;

void QuickSort(vector<int> &vec ,int m,int n)
{
    int i=m,j=n-1;    //将每组首个元素赋值给i，将每组末尾元素赋值给j
    int k=vec[m];     //设置基准值
    for(;j!=i;--j)    ///把比基准值小的数放在基准值的左边，比基准值大的数放在基准值的右边
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
    vec[j]=k;         //把基准值放在vec[i]=vec[j]的地方
    if(j>m+1)        ///注意：对分割出的前一部分递归调用QuickSort函数
    {
        QuickSort(vec,m,j);
    }
    if(j+1<n)         ///注意：对分割出的后一部分递归调用QuickSort函数
    {
        QuickSort(vec,j+1,n);
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)        //输入数组
        vec.push_back(n);
    QuickSort(vec,0,vec.size());
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)    //输出数组
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
