/*
��Ҫ˼�룺
1.ѡȡ��ǰ�����׼��������ѡȡ����ĵ�һ������ 
2.����ǰ���仮��Ϊ�����Ի�׼��Ϊ�е㣬���С�������ұߴ��������������� 
3.�ٶ��������������ظ�һ��������ֱ��������ֻ��һ���� 
�ܵ���������ʵÿ�β������ǰѻ�׼���ŵ��Լ�Ӧ�ô��ڵ�λ�� 
*/
#include <iostream>
using namespace std;

int Adjust_array(int *a,int l,int r){
    int i=l,j=r;
    int x=a[l];     //��׼ֵ 
    while(i<j){
        while(j>i&&a[j]>=x){
            j--;    
        }
        if(i<j){
            a[i]=a[j];
            i++;    
        }
        while(i<j&&a[i]<x){   //<=
            i++;    
        }
        if(i<j){
            a[j]=a[i];
            j--;    
        }
    }
    a[i]=x;
    return i;
}

void Quick(int *a,int l,int r){
    if(l<r){    //�������� 
        int base=Adjust_array(a,l,r);
        Quick(a,l,base-1);
        Quick(a,base+1,r);  
    }
    
}

void Print(int *a,int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<"  ";    
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];    
    }
    Print(a,n);
    Quick(a,0,n-1);
    Print(a,n);
    system("pause");
    return 0;
}

/*
http://blog.csdn.net/morewindows/article/details/6684558�еļ��棺

void quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1); // �ݹ����   
        quick_sort(s, i + 1, r);  
    }  
}  

ע1���е����������м������Ϊ��׼���ģ�Ҫʵ���������ǳ����㣬
     ֱ�ӽ��м�����͵�һ�������н����Ϳ����ˡ�
*/ 


