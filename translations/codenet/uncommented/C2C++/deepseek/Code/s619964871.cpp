#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long unko = 1e12;

long long merge(vector<long long>& a, int left, int middle, int right) {
    vector<long long> l_arr(middle - left + 1), r_arr(right - middle + 1);
    long long cnt = 0;
    for (int i = 0; i < middle - left; ++i) l_arr[i] = a[left + i];
    for (int i = 0; i < right - middle; ++i) r_arr[i] = a[middle + i];
    l_arr[middle - left] = unko;
    r_arr[right - middle] = unko;
    int l = 0, r = 0;
    for (int i = 0; i < right - left; ++i) {
        if (l_arr[l] <= r_arr[r]) {
            a[left + i] = l_arr[l++];
        } else {
            a[left + i] = r_arr[r++];
            cnt += middle - left - l;
        }
    }
    return cnt;
}

long long merge_sort(vector<long long>& a, int left, int right) {
    if (left + 1 < right) {
        int middle = (left + right) / 2;
        long long x1 = merge_sort(a, left, middle);
        long long x2 = merge_sort(a, middle, right);
        long long x3 = merge(a, left, middle, right);
        return x1 + x2 + x3;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << merge_sort(a, 0, n) << endl;
    return 0;
}
