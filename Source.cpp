#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

// ISBN sub-class for book
class ISBN {
	int n1, n2, n3;
	char c1;
public:
	//output operator
	friend ostream& operator <<(ostream& os, ISBN x);
	//equaltiy checker 
	bool operator ==(ISBN x) {
		if (n1 == x.n1 && n2 == x.n2 && n3 == x.n3 && c1 == x.c1) {
			return true;
		}
		else { return false; }
	}

	ISBN();
	ISBN(int x1, int x2, int x3, char y1) 
		: n1{ x1 }, n2{ x2 }, n3{ x3 }, c1{ y1 }
	{}
};

ostream& operator <<(ostream& os, ISBN x) {
	os << x.n1 << x.n2 << x.n3 << x.c1 << '\n';
	return os;
}


//ISBN constructor
ISBN::ISBN(){
	n1 = 0;
	n2 = 0;
	n3 = 0;
	c1 = 'a';

}

enum class Genre {
	fiction , nonfiction, biography, politcal, children
};

//book class
struct Book {
	Genre gen;
	ISBN ISBnumber;
	string title;
	string author;
	string copyDate;
	bool signedOut;
public: 
	Book();
	bool signOut() {
		signedOut = true;
	}
	bool signIn() {
		signedOut = false;
	}
};

//Constructor for book
Book::Book() {
	gen = Genre::fiction;
	title = "Null";
	author = "Null";
	copyDate = "Null";
	signedOut = false;
}

//output operator for book
ostream& operator<<(ostream &os, Book x) {
	os << x.title << '\n' << x.author << '\n' << x.copyDate << '\n' << x.ISBnumber;
	return os;
}

class Rational {
	int numerator;
	int denominator;
public:
	Rational() {
		numerator = 1;
		denominator = 1;
	};
	Rational(int x, int y);
	friend ostream& operator <<(ostream &os, Rational z);
	Rational operator+(Rational x) {
		int NewNumerator = numerator*x.denominator + x.numerator*denominator;
		int NewDenominator = denominator*x.denominator;
		Rational Result{ NewNumerator, NewDenominator };
		return Result;
	}

};

ostream& operator <<(ostream& os,Rational z) {
	os << z.numerator << "/" << z.denominator << '\n';
	return os;
};
Rational::Rational(int x, int y) {
	numerator = x;
	denominator = y;
};

// reads whitespace sepereated integers from a file, and sums them
void sum_whiteSpaceNumbers(string filename) {
	ifstream ist { filename };
	if (ist.fail()) {
		cout << "WARNING!: FILE FAILED TO OPEN.";
	}
	int sum{ 0 };
	for (int buffer; ist >> buffer;) {
		sum += buffer;
	}
	cout << sum;
}

//writes hour and temperature pairs to a file
void write_TempHours(string filename) {
	ofstream ost{ filename };
	while (true) {
		int hour{ 0 };
		double temperature{ 0 };
		cout << "Please enter an hour, and temperature; or any non integer to end." << '\n';
		cin >> hour >> temperature;
		if (!cin) {
			cin.clear();
			break;
		}
		ost << '(' << hour << ',' << temperature << ')' << '\n';
	}
}

//reads hour and temperature pairs from a file (converse of above function)
void read_TempHours(string filename) {
	ifstream ist{ filename };
	vector<int>hours;
	vector<double>temps;
	while (true){
		char c1;
		int hour;
		char c2;
		double temperature;
		char c3;
		ist >> c1 >> hour >> c2 >> temperature >> c3;
		if (ist.fail()) {
			break;
		}
		hours.push_back(hour);
		temps.push_back(temperature);
	}
	for (int i = 0; i < hours.size(); ++i) {
		cout << hours[i] << "," << temps[i] << '\n';
	}

}


// unfinished, probably a bad way to do this but if you really want to finish it
// you theoritcally would find the size of the string (how many characters are in it) and based on that do a series of switches on the character you want to append
//i.e if the string was 3 characters, the first appended character would be "C" for the roman 100th place.
//better ways to do it, this is a dumbass way of going about it; search online if you're curious.
class RomanIntegers {
	string value;
public:
	RomanIntegers(string entry) {
		int size = entry.size();
		for (char c1 : entry) {
			string append;
			if (!isdigit(c1)) {
				cout << "ERROR: Non integer entered!";
				abort();
			}
			if (size = 1) {
				switch (c1)
				{
				case'1':
					append = "I";
					break;
				case'2':
					append = 'II';
					break;
				case'3':
					append = 'III';
					break;
				}
			}
			value += append;
		}
		cout << value;
	}
};
int main() {
}




 