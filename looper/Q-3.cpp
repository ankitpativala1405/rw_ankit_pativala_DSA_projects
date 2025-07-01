#include <iostream>
using namespace std;
int main()
{
	int n;

	cout << "Enter the number:";
	cin >> n;

	int last = n % 10;

	for (; n >= 10; n /= 10);
	int first = n;

	int sum = last + first;

	cout <<"The sum of the first and the last digit:"<< sum;
}