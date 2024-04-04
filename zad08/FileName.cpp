#include<iostream>
#include<vector>
using namespace std;

/*
Napisati klasu Trojka, koja sadrzi tri celobrojna polja. Sortirati niz instanci klase
Trojka koristeci skup. Trojka (a, b, c) < Trojka (m, n, p) ako je a < m ili a = m, b < n ili
a = m, b = n, c < p
*/

class Three {
	int a, b, c;
public:
	Three(int a, int b, int c) :a(a), b(b), c(c) {}
	void print() {
		cout << a << " " << b << " " << c << endl;
	}
	bool operator<(Three other) {
		if (a < other.a) return true;
		if (a == other.a && b < other.b) return true;
		if (a == other.a && b == other.b && c < other.c) return true;
		return false;
	}
};

void sortVector(vector<Three>& v) {
	for (int i = 0;i < v.size();i++)
		for (int j = i + 1;j < v.size();j++)
			if (v[j] < v[i]) swap(v[i], v[j]);
}

int main() {

	vector<Three> v;
	v.push_back(Three(4, 3, 1));
	v.push_back(Three(5, 1, 8));
	v.push_back(Three(3, 2, 6));
	v.push_back(Three(9, 5, 4));
	v.push_back(Three(4, 4, 9));

	sortVector(v);

	for (typename vector<Three>::iterator it = v.begin();it != v.end();it++)
		(*it).print();

	return 0;
}