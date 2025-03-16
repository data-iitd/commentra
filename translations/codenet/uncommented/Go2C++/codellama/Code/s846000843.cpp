
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> aa(n);

	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}

	vector<int> cumsum = CumSum(aa);

	//fmt.Println(cumsum)
	int ans = 2020202020;
	for (int i = 1; i < cumsum.size()-1; i++) {
		ans = min(ans, abs(cumsum[cumsum.size()-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
	}

	cout << ans << endl;

}

int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

int Pow(int p, int q) {
	return int(pow(p, q));
}

int Min(vector<int> nums) {
	if (nums.size() == 0) {
		panic("funciton min() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = min(res, nums[i]);
	}
	return res;
}

int Max(vector<int> nums) {
	if (nums.size() == 0) {
		panic("funciton max() requires at least one argument.");
	}
	int res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = max(res, nums[i]);
	}
	return res;
}

vector<int> SortAsc(vector<int> a) {
	sort(a.begin(), a.end());
	return a;
}

vector<int> SortDesc(vector<int> a) {
	sort(a.begin(), a.end(), greater<int>());
	return a;
}

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a%b);
}

int LCM(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	return a * b / GCD(a, b);
}

vector<int> CumSum(vector<int> nums) {
	vector<int> sums = { 0 };

	for (int i = 0; i < nums.size(); i++) {
		sums.push_back(sums[i] + nums[i]);
	}
	return sums;
}

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
		return BisectLeft(nums, mid + 1, right, target);
	}
	return 0;
}

vector<vector<int>> Permutations(vector<int> nums) {
	int n = nums.size();
	if (n == 0) {
		return vector<vector<int>>{};
	}
	vector<vector<int>> ans;

	for (int i = 0; i < nums.size(); i++) {
		vector<int> rest = remove(nums, nums[i]);
		vector<vector<int>> lists = Permutations(rest);
		if (lists.size() == 0) {
			lists = vector<vector<int>>{ vector<int>{} };
		}

		for (int i = 0; i < lists.size(); i++) {
			lists[i].push_back(nums[i]);
			ans.push_back(lists[i]);
		}
	}
	return ans;
}

vector<int> remove(vector<int> nums, int target) {
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != target) {
			result.push_back(nums[i]);
		}
	}
	return result;
}

vector<vector<int>> PowerSet(vector<int> nums) {
	int size = pow(2, nums.size());
	vector<vector<int>> result(size);

	int idx = 0;
	result[idx] = vector<int>{};
	idx++;

	for (int i = 0; i < nums.size(); i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			result[idx] = copyAndAppend(result[j], nums[i]);
			idx++;
		}
	}

	return result;
}

vector<int> copyAndAppend(vector<int> nums, int n) {
	vector<int> dst(nums.size() + 1);
	copy(nums.begin(), nums.end(), dst.begin());
	dst[nums.size()] = n;
	return dst;
}

vector<vector<int>> Combination(vector<int> nums, int k) {
	int size = nums.size();
	vector<vector<int>> result(CombinationCount(int64(size), int64(k), 10e10));
	int bi = (1 << uint(k)) - 1;
	int max = 1 << uint(size);
	int idx = 0;

	for (; bi < max;) {
		int flags = bi;
		vector<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (flags % 2 != 0) {
				s.push_back(nums[i]);
			}
			flags /= 2;
		}
		result[idx] = s;
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

int Combination2NextIndex(int n) {
	int smallest = n & -n;
	int ripple = n + smallest;
	int newSmallest = ripple & -ripple;
	int ones = ((newSmallest / smallest) >> 1) - 1;
	return ripple | ones;
}

// CombinationCount はnCmを計算する関数。メモ化を使って計算量を削減する。
int CombinationCount(int64 n, int64 m, int64 maxInput) {
	map<int64, map<int64, int64>> memo;
	for (int i = 1; i <= maxInput*maxInput; i++) {
		memo[int64(i)] = map<int64, int64>{};
	}
	return combinationCount(n, m, memo);
}
int combinationCount(int64 n, int64 m, map<int64, map<int64, int64>> memo) {
	if (n == m || m == 0) {
		return 1;
	}

	int left, lOK;
	int right, rOK;
	tie(left, lOK) = memo[n - 1][m - 1];
	tie(right, rOK) = memo[n - 1][m];

	if (lOK && rOK) {
		return left + right;
	}

	if (lOK) {
		right = combinationCount(n - 1, m, memo);
		memo[n - 1][m] = right;
		return left + right;
	}

	if (rOK) {
		left = combinationCount(n - 1, m - 1, memo);
		memo[n - 1][m - 1] = left;
		return left + right;
	}

	left = combinationCount(n - 1, m - 1, memo);
	right = combinationCount(n - 1, m, memo);
	memo[n - 1][m - 1] = left;
	memo[n - 1][m] = right;
	return left + right;
}

int Fact(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Fact(n - 1);
	}
}

vector<int> Divisors(int n) {
	map<int, bool> divisors;
	for (int i = 1; i < int(sqrt(n)) + 1; i++) {
		if (n % i == 0) {
			divisors[i] = true;
			if (i != n) {
				divisors[n / i] = true;
			}
		}

	}
	vector<int> ans;
	for (auto k : divisors) {
		ans.push_back(k.first);
	}
	return ans;
}

