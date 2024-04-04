#include<iostream>
#include<vector>
using namespace std;

/*
Napisati sablonsku funkciju za nalazenje vrste matrice (vector < vector < T >>), sa najvecom sumom.
*/

template<typename T>
vector<T> findRowWithHighestSum(vector<vector<T>>& matrix) {
	int resultRow = 0, currentRow = 0, maxSum = 0;
	for (typename vector<vector<T>>::iterator itRow = matrix.begin(); itRow != matrix.end(); itRow++) {
		int currentSum = 0;
		for (typename vector<T>::iterator it = (*itRow).begin(); it != (*itRow).end(); it++)
			currentSum += *it;
		if (currentSum > maxSum) {
			maxSum = currentSum;
			resultRow = currentRow;
		}
		currentRow++;
	}
	return matrix[resultRow];
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
	thirdRow.push_back(7);
	matrix.push_back(firstRow);
	matrix.push_back(secondRow);
	matrix.push_back(thirdRow);

	vector<int> result = findRowWithHighestSum(matrix);
	for (int e : result)
		cout << e << " ";

	/*
		Matrix: 

		1 3 5 2   -> 11
		5 4 8 2   -> 19
		3 9 4 7   -> 23
	*/

	return 0;
}