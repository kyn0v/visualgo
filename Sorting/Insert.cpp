#include <iostream>
using namespace std;

void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Insert(int *a,int size){
	for(int i=1;i<size;i++){
		int temp=i;
		while(a[i]<a[i-1]){
			Swap(&a[i],&a[i-1]);
			i--;						
			if(i==0){		//此处的判断避免到a[0]时，仍继续向前比较 
				break;
			}	
		}
		i=temp;				//恢复i的值 
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
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Print(a,n);
	Insert(a,n);
	Print(a,n);
	system("pause");
	return 0;
}
