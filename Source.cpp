#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

//accepts a text file and lowers all capital letters.
void LowerCaseTextFile(string filename) {
	ifstream ist{ filename };
	ofstream ost{ "LowerCasedFile.txt" };
	string buffer;
	while (true) {
		getline(ist, buffer);
		for (char& c : buffer) {
			if (isalpha(c)) {
				c = tolower(c);
			}
		}
		ost << buffer << '\n';
		if (ist.eof()) {
			break;
		}
	}
}

//removes grammar NOT in quoitation marks, REPLACES THE ORIGINAL FILE!
void removeGrammar(string filename) {
	ifstream ist{ filename };
	ofstream ost{ "temporarybuffer.txt" };
	string buffer;
	bool skipStatus{ false };
	while (true) {
		getline(ist, buffer);
		for (char& c : buffer) {
			if (c == '"') {
				if (skipStatus == true) {
					skipStatus = false;
				}else{ skipStatus = true; }
			}
			else {
				if (ispunct(c)&& skipStatus == false) {
					c = ' ';
				}
			}
		}
		ost << buffer << '\n';
		if (ist.eof()) {
			break;
		}
	}
	ost.close();
	ist.close();
	ofstream replace{ filename };
	ifstream input{ "temporarybuffer.txt" };
	string replaceBuffer;
	while (true) {
		getline(input, replaceBuffer);
		replace << replaceBuffer << '\n';
		if (input.eof()) {
			break;
		}
	}

}

//takes an input word and tries to find what line its on. (Note: need to implement a restriction so that only single word can be written, eg no "Dogs Love" allowed for string, and need to remove grammar like ? 
//so that the equality doesnt mistake dog? and dog as being different. Also need to add feature so if word is on same line more than once, wont repeat line 3x over or something.
void findLinesWithWord(string filename, string word) {
	removeGrammar(filename);
	ifstream ist{ filename };
	string buffer;
	int line{ 0 };
	while (true) {
		getline(ist, buffer);
		stringstream ss{ buffer };
		for (string s; ss >> s;) {
			if (word == s) {
				cout << word << " was found on line: " << line << " containing text: " << buffer << '\n';
			}
		}
		++line;
		if (ist.eof()) {
			break;
		}
	}

}

//too lazy, but this should replace its original file. You can make it do this by just using the code from removeGrammar.
void removeVowels(string filename) {
	ifstream ist{ filename };
	string buffer;
	while (getline(ist, buffer)){
		for (char& c : buffer) {
			switch (c) {
			case'a':case'A':case'e':case'E':case'i':case'I':case'o':case'O':case'u':case'U':
				c = ' ';
				break;
			default:
				break;
			}
		}
		cout << buffer << '\n';
	}
}

//accepts input of all types and then outputs standard decimal numbers.
void multiInput() {
	cout << "Enter 5 numbers" << '\n';
	vector<int>storage;
	for (int i = 0; i < 5; ++i) {
		int entry{ 0 };
		cin.unsetf(ios::dec);
		cin.unsetf(ios::hex);
		cin.unsetf(ios::oct);
		cin >> entry;
		storage.push_back(entry);
	}
	for (int i = 0; i < storage.size(); ++i) {
		cout << dec << storage[i] << '\n';
	}
}

//goes through the characters of a word, and tells you what type they are.
void characterType(string word) {
	for (char c : word) {
		if (isalpha(c)) {
			cout << c << " is a letter." << '\n';
			if (isupper(c)) {
				cout << c << " is also an uppercase letter. " << '\n';
			}
			else { cout << c << " is also a lowercase letter. " << '\n'; };
		}
		if (ispunct(c)) {
			cout << c << " is punctuation. " << '\n';
		}
		if (isdigit(c)) {
			cout << c << " is a numerical digit. " << '\n';
		}
	}
}

//reads a sentence from a file, and reverses the words.
void ReverseWords(string filename) {
	ifstream ist{ filename };
	vector<string>words;
	while (ist) {
		string entry;
		ist >> entry;
		words.push_back(entry);
	}
	for (int i = words.size()-1; i >= 0; --i) {
		cout << words[i] << " ";
	}
}

//reads whitespace seperated numbers and outputs the largest one (WIP NEEDS A REWORK)
void largestSeperatedNumber(string line) {
	stringstream ss{ line };
	vector<int>integers;
	for (string s; ss >> s;) {
		integers.push_back(stoi(s));
	}
	sort(integers.rbegin(), integers.rend());
	int counter{ 1 };
	for (int i = 0; i < integers.size(); ++i) {
		for (int index = 0; index < integers.size(); ++index){
			if (integers[i] == integers[index] && index != i) {
				++counter;
			}
		
		}
		cout << integers[i] << '\t' << counter << '\n';
		counter = 1;
	}
}

//just seperates a sentence into a its individual words (grammar included, you need to remove grammar to make it words individually)
vector<string>split(const string& s) {
	stringstream ss{ s };
	vector<string>result;
	for (string buffer; ss >> buffer;) {
		result.push_back(buffer);
	}
	return result;
}

//does the same as above, but also considers characters in the second input as whitespaces too; not fully finished though, as it wont consider the upper or lower case of the whitespace characters as spacing.
vector<string>splitWithCharacters(const string& s, const string& whitespaces) {
	vector<string>result;
	string buffer{ s };
	for (char& c : buffer) {
		for (char z : whitespaces) {
			if (c == z) {
				c = ' ';
			}
		}
	}
	stringstream ss{ buffer };
	string feed;
	while (ss >> feed) {
		result.push_back(feed);
	}
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << '\n';
	}
	return result;
}


int main() {
}