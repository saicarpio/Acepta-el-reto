#include <iostream>
using namespace std;

int main() {

	int sum, n, m, aux, ret;

	cin >> n;
	while (n) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> aux;
			sum += aux;
		}
		cin >> m;

		ret = (m * (n+1)) - sum;

		if (ret < 0 || ret > 10) {
			cout << "IMPOSIBLE\n";
		}
		else {
			cout << ret << endl;
		}

		cin >> n;
	}

	return 0;
}