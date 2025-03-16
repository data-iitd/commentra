# Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Custom input function
class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
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
}

// Function to get a list of numbers separated by a space
ArrayList<Integer> get_nums_l() {
    ArrayList<Integer> arr = new ArrayList<>();
    FastReader sc = new FastReader();
    String[] temp = sc.nextLine().split(" ");
    for (int i = 0; i < temp.length; i++) {
        arr.add(Integer.parseInt(temp[i]));
    }
    return arr;
}

// Function to get a list of numbers of a given length
ArrayList<Integer> get_nums_n(int n) {
    ArrayList<Integer> arr = new ArrayList<>();
    FastReader sc = new FastReader();
    for (int i = 0; i < n; i++) {
        arr.add(sc.nextInt());
    }
    return arr;
}

// Function to get all integers from a file
ArrayList<Integer> get_all_int() {
    ArrayList<Integer> arr = new ArrayList<>();
    FastReader sc = new FastReader();
    String[] temp = sc.nextLine().split(" ");
    for (int i = 0; i < temp.length; i++) {
        arr.add(Integer.parseInt(temp[i]));
    }
    return arr;
}

// Define constants
int INF = 999999999;
int MOD = 1000000007;

// Get the number of test cases
int n = sc.nextInt();

// Base case for the recursion
if (n == 1) {
    System.out.println(0);
    return;
}

// Function to prime factorize a number
ArrayList<Integer> prime_factorize(int n) {
    ArrayList<Integer> a = new ArrayList<>();
    while (n % 2 == 0) {
        a.add(2);
        n /= 2;
    }
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            a.add(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n != 1) {
        a.add(n);
    }
    return a;
}

// Function to calculate the factorial of a number
ArrayList<Integer> factorial(int n) {
    ArrayList<Integer> arr = new ArrayList<>();
    if (arr.size() == 0) {
        arr.add(n);
    }
    return arr;
}

// Initialize variables
ArrayList<Integer> fac_ = prime_factorize(n);
ArrayList<Integer> fac = new ArrayList<>();
int ans = 0;

// Calculate the answer
for (int p : fac_) {
    int x = Collections.frequency(fac_, p);
    for (int i = 1; i < 1000000000; i++) {
        if (x >= i) {
            x -= i;
            ans += 1;
        } else {
            break;
        }
    }
}

// Print the answer
System.out.println(ans);

