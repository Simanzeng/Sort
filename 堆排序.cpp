///������
#include <iostream>
#include<vector>

using namespace std;

//����ڵ�
void MinHeapify(vector<int> &arry,int size,int element)
{
    int lchild=element*2+1,rchild=lchild+1;//��������
    while(rchild<size)//�������ڷ�Χ��
    {
        if(arry[element]<=arry[lchild]&&arry[element]<=arry[rchild])   //���������������С���������
        {
            return;
        }
        if(arry[lchild]<=arry[rchild])//��������С
        {
            swap(arry[element],arry[lchild]);//��������ᵽ����
            element=lchild;//ѭ��ʱ��������
        }
        else//����������С
        {
            swap(arry[element],arry[rchild]);//ͬ��
            element=rchild;
        }
        lchild=element*2+1;
        rchild=lchild+1;//���¼�������λ��
    }
    if((lchild<size)&&(arry[lchild]<arry[element]))//ֻ��������������С���Լ�
    {
        swap(arry[lchild],arry[element]);
    }
    return;
}

void HeapSort(vector<int> &arry)
{
    int size=arry.size();
    int i;
    for(i=size-1;i>=0;i--)//��������ʼ������
    {
        MinHeapify(arry,size,i);
    }
    while(size>0)//�����
    {
        swap(arry[size-1],arry[0]);//��������С����������ĩ����
        size--;//����С��С
        MinHeapify(arry,size,0);//������
    }
    return;
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    HeapSort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.end()-1;iter!=vec.begin()-1;--iter)   //���vec�е�ֵ
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
