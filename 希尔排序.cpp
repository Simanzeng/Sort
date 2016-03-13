//希尔排序
#include <iostream>
#include<vector>

using namespace std;

void shellsort(vector<int> &vec)
{
    int n=vec.size(),j;
    for(int d=n/2;d>=1;d=d/2)       //确定固定增量值d
        for(int i=d;i<n;++i)
        {
            int temp=vec[i];                //注意
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
    cout<<"请输入一组整数（按热键Ctrl+Z结束）：";
    while(cin>>n)
        vec.push_back(n);
    shellsort(vec);
    cout<<"这组整数从小到大的排序为：";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}
