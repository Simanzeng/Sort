///�鲢����:
/*�鲢��Merge�������ǽ����������������ϣ������ϲ���һ���µ���������Ѵ��������з�Ϊ���ɸ�����������У��ٰ�
����������кϲ�Ϊ�����������С��鲢�������ȶ�������.����ȵ�Ԫ�ص�˳�򲻻�ı�,��Ҳ�����ȿ����������Ƶĵط�.*/
///�����Ƕ�·�鲢�����㷨
#include <iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &vec1,vector<int> &vec2,int s,int m,int t)    //ʵ��һ�ι鲢����ĺ���
{
    int i=s;    //��һ���������еĿ�ʼλ��
    int j=m+1;  //�ڶ����������еĿ�ʼλ��
    int k=s;    //�������кϲ������������vec2�Ŀ�ʼλ��
    while((i<=m)&&(j<=t))     //��i��j���ڶ���Ҫ�ϲ����������еĲ���ʱ
    {
        if(vec1[i]<vec1[j])   //ɸѡ��������С�������ںϲ������������vec2����Ӧλ��
        {
            vec2[k++]=vec1[i++];
        }
        else    //ɸѡ��������С�������ںϲ������������vec2����Ӧλ��
        {
            vec2[k++]=vec1[j++];
        }
    }
    if(i<=m)    //��������ʣ��Ĳ��ַ���ϲ������������vec2��
       while(i<=m)
       {
            vec2[k++]=vec1[i++];
       }
    else     //��������ʣ��Ĳ��ַ���ϲ������������vec2��
        while(j<=t)
        {
            vec2[k++]=vec1[j++];
        }
    for(int n=s;n<=t;++n)      //�Ѻϲ������������vec2��ֵ������vec1
        vec1[n]=vec2[n];
}

void MergeSort(vector<int> &vec1,vector<int> &vec2,int s,int t)
{
    if(s<t)
    {
        int m=(s+t)/2;
        MergeSort(vec1,vec2,s,m);     //�ݹ����MergeSort������ʹvec1[s]~vec1[m]�鲢�������vec1[s]~vec1[m]
        MergeSort(vec1,vec2,m+1,t);   //�ݹ����MergeSort������ʹvec1[m+1]~vec1[t]�鲢�������vec1[m+1]~vec1[t]
        Merge(vec1,vec2,s,m,t);       //����Merge�������ϲ����������vec1[s]~vec1[m]��vec1[m+1]~vec1[t]
    }
}


int main()
{
    vector<int> vec1;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)        //��������
        vec1.push_back(n);
    vector<int>::size_type s=vec1.size();     //����vec1�ĳ��ȣ���Ԫ�صĸ���
    vector<int> vec2(s,0);        //�������s��ֵΪ0������vec2��
    MergeSort(vec1,vec2,0,s-1);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec1.begin();iter!=vec1.end();++iter)    //�������
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
