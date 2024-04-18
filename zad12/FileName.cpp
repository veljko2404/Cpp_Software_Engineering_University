#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku metodu koja formira vektor vektora tako da je svaki unutrasnji vektor
sortiran u rastucem poretku
Ulaz
1 2 3 1 5 3 
Izlaz 
[1 2 3]; [1 5]; [3];
*/

template<typename T>
void printVector(vector<T>& v) {
	for (T e : v) cout << e << " ";
	cout << endl;
}

template<typename T>
vector<vector<T>> findAllVectors(vector<T>& v) {
	vector<vector<T>> result;

	vector<T> tmp;
	for (typename vector<T>::iterator it = v.begin();it != v.end();it++) {
		if (it + 1 == v.end()) break;
		if (*it < *(it + 1)) {
			tmp.push_back(*it);
		}
		else {
			tmp.push_back(*it);
			result.push_back(tmp);
			tmp.clear();
		}
	}
	tmp.push_back(v[v.size()-1]);
	result.push_back(tmp);
	tmp.clear();

	return result;
}

int main() {

	vector<int> v = { 1,2,3,1,5,3 };
	vector<vector<int>> vectorOfVectors;
	vectorOfVectors = findAllVectors(v);

	printVector(v);
	for (vector<int> tmp : vectorOfVectors)
		printVector(tmp);

	return 0;
}