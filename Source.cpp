#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


//uses pointers to lowercase C-style string
void to_lower(char* s) {
	for (int i = 0; s[i]!=0; ++i) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 32;
		}		

	}

}


//accepts C-style array string; and allocates string in free store
//perhaps primitive, had to use an index 'lengthofstring' variable to keep track of stuff (allocated array length BEFORE making result pointer)
char* stredup(const char* s) {
	stringstream input;
	int lengthOfString{ 0 };
	for (int i = 0; s[i] != 0; ++i) {
		input << s[i];
		++lengthOfString;
	}
	char* result = new char[lengthOfString];
	lengthOfString = 0;
	for (char s; input >> s;) {
		result[lengthOfString] = s;
		++lengthOfString;


	}
	return result;
}

//takes two c style strings and finds if one is in another
const char* findx(const char* s, const char* x) {
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == x[0]) { 
			for (int j = 1; x[j] != 0; ++j) {
				if (s[i + j] != x[j]) {
					return nullptr;
					break;
				}
				if (x[j]==0) {
					return &s[i];
				}
				}
			}
		}
	}


//accepts C style string array and extends it by 1 unit
char* extendArray(char* s) {
	if (s == nullptr) {
		return nullptr;
	}

	int count{ 0 };

	while (s[count] != 0) {
		++count;
	}

	char* result;
	if (count == 0) {
		result = new char[2]{ ' ',0 };
		return result;
	}

	result = new char[count+2];

	result[count] = ' ';
	result[count + 1] = 0;

	for (int i = 0; i < count; ++i) {
		result[i] = s[i];
	}

	delete[] s;
	return result;


}

//reads characters (c-style) into memory, using the array extension function above.
char* readCharsIntoMem() {
	char* result = new char[1]{ 0 };
	char entry;
	int count{0};
	while (cin >> entry && entry != '!') {
		result = extendArray(result);
		result[count] = entry;
		result[count + 1] = 0;
		++count;
	}

	cout << result;
	return result;
	
}

//reads characters into a string
string readCharsIntoString() {
	stringstream ss;
	char entry;
	while (cin >> entry && entry != '!') {
		ss << entry;
	}

	string result = ss.str();
	cout << result;
	return result;
};

struct Link {
	string value;

	Link(string value = "null",Link* p = nullptr,Link*s = nullptr):value(value),previous(p),successor(s){}

	//erases the referenced Link completely from list, returns referenced member
	Link* erase() {
		Link* n = this;
		if (n == nullptr) {
			return nullptr;
		}

		if (n->successor != nullptr) {
			n->successor->previous = n->previous;
		}

		if (n->previous != nullptr) {
			n->previous->successor = n->successor;

		}
		return this;
	}
	
	//adds pointer in parameter to end of list, will refuse if n is not last in list.
	Link* append(Link* i) {
		Link* n = this;
		if (n->successor != nullptr) {
			cout << "Error - Cannot use append on non terminating link.\n";
			return nullptr;
		}

		if (i->previous != nullptr || i->successor != nullptr) {
			cout << "Error - Cannot append, the given link already has a successor and or predecessor!\n";
			return nullptr;
		}

		n->successor = i;
		i->previous = n;
		return n;

	}

	//inserts the pointer g inbetween the referenced object, and its successor.
	Link* insert(Link* g) {
		Link* n = this;
		if (n == nullptr) {
			cout << "Error - cannot insert g between a null pointer!\n";
			return nullptr;
		}
		
		if (g == nullptr) {
			cout << "Error - cannot insert a null pointer!\n";
			return nullptr;
		}

		g->previous = n;
		g->successor = n->successor;
		if (n->successor != nullptr) {
			n->successor->previous = g;
		}
		n->successor = g;
		return n;
	}
	//returns successor
	Link* next() {
		Link* n = this;
		if (n == nullptr || n->successor == nullptr) {
			cout << "No successor - nullptr returned\n";
			return nullptr;
		}
		return n->successor;
	}
	
	//returns previous
	Link* prev() {
		Link* n = this;
		if (n == nullptr || n->previous == nullptr) {
			cout << "No previous - nullptr returned\n";
			return nullptr;
		}
		return n->previous;
	}

	//prints all values of the list, starting with the referenced member.

	void print_all()
	{
		Link* p = this;
		cout << "{ ";
		while (p) {
			cout << p->value;
			p = p->successor;
			cout << ',';
		}
		cout << " }";
	}

private:
	Link* successor;
	Link* previous;

};

//accepts a c-style string array, creates a copy of said array on free store - sleeker version the above that instead uses arrays
char* sterdup(const char* x) {
	if (x == nullptr) {
		return 0;
	}
	int size{ 0 };
	while (*x) {
		++x;
		++size;
	}
	x -= size;
	char* result = new char[size+1];
	for (int i = 0; i < size; ++i) {
		*result = *x;
		++x;
		++result;
	}
	//terminating 0
	*result = 0;
	result -= size;
	return result;
}

//finds occurence of substring x in larger string s using pointer arithmetic on c-style string arrays only.
char* findX(const char* s, const char* x) {
	int charCount{ 0 };//what character currently at
	int loopCount{ 0 };
	int xSize{ 0 };

	while (*x) {
		++x;
		++xSize;
	}

	x -= xSize;
	while (*s) {
		if (*s == *x) {
			while (*x == *s && *x) {
				++x;
				++s;
				++loopCount;
			}
			x -= loopCount;
			if (loopCount == xSize) {
				cout << "found " << x << " occuring on character " << charCount;
				return nullptr;
			}
			else
			{
				loopCount = 0;
			}
		}
		++s;
		++charCount;
	}
	return nullptr;
}

//function that combines two smaller strings, with a period inbetween them.
string cat_dot(const string& s1, const string& s2, const string s = ".") {
	string result;
	result = s1 + s + s2;
	cout << result;
	return result;

}

//same functionality as cat_dot, except operates on c-style string arrays.
char* Cstyle_dot(const char* s1, const char* s2) {
	int s1Size{ 0 };
	int s2Size{ 0 };
	while (*s1) {
		++s1;
		++s1Size;
	}
	while (*s2) {
		++s2;
		++s2Size;
	}
	s1 -= s1Size;
	s2 -= s2Size;

	char* result = new char[s1Size + s2Size + 2];
	while (*s1) {
		*result = *s1;
		++s1;
		++result;
	}
	*result++ = '.';
	while (*s2) {
		*result = *s2;
		++s2;
		++result;
	}
	*result++ = 0;
	result -= (s1Size + s2Size + 2);
	cout << result;
	return result;


}
int main() {
	
	
}
