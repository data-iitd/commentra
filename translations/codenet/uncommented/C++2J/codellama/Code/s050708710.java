#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;


public class Main {
    public static void main(String[] args) {
        int r, g, b, n;
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        g = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();
        int ans = 0;
        for (int i = 0; i <= n / r; ++i) {
            for (int j = 0; j <= n / g; ++j) {
                int num = n - r * i - g * j;
                if (num >= 0 && num % b == 0) {
                    ++ans;
                }
            }
        }

        System.out.println(ans);
    }
}


