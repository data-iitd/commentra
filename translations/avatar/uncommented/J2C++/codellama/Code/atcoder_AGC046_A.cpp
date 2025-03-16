
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

class FastReader {
    public:
        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    private:
        BufferedReader br;
        StringTokenizer st;
};

int main() {
    FastReader sc = new FastReader();
    PrintWriter pw = new PrintWriter(System.out);
    int x = sc.nextInt();
    int count = 0;
    int tmp = x;
    x = 0;
    while (x != 360) {
        x = x + tmp;
        if (x > 360) {
            x = x - 360;
        }
        count++;
    }
    System.out.println(count);
}

