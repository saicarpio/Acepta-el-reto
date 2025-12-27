#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

std::vector<std::string> v(200);

int resolver(std::string s) {
	int i = -1;
	std::stack<std::string> undoStack;
	while (s != ".") {
		if (s == "<"){
			if (i >= 0) {
				undoStack.push(v[i]);
				i--;
			}
		} else if (s == ">") {
			if (!undoStack.empty()) {
				i++;
				v[i] = undoStack.top();
				undoStack.pop();
			} else {
				if (i >= 0) {
					i++;
					v[i] = v[i - 1];
				}
			}
		} else {
			i++;
			v[i] = s;
			while (!undoStack.empty()) {
				undoStack.pop();
			}
		}
		std::cin >> s;
	}
	return i + 1;
}

void resuelveCaso() {
	std::string s;
	std::cin >> s;
	v.clear();

	int size = resolver(s);

	if(size > 0) {
		std::cout << v[0];
		for (int i = 1; i < size; i++) {
			std::cout << " " << v[i];
		} 
	}
	std::cout << "\n";
}

int main() {

	int numC;
	std::cin >> numC;
	for (; numC > 0; numC--) {
		resuelveCaso();
	}

	return 0;
}