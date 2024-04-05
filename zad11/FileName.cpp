#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Ucitati sekvencu Trouglova. Trougao je zadat duzinama njegovih stranica. Za
svaki ucitani trougao ispisati koliko je istih trouglova vec ucitano.
*/

class Triangle { 
public:
	int a, b, c;
	Triangle(int a, int b, int c) :a(a), b(b), c(c) {}
	bool operator==(Triangle other) const {
		return a == other.a && b == other.b && c == other.c;
	}
	void print() const {
		cout << a << " " << b << " " << c << endl;
	}
};

class Triangle_h {
public:
	size_t operator()(const Triangle& t) const {
		size_t h = 0;
		h = 19 * h + hash<int>()(t.a);
		h = 19 * h + hash<int>()(t.b);
		h = 19 * h + hash<int>()(t.c);
		return h;
	}
};

int main() {

	unordered_map<Triangle, int, Triangle_h> map;
	int m = 20;
	for (int i = 0;i < m;i++) {
		unordered_map<Triangle, int, Triangle_h>::iterator it;
		Triangle t = Triangle(rand() % 3, rand() % 3, rand() % 3);
		it = map.find(t);
		if (it == map.end()) {
			cout << 0;
			map[t] = 1;
		}
		else {
			cout << map[t];
			map[t] = map[t] + 1;
		}
	}
	
	return 0;
}