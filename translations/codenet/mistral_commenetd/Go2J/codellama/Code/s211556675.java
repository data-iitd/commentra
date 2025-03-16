
// I/O
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

// Scanner
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return str;
    }
}

// Arithmetic
class Arithmetic {
    public static int max(int... nums) {
        int m = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (m < nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }

    public static int min(int... nums) {
        int m = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (m > nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }

    public static int abs(int x) {
        if (x > 0) {
            return x;
        }
        return -x;
    }

    public static int pow(int x, int y) {
        int res = 1;
        for (int i = 0; i < y; i++) {
            res *= x;
        }
        return res;
    }
}

// Sort
class Val implements Comparable<Val> {
    int id, num;

    public Val(int id, int num) {
        this.id = id;
        this.num = num;
    }

    @Override
    public int compareTo(Val o) {
        return this.num - o.num;
    }
}

// Main function
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read input values
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        // Find the maximum value among A, B, and C
        int ma = Arithmetic.max(A, B, C);

        // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
        int rest = 0;
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }

        // Calculate the final answer
        int answer = Arithmetic.pow(ma, K) + rest;

        // Write the answer to the output
        try {
            wtr.write(String.valueOf(answer));
            wtr.newLine();
            wtr.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

