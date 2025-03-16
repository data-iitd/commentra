
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

int N;

int getInt() {
	int i;
	cin >> i;
	return i;
}

int getIntArray(int n) {
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		array[i] = getInt();
	}
	return array;
}

string getString() {
	string s;
	cin >> s;
	return s;
}

string getStringArray(int n) {
	vector<string> array(n);
	for (int i = 0; i < n; i++) {
		array[i] = getString();
	}
	return array;
}

int abs(int a) {
	return a >= 0 ? a : -a;
}

int pow(int p, int q) {
	if (q == 0) {
		return 1;
	} else if (q % 2 == 0) {
		return pow(p, q / 2) * pow(p, q / 2);
	} else {
		return p * pow(p, q - 1);
	}
}

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

int min(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = min(res, nums[i]);
	}
	return res;
}

int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = max(res, nums[i]);
	}
	return res;
}

bool strSearch(string a[], string b) {
	for (int i = 0; i < n; i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;
}

void printIntArray(int array[], int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << array[i];
		if (i != n - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

int calcMod(int x) {
	return x % mod;
}

string reverse(string s) {
	int n = s.length();
	for (int i = 0; i < n / 2; i++) {
		char tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
	}
	return s;
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	} else if (n == 2) {
		return true;
	} else if (n % 2 == 0) {
		return false;
	}

	int sqrtN = int(sqrt(n));
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool contains(int s[], int n, int e) {
	for (int i = 0; i < n; i++) {
		if (s[i] == e) {
			return true;
		}
	}
	return false;
}

int* makeRange(int min, int max) {
	int* a = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}
	return a;
}

int** powerset2(int nums[], int n) {
	int length = pow(2, n);
	int** result = new int*[length];

	int index = 0;
	result[index] = new int[0];
	index++;

	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			int* tmp = new int[1];
			tmp[0] = nums[i];
			result[index] = concat(result[j], tmp);
			index++;
		}
	}

	return result;
}

int* concat(int a[], int b[]) {
	int* c = new int[sizeof(a) / sizeof(int) + sizeof(b) / sizeof(int)];
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < sizeof(b) / sizeof(int); i++) {
		c[sizeof(a) / sizeof(int) + i] = b[i];
	}
	return c;
}

int calcGcd(int x, int y) {
	if (y == 0) {
		return x;
	} else if (x >= y) {
		return calcGcd(y, x % y);
	} else {
		return calcGcd(x, y % x);
	}
}

int* getDivisor(int n) {
	map<int, int> divisor;
	divisor[1] = 1;
	if (n != 1) {
		divisor[n] = 1;
	}

	int sqrtN = int(sqrt(n));
	for (int i = 2; i <= sqrtN; i++) {
		if (n % i == 0) {
			divisor[i] = 1;
			divisor[n / i] = 1;
		}
	}

	int* divisorArray = new int[divisor.size()];
	int index = 0;
	for (map<int, int>::iterator it = divisor.begin(); it != divisor.end(); it++) {
		divisorArray[index] = it->first;
		index++;
	}
	return divisorArray;
}

struct intHeap {
	vector<int> heap;
	int size;

	intHeap() {
		size = 0;
	}

	void pushHeap(int n) {
		heap.push_back(n);
		size++;
		int i = size - 1;
		while (i > 0) {
			int p = (i - 1) / 2;
			if (heap[p] < heap[i]) {
				int tmp = heap[p];
				heap[p] = heap[i];
				heap[i] = tmp;
				i = p;
			} else {
				break;
			}
		}
	}

	int popHeap() {
		int res = heap[0];
		heap[0] = heap[size - 1];
		heap.pop_back();
		size--;
		int i = 0;
		while (i * 2 + 1 < size) {
			int l = i * 2 + 1;
			int r = i * 2 + 2;
			int m = l;
			if (r < size && heap[r] > heap[l]) {
				m = r;
			}
			if (heap[m] > heap[i]) {
				int tmp = heap[m];
				heap[m] = heap[i];
				heap[i] = tmp;
				i = m;
			} else {
				break;
			}
		}
		return res;
	}
};

int factMod(int n) {
	int value = 1;
	for (; n > 1; n--) {
		value = (value * n) % mod;
	}
	return value;
}

int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, mod - 2);
	int factNKR = powMod(factNK, mod - 2);
	return (factN * (factKR * factNKR)) % mod;
}

int* primeFactors(int n) {
	vector<int> factors;
	int i = 2;
	for (; i * i <= n; i++) {
		int r = n % i;
		if (r != 0) {
			i += 1;
		} else if (r == 0) {
			n /= i;
			factors.push_back(i);
		}
	}
	if (n > 1) {
		factors.push_back(n);
	}
	int* factorsArray = new int[factors.size()];
	for (int i = 0; i < factors.size(); i++) {
		factorsArray[i] = factors[i];
	}
	return factorsArray;
}

int main() {
	N = getInt();

	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		cout << "hon" << endl;
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	case 3:
		cout << "bon" << endl;
		break;
	}
}

