#include<iostream>
#include<vector>
using namespace std;

/*
Dat je ceo broj m. Odstampati svaki element vektora koji je veci od prethodnih m brojeva i manji od narednih m brojeva.
*/

void printElements(vector<int>& v, int m) {
	int start = m, end = v.size() - m;
	for (int i = start;i < end;i++) {
		bool correctElement = true;
		for (int j = 1;j <= m;j++)
			if (v[i - j] >= v[i] || v[i + j] <= v[i]) correctElement = false;
		
		if (correctElement) cout << v[i] << " ";
	}
}

int main() {

	vector<int> v = { 4,2,3,5,8,9 };
	int m = 2;

	printElements(v, m);

	return 0;
}