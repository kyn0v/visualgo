#include <iostream>
using namespace std;
//归并排序，即先递归分解数列，再合并数列

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
}//合并有序数列a[first...mid]与a[mid+1...last]
//这里的temp为共用的临时数组，避免了每次调用函数时动态申请空间费时 
 
void  Merge(int *a,int first,int last,int *temp){
    if(first<last){
        int mid=(first+last)/2;
        Merge(a,first,mid,temp);
        Merge(a,mid+1,last,temp);
        Merge_part(a,first,mid,last,temp);    
    }
}//递归分解数组 

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

//另：参照以下文章（写的很详细） 
//http://blog.csdn.net/morewindows/article/details/6678165/
