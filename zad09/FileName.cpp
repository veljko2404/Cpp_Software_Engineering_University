#include<iostream>
#include<set>
using namespace std;

/*
Ucitavati parove brojeva sve dok se ne pojavi vec ucitani par ili je ucitano m
brojeva. Koristiti uredjeni i neuredjeni skup.
*/

int main() {

	set<pair<int, int>> set;
	int m = 100;
	for (int i = 0;i < m;i++) {
		int x = rand() % 10;
		int y = rand() % 10;
		pair<int, int> pair = make_pair(x, y);
		if (set.find(pair) != set.end()) break;
		set.insert(pair);
	}

	pair<int, int> pair;
	for (auto& pair : set)
		cout << pair.first << " " << pair.second << endl;

	return 0;
}