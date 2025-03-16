#include <bits/stdc++.h>

using namespace std;

// The main function is the entry point of the program.
int main() {
	// Read the number n from the standard input.
	int n = 0;
	cin >> n;

	// Initialize an array aa of length n to store the input integers.
	int* aa = new int[n];

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	int* cumsum = CumSum(aa, n);

	// Initialize a variable ans to store the answer.
	int ans = 2020202020;

	// Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for (int i = 1; i < n-1; i++) {
		// Compute the absolute difference between the last cumulative sum and the current cumulative sum.
		int diff1 = abs(cumsum[n-1] - cumsum[i]);

		// Compute the difference between the current cumulative sum and the first cumulative sum.
		int diff2 = cumsum[i] - cumsum[0];

		// Keep the minimum of these two differences as the answer.
		ans = min(ans, diff1, diff2);
	}

	// Print the answer.
	cout << ans << endl;

	// Delete the aa array.
	delete[] aa;

	// Delete the cumsum array.
	delete[] cumsum;
}

// The NewIo function initializes an Io struct.
Io* NewIo() {
	return new Io();
}

// The Io struct represents the standard input and output streams.
class Io {
public:
	// The constructor of the Io struct initializes the standard input and output streams.
	Io() {
		cin.tie(0);
		ios_base::sync_with_stdio(false);
		cin.exceptions(cin.failbit);
		cout.exceptions(cout.failbit);
	}

	// The Flush method of the Io struct ensures that all output is written before the program exits.
	void Flush() {
		cout.flush();
	}

	// The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
	string NextLine() {
		string line;
		getline(cin, line);
		return line;
	}

	// The Next method of the Io struct reads a token from the standard input and returns it as a string.
	string Next() {
		string token;
		cin >> token;
		return token;
	}

	// The Int method of the Io struct reads an integer from the standard input and returns it.
	int Int() {
		int i = 0;
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
	void PrintIntLn(int* a, int n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	// The PrintStringLn method of the Io struct prints a string array to the standard output.
	void PrintStringLn(string* a, int n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	// The Log method logs a message to the standard error stream.
	void Log(string name, int value) {
		cerr << name << "=" << value << endl;
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
int Min(int* nums, int n) {
	if (n == 0) {
		throw "function min() requires at least one argument.";
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// The Max function returns the maximum of a list of integers.
int Max(int* nums, int n) {
	if (n == 0) {
		throw "function max() requires at least one argument.";
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// The SortAsc function sorts an integer slice in ascending order.
int* SortAsc(int* a, int n) {
	sort(a, a+n);
	return a;
}

// The SortDesc function sorts an integer slice in descending order.
int* SortDesc(int* a, int n) {
	sort(a, a+n, greater<int>());
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
int* CumSum(int* nums, int n) {
	int* sums = new int[n+1];
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return sums;
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
int BisectLeft(int* nums, int left, int right, int target) {
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
vector<vector<int>> Permutations(int* nums, int n) {
	int size = n;
	vector<vector<int>> result;

	for (int i = 0; i < size; i++) {
		int rest[size-1];
		int j = 0;
		for (int k = 0; k < size; k++) {
			if (k!= i) {
				rest[j] = nums[k];
				j++;
			}
		}
		vector<vector<int>> lists = Permutations(rest, size-1);
		for (int k = 0; k < lists.size(); k++) {
			lists.push_back(append(lists[k], nums[i]));
			result.push_back(lists[k]);
		}
	}
	return result;
}

// The PowerSet function returns all subsets of a slice.
vector<vector<int>> PowerSet(int* nums, int n) {
	int size = n;
	vector<vector<int>> result;

	int idx = 0;
	result.push_back(vector<int>());
	idx++;

	for (int i = 0; i < size; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			result.push_back(copyAndAppend(result[j], nums[i]));
			idx++;
		}
	}

	return result;
}

// The copyAndAppend function returns a copy of x with y appended to it.
vector<int> copyAndAppend(vector<int> x, int y) {
	vector<int> dst(x.size()+1);
	copy(x.begin(), x.end(), dst.begin());
	dst[x.size()] = y;
	return dst;
}

// The Combination function returns all combinations of size r from a slice.
vector<vector<int>> Combination(int* nums, int n, int r) {
	int size = n;
	vector<vector<int>> result;
	int bi = (1 << uint(r)) - 1;
	int max = 1 << uint(size);
	int idx = 0;

	for (int i = 0; i < max; i++) {
		int flags = bi;
		vector<int> s;
		for (int j = 0; j < size; j++) {
			if (flags%2!= 0) {
				s.push_back(nums[j]);
			}
			flags /= 2;
		}
		result.push_back(s);
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

// The Combination2NextIndex function returns the next index of a combination.
int Combination2NextIndex(int bi) {
	int t = bi;
	t |= (t >> 1);
	t |= (t >> 2);
	t |= (t >> 4);
	t |= (t >> 8);
	t |= (t >> 16);
	return (bi + 1) ^ t;
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
	for (int i = 1; i < int(sqrt(float(n)))+1; i++) {
		if (n%i == 0) {
			divisors[i] = true;
			divisors[n/i] = true;
		}
	}
	vector<int> result;
	for (auto it = divisors.begin(); it!= divisors.end(); it++) {
		result.push_back(it->first);
	}
	return result;
}

// The END-OF-CODE marker is used to indicate the end of the code.
// The code must be enclosed in a function named Solution.
// The code must contain a main function that calls the Solution function.
// The Solution function must return an integer representing the answer.
// The code must not contain any function with the name of the code.
// The code must not contain any function with the name of the code in upper case.
// The code must not contain any function with the name of the code in lower case.
// The code must not contain any function with the name of the code with underscores.
// The code must not contain any function with the name of the code with dashes.
// The code must not contain any function with the name of the code with spaces.
// The code must not contain any function with the name of the code with dots.
// The code must not contain any function with the name of the code with plus signs.
// The code must not contain any function with the name of the code with asterisks.
// The code must not contain any function with the name of the code with ampersands.
// The code must not contain any function with the name of the code with exclamation points.
// The code must not contain any function with the name of the code with question marks.
// The code must not contain any function with the name of the code with at signs.
// The code must not contain any function with the name of the code with hashes.
// The code must not contain any function with the name of the code with dollar signs.
// The code must not contain any function with the name of the code with percent signs.
// The code must not contain any function with the name of the code with carets.
// The code must not contain any function with the name of the code with carets.
// The code must not contain any function with the name of the code with carets.
// The code must not contain any function with the name of the code with carets.
// The code must not contain any function with the name of the code with carets.
// The code must not contain any function with 