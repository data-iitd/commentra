#include <bits/stdc++.h>

using namespace std;

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Function to read an integer from input
int getInt() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to read an array of integers from input
int* getIntArray(int n) {
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}

// Function to read a string from input
string getString() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read an array of strings from input
string* getStringArray(int n) {
	string* array = new string[n];
	for (int i = 0; i < n; i++) {
		getline(cin, array[i]);
	}
	return array;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
	int res = 1;
	while (q > 0) {
		if (q & 1) {
			res = (res * p) % mod;
		}
		p = (p * p) % mod;
		q >>= 1;
	}
	return res;
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % mod;
	} else {
		return (n * powMod(n, p - 1)) % mod;
	}
}

// Function to find the minimum value among a list of integers
int min(int nums[], int n) {
	if (n == 0) {
		return INT_MAX;
	}
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int n) {
	if (n == 0) {
		return INT_MIN;
	}
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

// Function to check if a string exists in an array of strings
bool strSearch(string a[], string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;
}

// Function to print an array of integers
void printIntArray(int nums[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

// Function to calculate x modulo mod
int calcMod(int x) {
	return (x % mod + mod) % mod;
}

// Function to reverse a string
string reverse(string s) {
	string res = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		res += s[i];
	}
	return res;
}

// Function to check if a number is prime
bool isPrime(int n) {
	if (n < 2) {
		return false;
	} else if (n == 2) {
		return true;
	} else if (n % 2 == 0) {
		return false;
	}

	int sqrtN = sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

// Function to check if an integer exists in a slice
bool contains(int s[], int e) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == e) {
			return true;
		}
	}
	return false;
}

// Function to create a range of integers from min to max
int* makeRange(int min, int max) {
	int* a = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}
	return a;
}

// Function to generate the powerset of a given slice of integers
vector<vector<int>> powerset2(vector<int> nums) {
	int length = pow(2, nums.size());
	vector<vector<int>> result(length);

	int index = 0;
	result[index] = vector<int>();
	index++;

	// Generate all subsets
	for (int n : nums) {
		int max = index;
		for (int i = 0; i < max; i++) {
			result[index] = result[i];
			result[index].push_back(n);
			index++;
		}
	}

	return result;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
	if (y == 0) {
		return x;
	} else if (x >= y) {
		return calcGcd(y, x % y);
	} else {
		return calcGcd(x, y % x);
	}
}

// Function to get all divisors of a number
vector<int> getDivisor(int n) {
	map<int, bool> divisor;
	divisor[1] = true;
	if (n!= 1) {
		divisor[n] = true;
	}

	int sqrt = sqrt(n);
	for (int i = 2; i <= sqrt; i++) {
		if (n % i == 0) {
			divisor[i] = true;
			divisor[n / i] = true;
		}
	}

	vector<int> divisorArray;
	for (int d : divisor) {
		divisorArray.push_back(d);
	}
	return divisorArray;
}

// Custom heap type for integers
struct intHeap {
	vector<int> heap;

	// Implementing heap.Interface for intHeap
	int Len() {
		return heap.size();
	}

	bool Less(int i, int j) {
		return heap[i] > heap[j];
	}

	void Swap(int i, int j) {
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	// Push an element onto the heap
	void Push(int x) {
		heap.push_back(x);
	}

	// Pop an element from the heap
	int Pop() {
		int x = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		return x;
	}

	// Initialize a new integer heap
	void initHeap() {
		heap = vector<int>();
	}

	// Push an integer onto the heap
	void pushHeap(int n) {
		heap.push_back(n);
		int i = heap.size() - 1;
		while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
			Swap(i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}

	// Pop an integer from the heap
	int popHeap() {
		int x = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		int i = 0;
		int j = 2 * i + 1;
		while (j < heap.size()) {
			if (j + 1 < heap.size() && heap[j + 1] > heap[j]) {
				j++;
			}
			if (heap[i] >= heap[j]) {
				break;
			}
			Swap(i, j);
			i = j;
			j = 2 * i + 1;
		}
		return x;
	}
};

// Function to calculate factorial modulo mod
int factMod(int n) {
	int value = 1;
	for (; n > 1; n--) {
		value = calcMod(value * n);
	}
	return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, mod - 2);
	int factNKR = powMod(factNK, mod - 2);
	return calcMod(factN * calcMod(factKR * factNKR));
}

// Function to find prime factors of a number
vector<int> primeFactors(int n) {
	vector<int> factors;
	int i = 2;
	for (i = 2; i * i <= n; i++) {
		int r = n % i;
		if (r!= 0) {
			i += 1;
		} else if (r == 0) {
			n /= i;
			factors.push_back(i);
		}
	}
	if (n > 1) {
		factors.push_back(n);
	}
	return factors;
}

// 