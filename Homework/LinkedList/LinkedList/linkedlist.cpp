#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct LinkedList {
    private:

        struct ListEntry {
            T val;
            shared_ptr<ListEntry> next;

			~ListEntry() {
				cout << "Deleting " << val << endl;
			}
        };

        int n;
        shared_ptr<ListEntry> head;
        shared_ptr<ListEntry> tail;

		shared_ptr<ListEntry> getEntry(int index)
		{
			if (index > n || index < 0)
				throw "Index out of range";

			auto cur = head;

			for (int i = 0; i < index; i++, cur = cur->next);

			return cur;
		}

    public:
		int size()
		{
			return n;
		}

        LinkedList() {
            n = 0;
            //shared_ptr's automatically have a constructor initializng them to nil,
            //so nothing needs to be written to initialize them here
        }

        //No destructor is needed.  When the LinkedList struct is reclaimed, the destructors for
        //shared_ptr will execute which will free the memory used by ListEntry

        //adds to the front of the list
        void push(T x) {
            shared_ptr<ListEntry> e = make_shared<ListEntry>();
            e->val = x;
            //e->next is initialized to nil by the constructor for shared_ptr
            
            if (n == 0) {
                head = e;
                tail = e;
            } else {
                e->next = head;
                head = e;
            }
            n = n+1;
        }

        //removes from the front of the list
        T pop() {
            if (n == 0) {
                throw "Cannot pop empty list";
            }

            T ret = head->val;

            //The shared_ptr structure has a custom implementation of the assignment operator (=)
            //which will call delete if the pointer that is being overwritten is the last reference.
            //This is the case here, so the following statement will imply a delete to the ListEntry.
            head = head->next;

            n = n - 1;

            return ret;
        }

		T removeFromEnd()
		{
			if (n == 0)
				throw "Cannot remove from an empty list";

			if (n == 1)
				return pop();

			T valToReturn = tail->val;
			auto e = getEntry(n - 2);
			e->next = tail->next;
			tail = e;
			n--;
			return valToReturn;
		}

        void add_to_end(T x) {
            shared_ptr<ListEntry> e = make_shared<ListEntry>();
            e->val = x;
			
            if (n == 0) {
                head = e;
                tail = e;
            } else {
                tail->next = e;
                tail = e;
            }

            n = n + 1;
        }

        void print() {
            cout << "Size of the list is: " << size() << endl << "List entries: " << endl;

            //shared_ptrs can be used as booleans.  When using a shared_ptr as a boolean,
            //it is false if the value is nil and true otherwise.  So in the following for loop,
            //we stop when cur becomes false, which is exactly when cur becomes nil.
            for (auto cur = head; cur; cur = cur->next) {
                cout << cur->val << endl;				
            }
            cout << endl;
        }

		T second_last() {
			if (n < 2)
				throw "second_last cannot be called when size is < 2";

			auto secondLast = head;

			while (secondLast->next != tail)
				secondLast = secondLast->next;

			return secondLast->val;
		}

		T get(int index)
		{		
			return getEntry(index)->val;
		}

		void set(int index, T newVal)
		{
			getEntry(index)->val = newVal;
		}

		void add(int index, T newVal)
		{
			if (index > n || index < 0)
				throw "Index out of range";

			if (index == 0)
				push(newVal);
			else if (index == n)
				add_to_end(newVal);
			else
			{
				auto e = getEntry(index - 1);
				auto toAdd = make_shared<ListEntry>();

				toAdd->val = newVal;
				toAdd->next = e->next;
				e->next = toAdd;
				n++;
			}
		}

		T remove(int index) 
		{
			if (index == 0)
				return pop();
			if (index == n - 1)
				return removeFromEnd();

			auto e = getEntry(index - 1);
			T removed = e->next->val;
			e->next = e->next->next;

			n--;
			return removed;
		}

		void reverse()
		{
			auto cur = head;
			auto ahead = head->next;

			head->next = tail->next;

			while (ahead)
			{
				auto nextAhead = ahead->next;
				ahead->next = cur;

				cur = ahead;
				ahead = nextAhead;
			}

			auto temp = tail;
			tail = head;
			head = temp;
		}
};

int main() 
{
	{
		LinkedList<int> d;

		for (int i = 0; i < 8; i++) {
			d.push(i * 10);
		}

		d.print();

		cout << "Just popped: " << d.pop() << endl;
		cout << "Just popped: " << d.pop() << endl;

		d.print();

		cout << "Second Last: " << d.second_last() << endl;

		cout << "The 3rd Elem: " << d.get(2) << endl << endl;

		cout << "Setting 3rd Elem to 45" << endl << endl;

		d.set(2, 45);
		d.print();

		cout << "Adding -1 in between each elem" << endl << endl;

		for (int i = d.size(); i >= 0; --i)
		{
			d.add(i, -1);
		}

		d.print();

		cout << "Removing The -1's" << endl;

		for (int i = 0; i < d.size(); i++)
		{
			d.remove(i);
		}

		cout << endl;
		d.print();

		cout << "Reversing The List" << endl << endl;

		d.reverse();
		d.print();

		cout << "Press Enter to Reclaim the list!";
		std::cin.get();
	}

	cout << endl << "Press enter to continue";
	cin.get();
    //try compiling with the following line, and see the error
    //d.push("Hello, World");
	//error = argument of type "const char *" is incompatible with parameter of type "int"

}
