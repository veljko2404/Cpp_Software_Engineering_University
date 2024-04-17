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
vector<T> findVector(vector<T>& nums) {
    int n = nums.size();
    if (n == 0) return vector<T>();

    vector<T> inc_dp(n, 1);
    vector<T> dec_dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && inc_dp[i] < dec_dp[j] + 1) inc_dp[i] = dec_dp[j] + 1;
            else if (nums[i] < nums[j] && dec_dp[i] < inc_dp[j] + 1) dec_dp[i] = inc_dp[j] + 1;
        }
    }

    int maxLength = 1;
    for (int i = 0; i < n; ++i) maxLength = max(maxLength, max(inc_dp[i], dec_dp[i]));

    vector<T> longestSubsequence;
    for (int i = 0; i < n; ++i) {
        if (inc_dp[i] == maxLength || dec_dp[i] == maxLength) {
            longestSubsequence.push_back(nums[i]);
            maxLength--;
        }
    }

    return longestSubsequence;
}

int main() {

	vector<int> v = { 1, 1, 2, 2, 2, 3, 2, 2 };
	vector<int> result = findVector(v);

	printVector(v);
	printVector(result);

	return 0;
}