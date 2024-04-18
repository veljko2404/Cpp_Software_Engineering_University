#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku metodu koja nalazi najduzi uzatopni podniz datog vektora za koji vazi (a1 < a2 > a3 < a4 > a5 <...).
Ulaz
1 1 2 2 2 3 2 2 
Izlaz
2 3 2
*/

template<typename T>
void printVector(vector<T>& v) {
    for (int e : v) cout << e << " ";
    cout << endl;
}

template<typename T>
vector<T> findVector(vector<T>& v) {
	vector<T> result;
	int start = 0, finish = 0, begin = 0, end = 0;
	for (int i = 0;i < v.size() - 1;i++) {
		if (i % 2 == 0) {
			if (v[i] < v[i + 1]) {
				if (begin == end) {
					begin = i;
					end = i + 1;
				}
				else end++;
			}
			else {
				if (end - begin > finish - start) {
					start = begin;
					finish = end;
				}
				begin = i;
				end = i;
			}
		}
		else {
			if (v[i] > v[i + 1]) {
				if (begin == end) {
					begin = i;
					end = i + 1;
				}
				else end++;
			}
			else {
				if (end - begin > finish - start) {
					start = begin;
					finish = end;
				}
				begin = i;
				end = i;
			}
		}
	}
	for (int i = start;i <= finish;i++) result.push_back(v[i]);
	return result;
}

int main() {

	vector<int> v = { 1, 1, 2, 2, 2, 3, 2, 2 };
	vector<int> result = findVector(v);

	printVector(v);
	printVector(result);

	return 0;
}