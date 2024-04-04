#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

/*
Definisati apstraktnu klasu IMera, sa metodom getMera koja e dati neku meru
objekta tipa double. Napisati genericku klasu Tacka, odredjenu koordinatama, gde se tip xkoordinate i y-koordinate moe zadati. Mera tacke je njeno rastojanje od koordinatnog pocetka.
Tacke su iste ako su na istoj udaljensti od koordinatnog poetka.
U test delu formirati linearnu kolekciju taaka.
Proci kroz linearnu kolekciju i dodati clanove linearne kolekcije u nesortiranu kolekciju gde
je key mera, a value tacka, ako ve nije dodata taka sa takvom merom. Iterirati kroz tako
formiranu kolekciju i prikazati njen sadraj.
*/

class IMera {
public:
	virtual double getMera() = 0;
};

template<typename T>
class Tacka : IMera {
private:
	T x, y;
public:
	Tacka(T x, T y) : x(x), y(y) {}
	double getMera() {
		return sqrt(x * x + y * y);
	}
	void print() {
		cout << "[" << x << ", " << y << " -> " << getMera() << "]" << endl;
	}
};

int main() {

	vector<Tacka<int>> t;
	t.push_back(Tacka<int>(5, 2));
	t.push_back(Tacka<int>(4, 8));
	t.push_back(Tacka<int>(3, 1));
	t.push_back(Tacka<int>(9, 6));
	t.push_back(Tacka<int>(3, 4));
	t.push_back(Tacka<int>(8, 4));

	unordered_map<double, Tacka<int>> map;
	for (int i = 0;i < t.size();i++) {
		unordered_map<double, Tacka<int>>::iterator it = map.find(t[i].getMera());
		if (it == map.end())
			map.insert(make_pair(t[i].getMera(), t[i]));
	}
	for (unordered_map<double, Tacka<int>>::iterator iterator = map.begin();iterator != map.end();iterator++)
		(*iterator).second.print();


	return 0;
}