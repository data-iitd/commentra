
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000000

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int pow(int p, int q) {
    return (int)pow(p, q);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int lcm(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    } else {
        return a * b / gcd(a, b);
    }
}

int* cumsum(int* nums, int n) {
    int* sums = (int*)malloc(sizeof(int) * (n + 1));
    sums[0] = 0;

    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int bisect_left(int* nums, int left, int right, int target) {
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
        return bisect_left(nums, left, mid, target);
    } else if (nums[mid] < target) {
        return bisect_left(nums, mid + 1, right, target);
    }
    return 0;
}

int** permutations(int* nums, int n) {
    int** ans = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        int* rest = remove(nums, nums[i]);
        int** lists = permutations(rest, n - 1);
        if (lists == NULL) {
            lists = (int**)malloc(sizeof(int*) * 1);
            lists[0] = NULL;
        }

        for (int j = 0; j < n - 1; j++) {
            lists[j] = (int*)malloc(sizeof(int) * (n + 1));
            for (int k = 0; k < n; k++) {
                lists[j][k] = lists[j][k + 1];
            }
            lists[j][n] = nums[i];
        }

        for (int j = 0; j < n - 1; j++) {
            ans[i] = lists[j];
        }
    }
    return ans;
}

int* remove(int* nums, int target) {
    int* result = (int*)malloc(sizeof(int) * n);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != target) {
            result[idx] = nums[i];
            idx++;
        }
    }
    return result;
}

int** powerset(int* nums, int n) {
    int** ans = (int**)malloc(sizeof(int*) * pow(2, n));
    for (int i = 0; i < pow(2, n); i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
    }

    int bi = (1 << n) - 1;
    int max = 1 << (n + 1);
    int idx = 0;

    while (bi < max) {
        int flags = bi;
        int* s = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            if (flags % 2 != 0) {
                s[i] = nums[i];
            }
            flags /= 2;
        }
        ans[idx] = s;
        idx++;
        bi = bisect_left(nums, bi, max, bi);
    }
    return ans;
}

int** combination(int* nums, int n) {
    int** ans = (int**)malloc(sizeof(int*) * combination_count(n, n, MAX_INPUT));
    for (int i = 0; i < combination_count(n, n, MAX_INPUT); i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
    }

    int bi = (1 << n) - 1;
    int max = 1 << (n + 1);
    int idx = 0;

    while (bi < max) {
        int flags = bi;
        int* s = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            if (flags % 2 != 0) {
                s[i] = nums[i];
            }
            flags /= 2;
        }
        ans[idx] = s;
        idx++;
        bi = bisect_left(nums, bi, max, bi);
    }
    return ans;
}

int combination_count(int n, int m, int max_input) {
    int** memo = (int**)malloc(sizeof(int*) * max_input * max_input);
    for (int i = 0; i < max_input * max_input; i++) {
        memo[i] = (int*)malloc(sizeof(int) * max_input);
    }
    return combination_count(n, m, memo);
}

int combination_count(int n, int m, int** memo) {
    if (n == m || m == 0) {
        return 1;
    }

    int left, lOK;
    int right, rOK;

    left = memo[n - 1][m - 1];
    right = memo[n - 1][m];
    lOK = left != 0;
    rOK = right != 0;

    if (lOK && rOK) {
        return left + right;
    }

    if (lOK) {
        right = combination_count(n - 1, m, memo);
        memo[n - 1][m] = right;
        return left + right;
    }

    if (rOK) {
        left = combination_count(n - 1, m - 1, memo);
        memo[n - 1][m - 1] = left;
        return left + right;
    }

    left = combination_count(n - 1, m - 1, memo);
    right = combination_count(n - 1, m, memo);
    memo[n - 1][m - 1] = left;
    memo[n - 1][m] = right;
    return left + right;
}

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int* divisors(int n) {
    int* divisors = (int*)malloc(sizeof(int) * n);
    for (int i = 1; i < int(sqrt(n)) + 1; i++) {
        if (n % i == 0) {
            divisors[i] = true;
            if (i != n) {
                divisors[n / i] = true;
            }
        }
    }
    int* ans = (int*)malloc(sizeof(int) * n);
    int idx = 0;
    for (int k = 0; k < n; k++) {
        if (divisors[k]) {
            ans[idx] = k;
            idx++;
        }
    }
    return ans;
}

int main() {
    // Initialize input/output handling
    int n = 0;
    scanf("%d", &n);

    int* aa = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    int* cumsum = cumsum(aa, n);

    int ans = 2020202020;

    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, abs(cumsum[n - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printf("%d\n", ans);
    return 0;
}

