#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//print entries of an integer vector
void print(vector<int>v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << '\n';
	}

 }

//fibonacci sequence function, creates an empty vector, takes 2 starting values, followed by how many iterations of fibonnaci, then pushes back into vector; and prints using prev function.
void fibonacci(int x, int y, int n) {
	vector<int>fibVector{ x,y };
	int next;
	for (int i = 0; i < n; ++i) {
		next = x + y;
		y = x;
		x = next;
		fibVector.push_back(next);
	}
	print(fibVector);
}

//reverse entries of a int vector via New copy
void reverse(vector<int>v) {
	vector<int>reversedVector;
	int j = v.size() - 1;
	for (int i = 0; i < v.size(); ++i) {
		reversedVector.push_back(v[j]);
		--j;
	}
	print(reversedVector);
}

void reverseByReference(vector<int>& v) {
	for (int i = 0; i < v.size()/2; ++i) {
		swap(v[i], v[v.size() - 1 - i]);
	}
	print(v);
}

//takes a re-sorted list of names and resyncs them up with their respective ages.
void nameAgePair() {
	vector<string>names;
	vector<int>ages;
	cout << "Enter 5 names please!" << '\n';
	for(int i = 0; i < 5; ++i) {
		string name;
		cin >> name;
		names.push_back(name);
	}
	cout << "Enter 5 ages in order of those names." << '\n';
	for (int i = 0; i < 5; ++i) {
		int age;
		cin >> age;
		ages.push_back(age);
	}
	vector<string>namesCopy{ names };
	sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); ++i) {
		int j{ 0 };
		while (true) {
			if (names[i] == namesCopy[j]){
				cout << namesCopy[j] << " is " << ages[j] << " years old!" << '\n';
					break;
			}
				++j;
		}
	}
}

//outputs max element in a integer vector
int maxV(vector<int>v) {
	int max{ 0 };
	for (int i = 0; i < v.size(); ++i) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

// class of name and age pairs
class name_pairs {
public:
	vector<string>name;
	vector<double>age;
	name_pairs() {
		vector<string>name;
		vector<double>age{ 0 };
	}
	int retrieve_size() const {
		return name.size();
	}
	void read_names() {
		cout << "How many names would you like to enter?" << '\n';
		int amount{ 0 };
		cin >> amount;
		string nameEntry;
		for (int i = 0; i < amount; ++i) {
			cin >> nameEntry;
			name.push_back(nameEntry);
			
		}
	}
	void read_ages() {
		int ageEntry{ 0 };
		cout << "Please enter respective ages of names entered." << '\n';
		for (int i = 0; i < name.size(); ++i) {
			cin >> ageEntry;
			age.push_back(ageEntry);
		}
	}
	void printPairs() {
		for (int i = 0; i < name.size(); ++i) {
			cout << name[i] << " , " << age[i] << '\n';
		}
	}

};

//output the ages
ostream& operator<<(ostream &os, name_pairs& v) {
	for (int i = 0; i < v.retrieve_size(); ++i) {
		os << v.name[i] << " , " << v.age[i] << '\n';
	}
	return os;
}

// equality checker
bool operator ==(const name_pairs& v, const name_pairs& x) {
	bool status{ true };
	if (v.retrieve_size() != x.retrieve_size()) {
		cout << "name pairs not of same size." << '\n';
		abort();
	}
	for (int i = 0; i < v.retrieve_size();++i) {
			if (v.name[i] != x.name[i]) {
				status = false;
				break;
			}
			if (v.age[i] != x.age[i]) {
				status = false;
				break;
			}
	}
	return status;
};

int main() {

}
