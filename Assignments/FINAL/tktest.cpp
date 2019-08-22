#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string s = "TK";
	char* s2 = "me";
	char* s3 = strcat(s, s2);
	cout<<s<<endl<<s2<<endl<<*s3;
}
