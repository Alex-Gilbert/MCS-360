### Exercise 2
```c++
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    cout << "I will print and detect all primes below the number you enter" << endl;
    cin >> number;

    for (int i = 2; i <= number; ++i)
    {
        int root = (int)sqrt(i);
        bool isPrime = true;
        for (int j = 2; j <= root; ++j)
        {
            if (i % j == 0)
            {
              isPrime = false;
              break;
            }
        }
        if (isPrime)
            cout << i << ", ";
    }
}

/*
Output:

I will print and detect all primes below the number you enter
100
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97
*/
```

### Exercise 6

I don't understand the problem...

### Exercise 7
```c++
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
```
