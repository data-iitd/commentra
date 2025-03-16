import java.util.Scanner;

public class Main {
    // Main function is the entry point of our program
    public static void main(String[] args) {
        // Declare and initialize variables
        int N, M;
        int ans = 0;

        // Read N and M from the standard input
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();

        // Check if N and M are equal to 1
        if (N == 1 && M == 1) {
            // If so, increment the ans variable
            ans += 1;
        } else if (N > 1 && M > 1) {
            // If N and M are greater than 1, calculate the area of the rectangle
            ans += (N - 2) * (M - 2);
        } else {
            // If N or M is equal to 1, calculate the number of points on the edge
            ans += (N * M) - 2;
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
    }

    // Helper functions
    public static int max(int... x) {
        // Find the maximum value in the array x
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.max(x[i], res);
        }
        return res;
    }

    public static int min(int... x) {
        // Find the minimum value in the array x
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.min(x[i], res);
        }
        return res;
    }

    public static int pow(int x, int y) {
        // Calculate x raised to the power of y
        return (int) Math.pow(x, y);
    }

    public static int abs(int x) {
        // Calculate the absolute value of x
        return Math.abs(x);
    }

    public static int floor(int x) {
        // Round x down to the nearest integer
        return (int) Math.floor(x);
    }
}

// Helper class for sorting a list of integers based on their absolute values
class SortBy {
    private int[] array;

    public SortBy(int[] array) {
        this.array = array;
    }

    public int length() {
        return array.length;
    }

    public void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public boolean less(int i, int j) {
        return abs(array[i]) < abs(array[j]);
    }
}

// <END-OF-CODE>
