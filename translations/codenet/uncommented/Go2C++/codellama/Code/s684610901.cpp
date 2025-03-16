
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>

using namespace std;

// sort
struct pair {
    int64_t index;
    int64_t p1;
    int64_t p2;
};

bool operator<(const pair& lhs, const pair& rhs) {
    return lhs.index < rhs.index;
}

bool operator>(const pair& lhs, const pair& rhs) {
    return lhs.index > rhs.index;
}

bool operator==(const pair& lhs, const pair& rhs) {
    return lhs.index == rhs.index;
}

bool operator!=(const pair& lhs, const pair& rhs) {
    return lhs.index != rhs.index;
}

bool operator<=(const pair& lhs, const pair& rhs) {
    return lhs.index <= rhs.index;
}

bool operator>=(const pair& lhs, const pair& rhs) {
    return lhs.index >= rhs.index;
}

// sort
struct Int64Slice {
    vector<int64_t> v;
    Int64Slice(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice2 {
    vector<int64_t> v;
    Int64Slice2(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice2& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice2& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice3 {
    vector<int64_t> v;
    Int64Slice3(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice3& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice3& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice4 {
    vector<int64_t> v;
    Int64Slice4(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice4& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice4& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice5 {
    vector<int64_t> v;
    Int64Slice5(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice5& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice5& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice6 {
    vector<int64_t> v;
    Int64Slice6(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice6& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice6& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice7 {
    vector<int64_t> v;
    Int64Slice7(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice7& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice7& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

// sort
struct Int64Slice8 {
    vector<int64_t> v;
    Int64Slice8(vector<int64_t> v) : v(v) {}
    int64_t size() { return v.size(); }
    int64_t get(int64_t i) { return v[i]; }
    void set(int64_t i, int64_t val) { v[i] = val; }
    bool less(int64_t i, int64_t j) { return v[i] < v[j]; }
    bool greater(int64_t i, int64_t j) { return v[i] > v[j]; }
    bool equal(int64_t i, int64_t j) { return v[i] == v[j]; }
    bool lessequal(int64_t i, int64_t j) { return v[i] <= v[j]; }
    bool greaterequal(int64_t i, int64_t j) { return v[i] >= v[j]; }
    void swap(int64_t i, int64_t j) {
        int64_t tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
};

void sort(Int64Slice8& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (slice.less(j, i)) {
                slice.swap(i, j);
            }
        }
    }
}

void stableSort(Int64Slice8& slice) {
    int64_t n = slice.size();
    for (int64_t i = 0; i < n; i++) {
     