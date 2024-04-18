#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku metodu koja formira novi vektor ubacivanjem elementa x izmedju svaka
dva uzastopa elementa ulaznog vektroa.
Ulaz 
v = 1 2 3 1 5 3
Izlaz
1 0 2 0 3 0 1 0 5 0 3
x = 0
*/

template<typename T>
void printVector(vector<T>& v) {
	for (T e : v) cout << e << " ";
	cout << endl;
}

template<typename T>
vector<T> insertX(vector<T>& v, int x) {
	vector<T> result;
	for (auto e : v) {
		result.push_back(e);
		result.push_back(x);
	}
	result.pop_back();
	return result;
}

int main() {

	int x = 0;
	vector<int> v = { 1,2,3,1,5,3 };
	vector<int> v2 = insertX(v, x);
	printVector(v2);

	return 0;
}