public class Main {
    public static void main(String[] args) {
        // Declare variables for input dimensions and the answer
        int N, M;
        int ans = 0;
        
        // Read input values for N and M
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        
        // Calculate the number of valid positions based on the dimensions
        if (N == 1 && M == 1) {
            // If both dimensions are 1, there's only one position
            ans += 1;
        } else if (1 < N && 1 < M) {
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
    public static int pow(int x, int y) { return (int) Math.pow(x, y); }

    // abs function returns the absolute value of an integer
    public static int abs(int x) { return Math.abs(x); }

    // floor function returns the largest integer less than or equal to x
    public static int floor(int x) { return (int) Math.floor(x); }

    // SortBy is a type that implements sorting based on absolute values
    public static class SortBy implements java.util.Comparator<Integer> {
        public int compare(Integer a, Integer b) {
            return Integer.compare(Math.abs(a), Math.abs(b));
        }
    }
}
