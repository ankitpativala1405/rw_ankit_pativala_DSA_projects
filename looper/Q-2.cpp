#include <iostream>
using namespace std;
int main()
{
	int a;
	int count=0;
	
	cout<<"Enter value of a:";
	cin >> a;

	for(;a>0;a/=10){
		count++;
	}
	
	cout<<"Total number of digits:"<<count;
}