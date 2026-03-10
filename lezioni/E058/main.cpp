#include <iostream>
using namespace std;

void incrp(int* p, int n)
{
    *p = *p + n;
}


void incrr(int& p, int n)
{
    p = p + n;
}


int main()
{
    int a = 10;
    int b = 2;
    int c = 3;  
    
    incrp(&a, b);
    cout<<a<<endl;

    incrr(a, c);
    cout<<a<<endl;

    return 0;
}
