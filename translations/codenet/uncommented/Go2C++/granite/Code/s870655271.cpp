
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return pow(x, y); }

int abs(int x) { return abs(x); }

int floor(int x) { return floor(x); }

/*  ----------------------------------------  */

struct SortBy {
    int val;
    SortBy(int val) : val(val) {}
    bool operator<(const SortBy &other) const {
        return abs(val) < abs(other.val);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg