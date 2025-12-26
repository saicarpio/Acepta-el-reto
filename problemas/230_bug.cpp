#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int v[MAX], n;

int inversionesDelVector(int v[],int o, int n);

int main() {

	cin >> n;

	while (n != 0) {

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		cout << inversionesDelVector(v, 0, n) << endl;

		cin >> n;
	}

	return 0;
}

int inversionesDelVector(int v[], int o, int n) {
	
	int ret = 0;
	int k = o;
	bool sorted;

	while (k < n -1 && v[k] <= v[k + 1]) 
		++k;
	sorted = k >= n - 1;

	if (!sorted) {

		ret += inversionesDelVector(v, k + 1, n);
		int i = o, j = k + 1;
		while (i < k + 1 && j < n) {

			if (v[i] <= v[j]) {
				++i;
			}
			else if (v[j] < v[i]) {
				++j;
				ret += k + 1 - i;
			}
		}

		sort(v + o, v + n);
	}
		
	return ret;
}