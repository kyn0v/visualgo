#include <iostream>
using namespace std;
void Swap(int *a,int *b){
	if(a>b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
}


int main(){
	int x,y;
	cin>>x>>y;
	cout<<x<<y;
	Swap(&x,&y);
	cout<<x<<y;
	system("pause");
	return 0;
}

