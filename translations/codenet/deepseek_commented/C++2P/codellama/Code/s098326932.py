
#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

// Function to calculate the minimum n/S(n)
ll f(ll N) {
    vector<ll> a(20,0); // Vector to store digits of N
    ll d = 0; // Digit counter
    while (N > 0) {
        a[d] = N % 10; // Store the last digit of N
        N /= 10; // Remove the last digit from N
        d++; // Increment the digit counter
    }
    double m = 1e18; // Initialize the minimum fraction to a large number
    ll res = N; // Initialize the result to 0
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0; // Numerator
        ll bunbo = 9 * i; // Denominator
        for (int j = d-1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
            else bunsi += a[j]; // Add the actual digit
            
            if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
            
        }
        //cout << "bb" << bunsi <<  " " << bunbo << "  " << endl;
        double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
        if (frac < m) {
            m = frac; // Update the minimum fraction
            res = bunsi; // Update the result
        }
    }
    return res; // Return the result
}

int main() {
    ll K;
    cin >> K; // Read the number of iterations
    ll N = f(1); // Initialize N with the result of f(1)
    for (ll i = 0; i < K; i++) {
        cout << N << endl; // Output the current N
        N = f(N+1); // Update N to the result of f(N+1)
    }
    

}

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

// Function to calculate the minimum n/S(n)
ll f(ll N) {
    vector<ll> a(20,0); // Vector to store digits of N
    ll d = 0; // Digit counter
    while (N > 0) {
        a[d] = N % 10; // Store the last digit of N
        N /= 10; // Remove the last digit from N
        d++; // Increment the digit counter
    }
    double m = 1e18; // Initialize the minimum fraction to a large number
    ll res = N; // Initialize the result to 0
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0; // Numerator
        ll bunbo = 9 * i; // Denominator
        for (int j = d-1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
            else bunsi += a[j]; // Add the actual digit
            
            if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
            
        }
        //cout << "bb" << bunsi <<  " " << bunbo << "  " << endl;
        double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
        if (frac < m) {
            m = frac; // Update the minimum fraction
            res = bunsi; // Update the result
        }
    }
    return res; // Return the result
}

int main() {
    ll K;
    cin >> K; // Read the number of iterations
    ll N = f(1); // Initialize N with the result of f(1)
    for (ll i = 0; i < K; i++) {
        cout << N << endl; // Output the current N
        N = f(N+1); // Update N to the result of f(N+1)
    }
    

}

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
1 <= S(n) <= 9 * (floor(log10 n) + 1)

したがって n / (9 * (floor(log10 n) + 1)) <= n/S(n) <= n

この達成される下界の内、floorの性質からその候補はちょうど10, 100, 1000...に限られる
10 ^ kのとき下界は
10^k/(9*(k+1))

11/2


その桁で一番小さいのは 19...9/S(19...9)
各桁について 99...9/S()以下なら出力?

各桁において
最もn/S(n)が小さいnは何か

n自体の差は最大10倍

1...19...9の形が可能性


editorial
つまり...
一つ目のポイント
「N以上の整数nでn/S(n)を最小にするもの」を求める
関数を作ってN <- f(N+1)を繰り返せばよい

二つ目
Nに対して、それ以上で最小にしえる候補は、
Nの下位数桁を9に置き換えたものとする
そのうち最小にするものを実際に比較する

*/

// Function to calculate the minimum n/S(n)
ll f(ll N) {
    vector<ll> a(20,0); // Vector to store digits of N
    ll d = 0; // Digit counter
    while (N > 0) {
        a[d] = N % 10; // Store the last digit of N
        N /= 10; // Remove the last digit from N
        d++; // Increment the digit counter
    }
    double m = 1e18; // Initialize the minimum fraction to a large number
    ll res = N; // Initialize the result to 0
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0; // Numerator
        ll bunbo = 9 * i; // Denominator
        for (int j = d-1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
            else bunsi += a[j]; // Add the actual digit
            
            if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
            
        }
        //cout << "bb" << bunsi <<  " " << bunbo << "  " << endl;
        double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
        if (frac < m) {
            m = frac; // Update the minimum fraction
            res = bunsi; // Update the result
        }
    }
    return res; // Return the result
}

int main() {
    ll K;
    cin >> K; // Read the number of iterations
    ll N = f(1); // Initialize N with the result of f(1)
    for (ll i = 0; i < K; i++) {
        cout << N << endl; // Output the current N
        N = f(N+1); // Update N to the result of f(N+1)
    }
    

}

#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
templ