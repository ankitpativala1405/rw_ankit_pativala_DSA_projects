#include <iostream>
using namespace std;
int main()
{
    char sum='a';  
    
    do {
        cout<<sum<<",";
        sum=sum+4;  
    } while(sum<='z');
}