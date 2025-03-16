#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int facNum = 300001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			continue;
		}
		sum += i;
	}
	cout << sum << "\n";
}

// fmt.Println("Yes")
// fmt.Println("No")

// I/O
#include <bits/stdc++.h>
using namespace std;

struct scanner {
	std::istream& is;
	scanner(std::istream& is) : is(is) {}
	template <class T>
	T next() {
		T x;
		is >> x;
		return x;
	}
	template <class T>
	vector<T> next_vec() {
		int n;
		is >> n;
		vector<T> a(n);
		for (int i = 0; i < n; i++) {
			is >> a[i];
		}
		return a;
	}
};

//const factorial = new
int Pow(int a, int n) {
	int ans = 1;
	for (int i = 0; i < 30; i++) {
		if (n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

int Gcd(int a, int b) {
	if (a < b) {
		return Gcd(b, a);
	}
	while (b!= 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int combination(int n, int k, vector<int>& fac, vector<int>& ifac) {
	if (n < k || n < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	//while n!= 0
	int ans = ifac[k] * ifac[n-k] % mod;
	return ans * fac[n] % mod;
}

// 階乗: factorial
// コンビネーションを計算する際に前もって計算しておく
// fac[k] => k! (mod M)
// ifac[k] => k!^(M-2) (mod M)
// n: ex. 2 * 10^5 => 200001
// fac, ifac := factorial()
vector<int> factorial() {
	vector<int> fac(facNum);
	fac[0] = 1;
	vector<int> ifac(facNum);
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
	}
	return {fac, ifac};
}

// vs: sorted slice int value
int lowerBound(vector<int>& vs, int v) {
	int n = vs.size() / 2;
	int m = vs.size();
	while (m!= n) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n;
			//m = m
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

vector<int> IntSlice(int n, int init) {
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

