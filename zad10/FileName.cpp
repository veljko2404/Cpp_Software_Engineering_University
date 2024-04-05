#include<iostream>
#include<vector>
using namespace std;

/*
Ucitati sekvencu Trouglova. Trougao je zadat duzinama njegovih stranica. Ne ucitavati
trougao ako vec postoji.
*/

class Triangle {
	int a, b, c;
public:
	Triangle(int a, int b, int c) :a(a), b(b), c(c) {}
	bool operator==(Triangle other) {
		return a == other.a && b == other.b && c == other.c;
	}
	void print() {
		cout << a << " " << b << " " << c << endl;
	}
};

void loadTriangle(Triangle t, vector<Triangle>& v) {
	for (int i = 0;i < v.size();i++)
		if (t == v[i]) return;
	v.push_back(t);
}

int main() {

	vector<Triangle> v;
	
	for (int i = 0;i < 20;i++) {
		int a = rand() % 2;
		int b = rand() % 2;
		int c = rand() % 2;
		Triangle t = Triangle(a, b, c);
		loadTriangle(Triangle(a, b, c), v);
	}

	for (int i = 0;i < v.size();i++)
		v[i].print();

	return 0;
}