#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

void resuelveCaso() {
	std::queue<bool> q; //true = rehacer, false = deshacer
	std::vector<std::string> v (400);
	std::string s, last_s;
	int pos = 0;

	std::cin >> s;
	while (s != ".") {
		if (s == "<") {
			if (q.empty() || q.front() == false) q.push(false);
			else q.pop();
		}
		else if (s == ">") {
			if (q.empty() || q.front() == true) q.push(true);
			else q.pop();
		}
		else {
			last_s = s;
			if (q.empty()) {
				v[pos++] = s;
			}
			else if (q.front() && pos > 0) {
				while (!q.empty()) { v[pos++] = last_s; q.pop(); }
			}
			else {
				while (!q.empty()) {
					pos = (pos - 1 < 0) ? 0 : pos - 1;
					q.pop();
				}
				v[pos++] = last_s;
			}
		}

		std::cin >> s;
	}

	while (!q.empty()) {
		if (q.front() && pos > 0) {
			v[pos++] = last_s;
		}
		else {
			pos = (pos - 1 < 0) ? 0 : pos - 1;
		}
		q.pop();
	}


	for (int i = 0; i < pos; i++) {
		std::cout << v[i] << " ";
	} std::cout << "\n";
}

int main() {

	int numC;
	std::cin >> numC;
	for (; numC > 0; numC--) {
		resuelveCaso();
	}

	return 0;
}