#include <iostream>
#include <string>
using namespace std;

char *c;
char x[100];
int n;

int conta (char *z)
{     
    int nc,nv;
    int j;
    nc=0;
    nv=0;
    for (j=0; (*z)!='\0'; j++)
    {
        if (*z=='a' || *z=='A')
            nv++;
        if (*z=='e' || *z=='E')
            nv++;
        if (*z=='i' || *z=='I')
            nv++;
        if (*z=='o' || *z=='O')
            nv++;
        if (*z=='u' || *z=='U')
            nv++;

        nc=j+1-nv;
        z++;
    }

    return nc;
}

int main ()
{
    int k;
    cout << "inserisci dei caratteri (al massimo 99) \n";
    cin >> x;
    c=x;
 
    cout << " il numero di consonanti è : " << conta(x) <<" in " << x;
    return 0;
}
