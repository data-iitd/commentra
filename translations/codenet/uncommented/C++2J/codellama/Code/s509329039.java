#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

public class Main {
    public static void main(String[] args) {
        int n,m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int[] s = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
            c[i] = sc.nextInt();
            s[i]--;
        }
        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i);
            if (st.length() != n) {
                continue;
            }
            //cerr<<st<<endl;
            int f = 1;
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (char) (c[j] + '0')) {

                } else {
                    f = 0;
                }
            }
            if (f) {
                System.out.println(i);
                return;
            }

        }
        System.out.println(-1);
    }
}
