import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input dimensions and the answer
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans = 0;

        // Calculate the number of valid positions based on the dimensions
        if (N == 1 && M == 1) {
            // If both dimensions are 1, there's only one position
            ans += 1;
        } else if (N > 1 && M > 1) {
            // If both dimensions are greater than 1, calculate the inner positions
            ans += (N - 2) * (M - 2);
        } else {
            // If one dimension is 1, count the edge positions
            ans += (N * M) - 2;
        }

        // Output the calculated answer
        System.out.println(ans);
    }

    // max function returns the maximum value from a variable number of integers
    public static int max(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.max(x[i], res);
        }
        return res;
    }

    // min function returns the minimum value from a variable number of integers
    public static int min(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.min(x[i], res);
        }
        return res;
    }

    // pow function calculates x raised to the power of y
    public static int pow(int x, int y) {
        return (int) Math.pow(x, y);
    }

    // abs function returns the absolute value of an integer
    public static int abs(int x) {
        return Math.abs(x);
    }

    // floor function returns the largest integer less than or equal to x
    public static int floor(double x) {
        return (int) Math.floor(x);
    }

    // SortBy class for sorting based on absolute values
    static class SortBy {
        int[] array;

        SortBy(int[] array) {
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
}

/* <END-OF-CODE> */
