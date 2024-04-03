#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku funkciju za nalazenje maksimalnog elementa matrice(vector <vector < T >>).
*/

template<typename T>
T max_elem_in_matrix(vector<vector<T>>& matrix) {
	T max = matrix[0][0];
	for (typename vector<vector<T>>::iterator itVector = matrix.begin();itVector != matrix.end();itVector++) {
		for (typename vector<T>::iterator itElement = (*itVector).begin();itElement != (*itVector).end();itElement++)
			if (*itElement > max)max = *itElement;
	}
	return max;
}

int main() {

	vector<vector<int>> matrix;
	vector<int> firstRow;
	firstRow.push_back(1);
	firstRow.push_back(3);
	firstRow.push_back(5);
	firstRow.push_back(2);
	vector<int> secondRow;
	secondRow.push_back(5);
	secondRow.push_back(4);
	secondRow.push_back(8);
	secondRow.push_back(2);
	vector<int> thirdRow;
	thirdRow.push_back(3);
	thirdRow.push_back(9);
	thirdRow.push_back(4);
	thirdRow.push_back(2);
	matrix.push_back(firstRow);
	matrix.push_back(secondRow);
	matrix.push_back(thirdRow);

	cout << max_elem_in_matrix<int>(matrix);

	return 0;
}