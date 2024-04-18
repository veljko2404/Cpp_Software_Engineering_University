#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku metodu koja nalazi najveci rastuci uzatopni podniz datog vektora.
Ulaz 
1 1 2 2 2 3 5 5
Izlaz
2 3 5
*/

template<typename T>
void printVector(const vector<T>& v) {
	for (int e : v) cout << e << " ";
	cout << endl;
}

template<typename T>
vector<T> findLongestIncreasingSubArray(const vector<T>& v) {
	vector<T> result;
	int start = 0, finish = 0, begin = 0, end = 0;
	for (int i = 0;i < v.size() - 1;i++) {
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
	for (int i = start;i <= finish;i++) result.push_back(v[i]);
	return result;
}

int main() {

	vector<int> v = { 1,1,2,2,2,3,5,5 };
	vector<int> v2 = findLongestIncreasingSubArray(v);
	printVector(v);
	printVector(v2);

	return 0;
}