#include <iostream>

using namespace std;

string toBinary(int n);

string simetrico(string n);

int main() {

	int n;
	cin >> n;
	
	while (n != 0) {

		cout << simetrico(toBinary(n)) << endl;

		cin >> n;
	}

	return 0;
}

string toBinary(int n) {
	string inBinary = "";

	while (n != 0) {
		if (n % 2 == 0) {
			inBinary += "0";
		}
		else {
			inBinary += "1";
		}
		n /= 2;
	}

	return inBinary;
}

string simetrico(string n) {

	int k = n.length() - 1;
	while (n[k] == '0') {
		n.erase(k);
		--k;
	}

	int i = 0, j = n.length() - 1;

	while (i < j && n[i] == n[j]) {
		++i;
		--j;
	}

	if (i < j)
		return "NO";
	else
		return "SI";
}