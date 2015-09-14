#include <iostream>
#include <string>

using namespace std;

void changeStringAmp(string& s)
{
	s[0] = '&';
}

void changeStringStar(string* s)
{
	s[0] = '*';
}

int main()
{
	std::string s = "I'm just a normal string";

	cout << "Initial string: " << s << endl;

	changeStringAmp(s);

	cout << "After pass to &: " << s << endl;

	changeStringStar(&s);

	cout << "After pass to *: " << s << endl;

}

/*
Output:

Initial string: I'm just a normal string
After pass to &: &'m just a normal string
After pass to *: *

*/