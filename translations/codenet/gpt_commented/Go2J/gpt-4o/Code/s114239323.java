import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = scanner.nextInt();
        // Read the heights into an array
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }

        // Initialize a dynamic programming array to store minimum costs
        int[] dp = new int[N];
        
        // Base case: cost to jump from the first to the second height
        dp[1] = Math.abs(h[0] - h[1]);

        // Fill the dp array with minimum costs for each position
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(
                dp[i - 1] + Math.abs(h[i] - h[i - 1]), // Cost from the previous height
                dp[i - 2] + Math.abs(h[i] - h[i - 2])  // Cost from two heights back
            );
        }

        // Output the minimum cost to reach the last height
        System.out.println(dp[N - 1]);
        
        scanner.close();
    }
}

/* templates */

// Max function returns the maximum value from an array of integers
public static int max(int[] a) {
    int r = a[0];
    for (int value : a) {
        if (r < value) {
            r = value;
        }
    }
    return r;
}

// Min function returns the minimum value from an array of integers
public static int min(int[] a) {
    int r = a[0];
    for (int value : a) {
        if (r > value) {
            r = value;
        }
    }
    return r;
}

// Sum function calculates the sum of an array of integers
public static int sum(int[] a) {
    int r = 0;
    for (int value : a) {
        r += value;
    }
    return r;
}

// Abs function returns the absolute value of an integer
public static int abs(int a) {
    return a < 0 ? -a : a;
}

// Pair class represents a pair of integers
class Pair {
    int a, b;

    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

// Pairs class is a collection of Pair objects
class Pairs {
    Pair[] pairs;

    Pairs(Pair[] pairs) {
        this.pairs = pairs;
    }

    public int length() {
        return pairs.length;
    }

    public void swap(int i, int j) {
        Pair temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

    public boolean less(int i, int j) {
        return pairs[i].b < pairs[j].b;
    }
}

// The following methods for reading input are not needed in Java as we use Scanner directly.

