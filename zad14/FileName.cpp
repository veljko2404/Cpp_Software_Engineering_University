#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku metodu koja formira novi vektor kopiranjem svakog elementa x puta
ulaznog vektroa.
Ulaz 
v = 1 2 3
Izlaz
1 1 1 2 2 2 3 3 3
x = 3
*/

template<typename T>
void printVector(vector<T>& v) {
	for (T e : v) cout << e << " ";
	cout << endl;
}

template<typename T>
vector<T> createNewVector(vector<T>& v, T x) {
	vector<T> result;
	for (int j = 0;j < v.size();j++) {
		result.push_back(v[j]);
		for (T i = 0;i < x - 1;i++)
			result.push_back(v[j]);
	}
	return result;
}

int main() {

	int x = 3;
	vector<int> v = { 1,2,3 };
	vector<int> v2 = createNewVector(v, x);
	printVector(v);
	printVector(v2);

	return 0;
}