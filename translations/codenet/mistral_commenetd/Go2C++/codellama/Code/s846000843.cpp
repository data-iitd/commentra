
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// The main function is the entry point of the program.
int main() {
	// Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
	Io io;
	io.Flush();

	// Read the number n from the standard input.
	int n = io.Int();

	// Initialize an array aa of length n to store the input integers.
	vector<int> aa(n);

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for (int i = 0; i < n; i++) {
		aa[i] = io.Int();
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	vector<int> cumsum = CumSum(aa);

	// Initialize a variable ans to store the answer.
	int ans = 2020202020;

	// Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for (int i = 1; i < cumsum.size()-1; i++) {
		// Compute the absolute difference between the last cumulative sum and the current cumulative sum.
		int diff1 = abs(cumsum[cumsum.size()-1] - cumsum[i]);

		// Compute the difference between the current cumulative sum and the first cumulative sum.
		int diff2 = cumsum[i] - cumsum[0];

		// Keep the minimum of these two differences as the answer.
		ans = min(ans, diff1, diff2);
	}

	// Print the answer using the PrintLn method of the Io struct.
	io.PrintLn(ans);

	// End the program.
	return 0;
}

// The Io struct represents the standard input and output streams.
struct Io {
	// The Flush method of the Io struct ensures that all output is written before the program exits.
	void Flush() {
		cout.flush();
	}

	// The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
	string NextLine() {
		string buffer;
		getline(cin, buffer);
		return buffer;
	}

	// The Next method of the Io struct reads a token from the standard input and returns it as a string.
	string Next() {
		string buffer;
		cin >> buffer;
		return buffer;
	}

	// The Int method of the Io struct reads an integer from the standard input and returns it.
	int Int() {
		int i;
		cin >> i;
		return i;
	}

	// The PrintLn method of the Io struct prints a line to the standard output.
	void PrintLn(int a) {
		cout << a << endl;
	}

	// The Printf method of the Io struct prints a formatted line to the standard output.
	void Printf(string format, int a) {
		cout << format << a << endl;
	}

	// The PrintIntLn method of the Io struct prints an integer array to the standard output.
	void PrintIntLn(vector<int> a) {
		cout << a << endl;
	}

	// The PrintStringLn method of the Io struct prints a string array to the standard output.
	void PrintStringLn(vector<string> a) {
		cout << a << endl;
	}
};

// The Abs function returns the absolute value of an integer.
int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// The Pow function returns the result of raising a to the power of b.
int Pow(int p, int q) {
	return int(pow(p, q));
}

// The Min function returns the minimum of a list of integers.
int Min(vector<int> nums) {
	if (nums.size() == 0) {
		panic("funciton min() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = int(min(res, nums[i]));
	}
	return res;
}

// The Max function returns the maximum of a list of integers.
int Max(vector<int> nums) {
	if (nums.size() == 0) {
		panic("funciton max() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = int(max(res, nums[i]));
	}
	return res;
}

// The SortAsc function sorts an integer slice in ascending order.
vector<int> SortAsc(vector<int> a) {
	sort(a.begin(), a.end());
	return a;
}

// The SortDesc function sorts an integer slice in descending order.
vector<int> SortDesc(vector<int> a) {
	sort(a.begin(), a.end(), greater<int>());
	return a;
}

// The GCD function returns the greatest common divisor of a and b.
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a%b);
}

// The LCM function returns the least common multiple of a and b.
int LCM(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	return a * b / GCD(a, b);
}

// The CumSum function computes the cumulative sum of an integer slice.
vector<int> CumSum(vector<int> nums) {
	vector<int> sums(nums.size() + 1);

	for (int i = 0; i < nums.size(); i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return sums;
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
int BisectLeft(vector<int> nums, int left, int right, int target) {
	if (left == right) {
		if (nums[left] == target) {
			return left;
		} else if (nums[left] < target) {
			return left + 1;
		} else {
			return left;
		}
	}

	int mid = (left + right) / 2;
	if (nums[mid] == target) {
		return mid;
	}

	if (nums[mid] > target) {
		return BisectLeft(nums, left, mid, target);
	} else if (nums[mid] < target) {
		return BisectLeft(nums, mid+1, right, target);
	}
	return 0;
}

// The Permutations function returns all permutations of a slice.
vector<vector<int>> Permutations(vector<int> nums) {
	int size = nums.size();
	vector<vector<int>> result(0, vector<int>(size));

	for (int i = 0; i < size; i++) {
		vector<int> rest = remove(nums, nums[i]);
		vector<vector<int>> lists = Permutations(rest);
		for (int j = 0; j < lists.size(); j++) {
			lists[j] = append(lists[j], nums[i]);
			result.push_back(lists[j]);
		}
	}
	return result;
}

// The remove function removes the first occurrence of x from a slice.
vector<int> remove(vector<int> nums, int x) {
	vector<int> result(0);
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != x) {
			result.push_back(nums[i]);
		}
	}
	return result;
}

// The PowerSet function returns all subsets of a slice.
vector<vector<int>> PowerSet(vector<int> nums) {
	int size = nums.size();
	vector<vector<int>> result(0, vector<int>(size));

	int idx = 0;
	result.push_back(vector<int>(0));
	idx++;

	for (int i = 0; i < size; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			result.push_back(append(result[j], nums[i]));
			idx++;
		}
	}

	return result;
}

// The append function returns a copy of x with y appended to it.
vector<int> append(vector<int> x, int y) {
	vector<int> dst(x.size() + 1);
	copy(x.begin(), x.end(), dst.begin());
	dst[x.size()] = y;
	return dst;
}

// The Combination function returns all combinations of size r from a slice.
vector<vector<int>> Combination(vector<int> nums, int r) {
	int size = nums.size();
	vector<vector<int>> result(0, vector<int>(r));

	int idx = 0;
	int bi = (1 << uint(r)) - 1;
	int max = 1 << uint(size);

	while (bi < max) {
		int flags = bi;
		vector<int> s(0);
		for (int i = 0; i < size; i++) {
			if (flags % 2 != 0) {
				s.push_back(nums[i]);
			}
			flags /= 2;
		}
		result.push_back(s);
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

// The CombinationCount function returns the number of combinations of size r from a slice.
int CombinationCount(int n, int m, int maxInput) {
	map<int, map<int, int>> memo;
	for (int i = 1; i <= maxInput*maxInput; i++) {
		memo[i] = map<int, int>();
	}
	return combinationCount(n, m, memo);
}
int combinationCount(int n, int m, map<int, map<int, int>> memo) {
	if (n == m || m == 0) {
		return 1;
	}

	int left, lOK;
	int right, rOK;
	left = memo[n-1][m-1];
	right = memo[n-1][m];
	lOK = memo[n-1].find(m-1) != memo[n-1].end();
	rOK = memo[n-1].find(m) != memo[n-1].end();

	if (lOK && rOK) {
		return left + right;
	}

	if (lOK) {
		right = combinationCount(n-1, m, memo);
		memo[n-1][m] = right;
		return left + right;
	}

	if (rOK) {
		left = combinationCount(n-1, m-1, memo);
		memo[n-1][m-1] = left;
		return left + right;
	}

	left = combinationCount(n-1, m-1, memo);
	right = combinationCount(n-1, m, memo);
	memo[n-1][m-1] = left;
	memo[n-1][m] = right;
	return left + right;
}

// The Fact function returns the factorial of n.
int Fact(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Fact(n-1);
	}
}

// The Divisors function returns all divisors of n.
vector<int> Divisors(int n) {
	map<int, bool> divisors;
	for (int i = 1; i < int(sqrt(n))+1; i++) {
		if (n%i == 0) {
			divisors[i] = true;
			divisors[n/i] = true;
		}
	}
	vector<int> result(0);
	for (map<int, bool>::iterator it = divisors.begin(); it != divisors.end(); it++) {
		result.push_back(it->first);
	}
	return result;
}

// The panic function prints a message to the standard error stream and exits the program.
void panic(string message) {
	cerr << message << endl;
	exit(1);
}

// The main function is the entry point of the program.
int main() {
	// Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
	Io io;
	io.Flush();

	// Read the number n from the standard input.
	int n = io.Int();

	// Initialize an array aa of length n to store the input integers.
	vector<int> aa(n);

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for (int i = 0; i < n; i++) {
		aa[i] = io.Int();
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	vector<int> cumsum = CumSum(aa);

	// Initialize a variable ans to store the answer.
	int ans = 2020202020;

	// Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for (int i = 1; i < cumsum.size()-1; i++) {
		// Compute the abs