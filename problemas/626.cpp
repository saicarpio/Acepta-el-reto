#include <iostream>
#include <string>
using namespace std;

void cumple(int d, int m, int a);
bool esBisiesto(int n);

int main() {
	char c;
	int d, m, a;
	int numCasos;
	cin >> numCasos;
	for (; numCasos > 0; --numCasos) {
		cin >> d >> c >> m >> c >> a;
		cumple(d, m, a);
	}

	return 0;
}

void cumple(int d, int m, int a) {
	if (m < 2 ){
		if(!esBisiesto(a)) 
			a += 4 - (a % 4);
	}
	else  if (m == 2){
		if (d == 29)
			a += 4;
		else if (!esBisiesto(a))
			a += 4 - (a % 4);
	}
	else {
		a += 4 - (a % 4);
	}

	string year = to_string(a);

	if (year.length() == 2)
		year = "00" + year;
	else if (year.length() == 3)
		year = "0" + year;

	cout << "29/02/" << year << endl;
}

bool esBisiesto(int n) {
	return (n % 4 == 0);
}