///��ֱ��ѡ������
#include <iostream>
#include<vector>

using namespace std;

void  OptionSort(vector<int> &vec)
{
    int n=vec.size();  //���������ܳ��ȣ����ж��ٸ���
    int i,j,k;      //kΪ��¼��������ʣ�����򲿷ֵ���С�����±�
    for(i=0;i!=n-1;++i)   //����Ԫ�ؿ�ʼ��������n-1��
    {
        k=i;     //k��ʼ��Ϊʣ�����������򲿷ֵĵ�һ�������±�
        for(j=i+1;j!=n;++j)    //��ʣ�����������򲿷��п�ʼѰ����С����
        {
            if(vec[k]>vec[j])
            {
                k=j;      //��k���ڱ�vec[k]��С�������±�
            }
        }
        int temp=vec[i];         //ʣ�����������򲿷�����С������ʣ�����������򲿷ֵĵ�һ�����û�
        vec[i]=vec[k];
        vec[k]=temp;
    }
}

int main()
{
    vector<int> vec;
    int n;
    cout<<"������һ�����������ȼ�Ctrl+Z��������";
    while(cin>>n)
        vec.push_back(n);
    OptionSort(vec);
    cout<<"����������С���������Ϊ��";
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)        //���vec�е�ֵ
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
