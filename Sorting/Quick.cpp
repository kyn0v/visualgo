/*
主要思想：
1.选取当前区间基准数（这里选取区间的第一个数） 
2.将当前区间划分为两个以基准数为中点，左边小于它、右边大于它的两个区间 
3.再对左右两个区间重复一、二步，直到各区间只有一个数 
总的来看，其实每次操作就是把基准数放到自己应该处于的位置 
*/
#include <iostream>
using namespace std;

int Adjust_array(int *a,int l,int r){
    int i=l,j=r;
    int x=a[l];     //基准值 
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
    if(l<r){    //结束条件 
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
http://blog.csdn.net/morewindows/article/details/6684558中的简洁版：

void quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1); // 递归调用   
        quick_sort(s, i + 1, r);  
    }  
}  

注1，有的书上是以中间的数作为基准数的，要实现这个方便非常方便，
     直接将中间的数和第一个数进行交换就可以了。
*/ 


