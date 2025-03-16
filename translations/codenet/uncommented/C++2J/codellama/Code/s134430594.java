#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

class Sp {
    public:
        const int LIM = 20; 
        const int N = 2e5 + 7;

        int mn[LIM][N];
        int pw[N];

        void init(vector<int> a) {
            int n = (int)a.size();
            for (int i = 0; i < n; i++) {
                mn[0][i] = a[i]; 
            }
            for (int i = 0; i + 1 < LIM; i++) {
                for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                    mn[i + 1][j] = max(mn[i][j], mn[i][j + (1 << i)]);
                }
            }
            pw[1] = 0;
            for (int i = 2; i < N; i++) {
                pw[i] = pw[i / 2] + 1;
            }
        } 

        int get(int l, int r) {
            r++;
            int p = pw[r - l];
            return min(mn[p][l], mn[p][r - (1 << p)]);
        }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] dl = new int[n];
        for (int i = 0; i < n; i++) {
            dl[i] = i - a[i];
        }
        int ans = 0;
        ArrayList<Ban> bans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            ans += a[r];
            i = r;
            bans.add(new Ban(r - a[r], r, r - a[r]));
        }
        Sp sp = new Sp();
        sp.init(Arrays.asList(dl));
        for (Ban t : bans) {
            // cerr << t.l + 1 << ' ' << t.r + 1 << ' ' << t.val << endl;
            if (sp.get(t.l, t.r) > t.val) {
                System.out.println(- 1);
                return;
            }
        }
        System.out.println(ans);
    }
}

class Ban {
    public int l;
    public int r;
    public int val;

    public Ban() {}

    public Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
}

