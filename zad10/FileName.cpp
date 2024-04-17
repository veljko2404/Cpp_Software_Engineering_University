#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Triangle {

public:
	int a, b, c;
	Triangle(int a, int b, int c) :a(a), b(b), c(c) {}
	bool operator==(const Triangle& other) const {
		return a == other.a && b == other.b && c == other.c;
	}
	void print() const {
		cout << a << " " << b << " " << c << endl;
	}
};

class TriangleHash {
public:
	size_t operator()(const Triangle& t)const {
		size_t h = 0;
		h = 19 * h + hash<int>()(t.a);
		h = 19 * h + hash<int>()(t.b);
		h = 19 * h + hash<int>()(t.b);
		return h;
	}
};

class TriangleCompare {
public:
	bool operator()(const Triangle& a, const Triangle& b) const {
		return a.a == b.a && a.b == b.b && a.c == b.c;
	}
};

int main() {
	unordered_map<Triangle, int, TriangleHash, TriangleCompare> map;

	for (int i = 0; i < 10; i++) {
		int a = rand() % 2;
		int b = rand() % 2;
		int c = rand() % 2;
		Triangle t = Triangle(a, b, c);
		auto it = map.find(t);
		if (it == map.end()) {
			map[t] = 1;
		}
	}

	for (const auto& t : map)
		t.first.print();

	return 0;
}
