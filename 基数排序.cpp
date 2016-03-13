///基数排序
#include <iostream>
#include<vector>

using namespace std;


int maxbit(vector<int> &vec) //辅助函数，求数据的最大位数
{
    int n=vec.size();
    int d = 1; //保存最大的位数
    int p =10;
    for(int i = 0;i < n; ++i)
    {
        while(vec[i]>= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(vector<int> &vec) //基数排序
{
    int n=vec.size();
    int d = maxbit(vec);
    int * tmp = new int[n];
    int * count = new int[10]; //计数器
    int i,j,k;
    int radix = 1;
    for(i = 1; i<= d;i++) //进行d次排序
    {
        for(j = 0;j < 10;j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0;j < n; j++)
        {
            k = (vec[j]/radix)%10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1;j < 10;j++)
            count[j] = count[j-1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n-1;j >= 0;j--) //将所有桶中记录依次收集到tmp中
        {
            k = (vec[j]/radix)%10;
            tmp[count[k]-1] = vec[j];
            count[k]--;
        }
        for(j = 0;j < n;j++) //将临时数组的内容复制到data中
            vec[j] = tmp[j];
        radix = radix*10;
    }
    delete [] tmp;
    delete [] count;
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    radixsort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //输出vec中的值
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
