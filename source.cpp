#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
	unsigned int endRange = 50, p = 1;
	cout << "Welcome to a guessing game!" << endl;
	cout << "Enter the end of a range (2-1000) : ";
	cin >> endRange;
	if (endRange > 1000) endRange = 1000;
	else if (endRange < 2) endRange = 2;
	vector<int> v;
	do {
		v.push_back(p);
		p = (p << 1);
	} while (p < endRange);
	map<int, vector<int>> mp;
	for (int i = 0; i < p; i++) {
		vector<int> range; int sum = 0;
		for (int j = 0; j < v.size(); j++) {
			if (i & (1 << j)) {
				sum += v[j];
				range.push_back(v[j]);
			}
		}
		for (int j : range)
			mp[j].push_back(sum);
	}
	cout << "pick a number in your head from 1 to " << p << " if you finished picking hit enter!";
	cin.get();
	cin.get();
	cout << endl;
	int sum = 0;
	for (const auto& [a, vv] : mp) {
		cout << "Do you see your number in the following list? (y/n)" << endl;
		for (const int& i : vv)
			cout << i << ' ';
		cout << endl << "> ";
		string str;
		cin >> str;
		if (str[0] == 'y') sum += vv[0];
		cout << endl << endl;
	}
	cout << "Do you see your number in the following list? (y/n)" << endl;
	string str;
	cout << p << endl << "> ";
	cin >> str;
	if (str[0] == 'y') sum = p;
	cout << (sum ? (("You picked: " + to_string(sum))) : "You either didn't see your number or you picked a number that falls out of the range! :)") << endl;
}
