#include <iostream>
using namespace std;

void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Bubble(int *a,int size){
	for(int i=size;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				Swap(a+j,a+j+1);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	Bubble(a,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	
}

