#include <iostream>
using namespace std;
//�鲢���򣬼��ȵݹ�ֽ����У��ٺϲ�����

void Merge_part(int *a,int first,int mid,int last,int *temp){
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0;
    while(i<=m&&j<=n){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];    
        }
        else{
            temp[k++]=a[j++]; 
        }
    }
    while(i<=m){
        temp[k++]=a[i++];    
    }
    while(j<=n){
        temp[k++]=a[j++];
    }
    for(i=0;i<k;i++){
        a[first+i]=temp[i];    
    }
}//�ϲ���������a[first...mid]��a[mid+1...last]
//�����tempΪ���õ���ʱ���飬������ÿ�ε��ú���ʱ��̬����ռ��ʱ 
 
void  Merge(int *a,int first,int last,int *temp){
    if(first<last){
        int mid=(first+last)/2;
        Merge(a,first,mid,temp);
        Merge(a,mid+1,last,temp);
        Merge_part(a,first,mid,last,temp);    
    }
}//�ݹ�ֽ����� 

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
    int temp[n];
    for(int i=0;i<n;i++){
        cin>>a[i];    
    }
    Print(a,n);
    Merge(a,0,n-1,temp);
    Print(a,n);
    system("pause");
    return 0;
}

//�������������£�д�ĺ���ϸ�� 
//http://blog.csdn.net/morewindows/article/details/6678165/
