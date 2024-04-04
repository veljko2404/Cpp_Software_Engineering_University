#include<iostream>
#include<vector>
using namespace std;

/*
Odstampati svaki drugi element celobrojnog vektora ako je taj element neparan.
*/

void printEveryOtherOddInteger(vector<int>& v) {
	for (typename vector<int>::iterator it = v.begin();it != v.end();it += 2)
		if (*it % 2 == 1) cout << *it << " ";
}

int main() {

	vector<int> v = { 3,12,5,22,412,3,16,45,6745,2,4124,1212 };
	printEveryOtherOddInteger(v);

	return 0;
}