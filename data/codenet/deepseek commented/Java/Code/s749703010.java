import javax.swing.text.Style;
import java.io.*;
import java.util.*;
public class Main {
    // Class and Static Members Definition
    // This block defines a Pair class to store pairs of integers and overrides the toString method for easy printing.
    // It also declares static variables for memoization and the input matrix a.
    static class Pair{
        int l,r;
        Pair(int a,int b){
            l=a;
            r=b;
        }

        @Override
        public String toString() {
            return l+" "+r;
        }
    }
    static int[][][]memo;
    static int[][]a;
    static int n;
    // Dynamic Programming Function (dp)
    // This block contains the dynamic programming function dp which calculates the minimum number of flips required.
    // It uses memoization to store results of subproblems to avoid redundant calculations.
    static int dp(int fliped,int idx,int msk){
        if (msk==(1<<n)-1)return 0;
        if (memo[fliped][idx][msk]!=-1)return memo[fliped][idx][msk];
        int x = Integer.bitCount(msk);
        int ff=0;
        int ans = (int)1e9;
        for (int i=0;i<n;i++){
            if ((msk&(1<<i))==0){
                int nf= x%2;
                if (idx==n||a[fliped][idx]<=a[(nf+(ff%2))%2][i]) {
                    ans = Math.min(ans, ff + dp((nf+(ff%2))%2, i, msk | 1 << i));
                }
                ff++;
            }
            else x--;
        }
        return memo[fliped][idx][msk]=ans;
    }
    // Main Function
    // This block is the entry point of the program.
    // It initializes the input scanner and print writer.
    // Reads the size n and the matrix a.
    // Initializes the memoization array.
    // Calls the dp function and prints the result.
    public static void main(String[] args) throws IOException, InterruptedException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        n = sc.nextInt();
        a= new int[2][n];
        for (int i =0;i<n ;i++)a[0][i]=sc.nextInt();
        for (int i =0;i<n ;i++)a[1][i]=sc.nextInt();
        memo = new int[2][n+1][1<<n];
        for (int[][]z:memo)for (int[]x:z)Arrays.fill(x,-1);
        int ans=dp(0,n,0);
        pw.println(ans>=1e8?-1:ans);
        pw.flush();
    }
    // Scanner Class
    // This block defines a Scanner class to read input from the console or file.
    // It includes methods to read integers, longs, doubles, and strings.
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }

}