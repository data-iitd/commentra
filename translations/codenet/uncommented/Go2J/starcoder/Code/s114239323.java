package main
 
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

public class Main {
    public static void main(String[] args) {
        int N = nextInt();
        int[] h = nextInts(N);
        
        int[] dp = new int[N];
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
        }
        dp[1] = Math.abs(h[0] - h[1]);
        
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]),
                             dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }
        
        System.out.println(dp[N - 1]);
    }
}

/* templates */


public int Max(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}
 
public int Min(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}
 
public int Sum(int[] a) {
    int r = 0;
    for (int i = 0; i < a.length; i++) {
        r += a[i];
    }
    return r;
}
 
public int Abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}
 
class Pair {
    int a, b;
    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
 
class Pairs extends ArrayList<Pair> {
    public Pairs(int n) {
        super(n);
    }
}

var nextReader = new NewScanner();

class NewScanner {
    public NewScanner() {
    }
    public String next() {
        try {
            return new BufferedReader(new InputStreamReader(System.in)).readLine();
        } catch (IOException e) {
            throw new RuntimeException();
        }
    }
}

public String nextString() {
    return nextReader.next();
}
 
public int nextInt() {
    return Integer.parseInt(nextReader.next());
}
 
public int[] nextInts(int n) {
    int[] r = new int[n];
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

public String[] nextStrings(int n) {
    String[] r = new String[n];
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

public double nextFloat() {
    return Double.parseDouble(nextReader.next());
}

