
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter wtr = new PrintWriter(System.out);
        int N, ss, ans, A, B, C;

        // sort
        // array := []int{5, 1, 4, 2, 3}
        // sort.Sort(sort.IntSlice(array))

        String[] X = sc.nextLine().split(" ");

        // Z := strings.Split(nextLine(), " ")
        // n, _ := strconv.Atoi(input[0])

        N = Integer.parseInt(X[0]);
        A = Integer.parseInt(X[1]);
        B = Integer.parseInt(X[2]);
        C = Integer.parseInt(X[3]);

        // K, _ := strconv.Atoi(X[2]) //strconv.ParseInt(X[2], 10, 64)

        // Y := strings.Split(nextLine(), " ")

        int[] arr = new int[N];
        int[] dp = new int[N];
        ans = 10000;
        ss = A + B + C;
        // sort.Sort(sort.Reverse(sort.IntSlice(arr)))
        for (int i = 0; i < N; i++) {
            String[] Y = sc.nextLine().split(" ");

            arr[i] = Integer.parseInt(Y[0]);

        }
        dfs(dp, 0, arr);

        /*文字列連結高速化
       初期化:buf := make([]byte, 0,N+1)
       連結:buf=append(buf,str)
       出力:string(buf)
        */
        // sort.Sort(sort.Reverse(dp[M][N]))

        wtr.println(ans);

        wtr.flush();
    }

    public static void dfs(int[] dp, int times, int[] arr) {
        if (times >= N) {
            ans = min(ans, calc(dp, arr));
            return;
        }

        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr);
        }
    }

    public static int calc(int[] dp, int[] arr) {
        int cost, AA, BB, CC;

        int[] memo = new int[4];
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                AA += arr[i];
            } else if (dp[i] == 2) {
                BB += arr[i];
            } else if (dp[i] == 3) {
                CC += arr[i];
            }
        }
        cost = abs(A - AA) + abs(B - BB) + abs(C - CC);

        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }

        return cost;
    }

    public static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    public static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    public static int com(int a, int b) {

        if (a > b) {
            return 0;
        }
        return 0; //abs(a - b)
    }

    public static int abs(int a) {
        if (a < 0) {
            return a * -1;
        }
        return a;
    }

    public static int sum(int[] a) {
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        return sum;
    }

    public static class item implements Comparable<item> {
        int x;
        // y     int
        // point int

        public int compareTo(item o) {
            return this.x - o.x;
        }
    }

    public static class que extends PriorityQueue<item> {
        public que() {
            super();
        }

        public void push(int in) {
            item i = new item();
            i.x = in;
            this.add(i);
            this.sort();
        }

        public int pop() {
            item i = this.poll();
            return i.x;
        }

        public int peek() {
            item i = this.peek();
            return i.x;
        }
    }

    // END-OF-CODE
}