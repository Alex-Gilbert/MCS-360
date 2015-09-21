#include <iostream>
#include <string>

using namespace std;

void printArray(string name, int* array, int size) 
{
	for (int i = 0; i < size; i++)
		cout << name << "[" << i << "] ("
		<< (long)(&array[i]) << ") = "
		<< array[i] << endl;
}

void printAll(int* A, int* B, char C, int* D) 
{
	printArray("A", A, 3); \
	printArray("B", B, 3); \
	cout << "C (" << (long)(&C) << ") = " \
		<< C << endl; \
		printArray("D", D, 3);
}

int main() 
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6 };
	char c = 'a';
	int d[] = { 7, 8, 9 };

	cout << "Initial Data" << endl << "----------------------------------------------" << endl;
	printAll(a, b, c, d);

	cout << endl << "Assigning a[3] to 32" << endl << "----------------------------------------------" << endl;
	a[3] = 32;
	printAll(a, b, c, d);

	cout << endl << "Assinging b[3] to 48" << endl << "----------------------------------------------" << endl;
	b[3] = 48;
	printAll(a, b, c, d);
}