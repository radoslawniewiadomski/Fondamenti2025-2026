#include <iostream>
using namespace std;

    int main() {
	char s[32];
	cin >> s;

	char* p = s;

	while (*p != '\0') {
		if (*p >= 'A' && *p <= 'Z')
			*p = *p - 'A' + 'a';
		p++; 
	    }
	cout << s;
	return 0;
}



