
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

class Io {
public:
    Io() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);
        tokens = new vector<string>();
        nextToken = 0;
    }

    ~Io() {
        delete reader;
        delete writer;
    }

    string NextLine() {
        string line;
        while (true) {
            line = reader->readLine();
            if (line!= null) {
                break;
            }
        }
        return line;
    }

    string Next() {
        while (nextToken >= tokens->size()) {
            string line = NextLine();
            tokens = new vector<string>(split(line,''));
            nextToken = 0;
        }
        string r = (*tokens)[nextToken];
        nextToken++;
        return r;
    }

    int Int() {
        int i = stoi(Next());
        return i;
    }

    float Float() {
        float i = stof(Next());
        return i;
    }

    void PrintLn(vector<int> a) {
        for (int i = 0; i < a.size(); i++) {
            writer->print(a[i]);
            if (i!= a.size() - 1) {
                writer->print(" ");
            }
        }
        writer->println();
    }

    void PrintLn(vector<string> a) {
        for (int i = 0; i < a.size(); i++) {
            writer->print(a[i]);
            if (i!= a.size() - 1) {
                writer->print(" ");
            }
        }
        writer->println();
    }

    void PrintIntLn(vector<int> a) {
        PrintLn(a);
    }

    void PrintStringLn(vector<string> a) {
        PrintLn(a);
    }

    void Flush() {
        writer->flush();
    }

private:
    BufferedReader* reader;
    PrintWriter* writer;
    vector<string>* tokens;
    int nextToken;

    vector<string> split(string line, char delimiter) {
        vector<string> result;
        stringstream ss(line);
        string item;
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }
};

int Abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int Pow(int p, int q) {
    return pow(p, q);
}

int Min(vector<int> nums) {
    int res = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        res = min(res, nums[i]);
    }
    return res;
}

int Max(vector<int> nums) {
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
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }
    return a * b / GCD(a, b);
}

vector<int> CumSum(vector<int> nums) {
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
        sums[i + 1] = sums[i] + nums[i];
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
        return {};
    }
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) {
        vector<int> rest = Remove(nums, i);
        vector<vector<int>> lists = Permutations(rest);
        if (lists.empty()) {
            lists.push_back({});
        }

        for (int j = 0; j < lists.size(); j++) {
            lists[j].push_back(nums[i]);
            ans.push_back(lists[j]);
        }
    }
    return ans;
}

vector<int> Remove(vector<int> nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]!= target) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

vector<vector<int>> PowerSet(vector<int> nums) {
    int size = Pow(2, nums.size());
    vector<vector<int>> result(size);

    int idx = 0;
    result[idx] = {};
    idx++;

    for (int i = 0; i < nums.size(); i++) {
        int max = idx;
        for (int j = 0; j < max; j++) {
            result[idx] = CopyAndAppend(result[j], nums[i]);
            idx++;
        }
    }

    return result;
}

vector<int> CopyAndAppend(vector<int> nums, int n) {
    vector<int> dst(nums.size() + 1);
    copy(nums.begin(), nums.end(), dst.begin());
    dst[nums.size()] = n;
    return dst;
}

vector<vector<int>> Combination(vector<int> nums, int k) {
    int size = Pow(2, nums.size());
    vector<vector<int>> result(size);

    int bi = (1 << uint(k)) - 1;
    int max = 1 << uint(nums.size());
    int idx = 0;

    for (int i = 0; i < max; i++) {
        int flags = bi;
        vector<int> s;
        for (int j = 0; j < nums.size(); j++) {
            if (flags % 2!= 0) {
                s.push_back(nums[j]);
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

// CombinationCountはnCmを計算する<fim_middle>}

int main() {
	Io io;
	int n = io.Int();
	int m = io.Int();
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		nums[i] = io.Int();
	}
	vector<vector<int>> ans = Permutations(nums);
	io.PrintIntLn(ans);
	io.Flush();
	return 0;
}
