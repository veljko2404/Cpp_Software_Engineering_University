#include<iostream>
#include<vector>
using namespace std;

/*
Definisati apstraktnu klasu Figura, sa metodom opis(); apstraktnu klasu Dim2 sa
metodom povrsina() tipa double; apstraktnu klasu Dim3 sa metodom zapremina() tipa double.
Napisati genericke klase Kvadrat(a), Krug(r), Kocka(a), Kupa(r, h).
U test delu formirati linearnu kolekciju figura. Proci kroz kolekciju i odstampati opis svake
figure. Izracunati sumu povrsina svih dvodimenzionalnih figura i sumu zapremina svih trodimenzionalnih figura.
*/

const double PI = 3.14;

class Figure {
public:
	virtual void description() = 0;
};

class Dimensions2 {
public:
	virtual double surface() = 0;
};

class Dimensions3 {
public:
	virtual double volume() = 0;
};

template<typename T>
class Square : public Figure, public Dimensions2 {
	double a;
public:
	Square(T a) :a(a) {}
	void description() {
		cout << "Square: a = " << a << ", surface = " << surface() << endl;
	}
	double surface() {
		return a * a;
	}
};

template<typename T>
class Circle : public Figure, public Dimensions2 {
	double r;
public:
	Circle(T r) :r(r) {}
	void description() {
		cout << "Circle: r = " << r << ", surface = " << surface() << endl;
	}
	double surface() {
		return r * r * PI;
	}
};

template<typename T>
class Cube : public Figure, public Dimensions3 {
	double a;
public:
	Cube(T a) :a(a) {}
	void description() {
		cout << "Cube: a = " << a << ", volume = " << volume() << endl;
	}
	double volume() {
		return a * a * a;
	}
};

template<typename T>
class Cone : public Figure, public Dimensions3 {
	double r, h;
public:
	Cone(T r, T h) :r(r), h(h) {}
	void description() {
		cout << "Cube: r = " << r << ", h = " << h << ", volume = " << volume() << endl;
	}
	double volume() {
		return r * r * h * (1.0 / 3.0);
	}
};

int main() {

	vector<Figure*> figures;
	figures.push_back(new Square<double>(5.0));
	figures.push_back(new Circle<double>(5.0));
	figures.push_back(new Cube<double>(6.0));
	figures.push_back(new Cone<double>(7.0, 4));
	figures.push_back(new Circle<double>(5.0));

	double surfaceSum = 0.0, volumeSum = 0;

	for (typename vector<Figure*>::iterator it = figures.begin();it != figures.end();it++) {
		Dimensions2* dim2 = dynamic_cast<Dimensions2*>(*it);
		Dimensions3* dim3 = dynamic_cast<Dimensions3*>(*it);
		if (dim2) surfaceSum += dim2->surface();
		if (dim3) volumeSum += dim3->volume();
		(*it)->description();
	}
	cout << "Total surface is: " << surfaceSum << endl;
	cout << "Total volume is: " << volumeSum << endl;

	return 0;
}