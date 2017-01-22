#include <iostream>
using namespace std;

void Swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void Select(int *a,int size){
	int MIN_index;
	for(int i=0;i<size;i++){  //注意这里的size-1 
		MIN_index=i;
		for(int j=i;j<size;j++){
			if(a[MIN_index]>a[j]){
				MIN_index=j;  //每次找出最小值 
			}
		}
		Swap(a[i],a[MIN_index]);
	}
}
//与冒泡排序一样，比较时的限定条件（即何时结束）应当注意
void print(int *a,int size){
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
	print(a,n);
	Select(a,n);
	print(a,n);
	system("pause");
	return 0;
}

 
