#include <iostream>

using namespace std;

int main() {

	double n, v, f;

	cin >> n;

	for (n; n > 0; --n) {
		cin >> v >> f;
		cout << (int)((((v / ((v + f) * 0.5)) - 1) * v * 100) / (v + f)) << endl;
	}

	return 0;
}