#include <iostream>
using namespace std;

void Swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void Select(int *a,int size){
	int MIN_index;
	for(int i=0;i<size;i++){  //ע�������size-1 
		MIN_index=i;
		for(int j=i;j<size;j++){
			if(a[MIN_index]>a[j]){
				MIN_index=j;  //ÿ���ҳ���Сֵ 
			}
		}
		Swap(a[i],a[MIN_index]);
	}
}
//��ð������һ�����Ƚ�ʱ���޶�����������ʱ������Ӧ��ע��
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

 
