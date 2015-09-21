#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	string major;
	int age;
};

int main() 
{
	using namespace std;
	Student s1;
	s1.name = "Alex Gilbert";
	s1.major = "Mathematics";
	s1.age = 23;

	cout << "Name: " << s1.name << endl;
	cout << "Major: " << s1.major << endl;
	cout << "Age: " << s1.age << endl;

	Student* sptr = &s1;
	sptr->name = "Socrates";
	sptr->major = "Philosophy";
	sptr->age = 2484;
	cout << endl << "Name: " << sptr->name << endl;
	cout << "Major: " << sptr->major << endl;
	cout << "Age: " << sptr->age << endl;

	cout << endl << "Press Enter" << endl;

	cin.get();
}