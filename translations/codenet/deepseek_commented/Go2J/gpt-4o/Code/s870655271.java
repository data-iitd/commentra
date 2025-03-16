import java.util.Scanner;

public class Main {
    // This is the main function where the program starts execution.
    // It reads two integers N and M from the standard input.
    // Depending on the values of N and M, it calculates the number of cells in the grid.
    // Finally, it prints the result to the standard output.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans = 0;

        // If both N and M are 1, there is only one cell, so the answer is 1.
        if (N == 1 && M == 1) {
            ans += 1;
        } else if (N > 1 && M > 1) {
            // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
            ans += (N - 2) * (M - 2);
        } else {
            // If either N or M is 1, the number of cells is (N*M) - 2.
            ans += (N * M) - 2;
        }

        System.out.println(ans);
    }

    // This function returns the maximum value among the given integers.
    public static int max(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.max(x[i], res);
        }
        return res;
    }

    // This function returns the minimum value among the given integers.
    public static int min(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.min(x[i], res);
        }
        return res;
    }

    // This function returns x raised to the power of y.
    public static int pow(int x, int y) {
        return (int) Math.pow(x, y);
    }

    // This function returns the absolute value of x.
    public static int abs(int x) {
        return Math.abs(x);
    }

    // This function returns the floor value of x.
    public static int floor(double x) {
        return (int) Math.floor(x);
    }

    // This class is a custom comparator for sorting integers by their absolute values.
    public static class SortByAbs implements java.util.Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b) {
            return Integer.compare(abs(a), abs(b));
        }
    }
}

// <END-OF-CODE>
