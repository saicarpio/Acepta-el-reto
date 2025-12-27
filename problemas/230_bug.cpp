#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::vector<int> v;

int merge(int low, int mid, int high) {
	std::vector<int> temp(high - low + 1);
	int i = low, j = mid + 1, k = 0;
	int inv_count = 0;
	
	while (i <= mid && j <= high) {
		if (v[i] <= v[j]) {
			temp[k++] = v[i++];
		} else {
			temp[k++] = v[j++];
			inv_count += (mid - i + 1);
		}
	}
	
	while (i <= mid) temp[k++] = v[i++];
	while (j <= high) temp[k++] = v[j++];
	
	for (i = low, k = 0; i <= high; ++i, ++k)
		v[i] = temp[k];
	
	return inv_count;
}

int mergeSort(int low, int high) {
	int inv_count = 0;
	if (low < high) {
		int mid = low + (high - low) / 2;
		inv_count += mergeSort(low, mid);
		inv_count += mergeSort(mid + 1, high);
		inv_count += merge(low, mid, high);
	}
	return inv_count;
}

int resolver(int n, int low, int high) {
	return mergeSort(low, high);
}

bool resuelveCaso() {
    int n;
	std::cin >> n;

    if (!n)
        return false;
	
	int m;
    v.clear();
	for(int i = 0; i < n; ++i) {
		std::cin >> m;
		v.push_back(m);
	}

    int sol = resolver(n, 0, n-1);
    
    std::cout << sol << "\n";

    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}