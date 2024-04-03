#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku funkciju za nalazenje maksimalnog elementa vektora.
*/

template<typename T>
T max_elem_in_vector(vector<int>& v) {
	T max = v[0];
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
		if (*it > max) max = *it;
	return max;
}

int main() {
	
	vector<int> v;
	v.push_back(5);
	v.push_back(9);
	v.push_back(8);
	v.push_back(2);

	cout << max_elem_in_vector<int>(v);
	
	return 0;
}