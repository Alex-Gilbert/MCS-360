#include <string>
#include <iostream>
#include <cassert>

using namespace std;

struct StringArrayStack {
private:
	int n;
	int array_size;
	string *a;

public:
	//This function is the constructor, it is called when a StringArrayStack is created.
	StringArrayStack() {
		n = 0;
		array_size = 1;
		a = new string[1]; //This creates a new array of length 1 and stores a pointer to it in a.
	}

	//This function is the destructor, it is called when the StringArrayStack is no longer needed.
	//For now just ignore this, we will talk more about constructors and destructors in the future.
	~StringArrayStack() {
		delete[] a;
	}

	string get(int i) {
		assert(i >= 0 && i < n);
		return a[i];
	}

	string set(int i, string x) {
		assert(i >= 0 && i < n);
		string y = a[i];
		a[i] = x;
		return y;
	}

	//The modified add all function
	void add_all(int i, StringArrayStack &source) {
		assert(i >= 0 && i <= n);

		int prevN = n;
		n  += source.n;

		if (n >= array_size)
			resize();

		for (int j = prevN + source.n; j >= i + source.n; j--)
		{
			a[j] = a[j - source.n];
		}

		for (int j = i; j < source.n + i; ++j)
		{
			a[j] = source.get(j - i);
		}
	}

	void add(int i, string x) {
		assert(i >= 0 && i <= n);
		if (n == array_size) {
			resize();
		}
		for (int j = n; j >= i + 1; j--) {
			a[j] = a[j - 1];
		}
		a[i] = x;
		n = n + 1;
	}

	string remove(int i) {
		assert(i >= 0 && i < n);
		string x = a[i];
		for (int j = i; j <= n - 2; j++) {
			a[j] = a[j + 1];
		}
		n = n - 1;
		if (array_size >= 3 * n) {
			resize();
		}
		return x;
	}

	

	void resize() {
		array_size = std::fmax(1, 2 * n);
		string *b = new string[array_size]; //create a new array and store a pointer to it in b.
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}
		delete[] a; //for now, just ignore this line.  We will talk about delete later.
		a = b;
	}

	void print() {
		cout << "Array size: " << array_size << endl;
		cout << "n: " << n << endl;
		for (int i = 0; i < n; i++) {
			cout << "Pos " << i << ": " << a[i] << endl;
		}
		cout << endl;
	}
};

int main() {
	StringArrayStack s;

	s.print();

	s.add(0, "Hello");
	s.add(1, "World");
	s.add(1, ", ");

	s.print();

	s.remove(1);

	s.print();

	s.add(0, "Beginning");
	s.print();
	s.add(1, "Also beginning");

	s.print();

	s.remove(1);

	s.print();

	StringArrayStack e;
	StringArrayStack n;

	e.add(0, "Have no ");
	e.add(1, "fear ");
	e.add(2, "never ");
	e.add(3, "reach ");
	e.add(4, "it ");

	n.add(0, "of ");
	n.add(1, "perfection");
	n.add(2, ", ");
	n.add(3, "you'll ");

	e.print();

	n.print();

	e.add_all(2, n);

	e.print();

	return 0;
}