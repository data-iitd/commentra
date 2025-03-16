public class Main {
    // Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
    private static final int[] dx = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    private static final int[] dy = {1, 1, 0, -1, -1, -1, 0, 1, 0};

    // Define an infinite value for comparison
    private static final int inf = Integer.MAX_VALUE;

    // Initialize a new scanner for input
    private static final Scanner next = new Scanner(System.in);

    // main function where the program execution starts
    public static void main(String[] args) {
        // Read input as a string
        String N = next.nextLine();
        byte[] b = N.getBytes(); // Convert string to byte slice
        int n = 0; // Initialize sum of digits

        // Calculate the sum of digits in the input number
        for (int i = 0; i < b.length; i++) {
            n += (b[i] - '0'); // Convert byte to int and accumulate
        }

        // Convert the string input to an integer
        int m = Integer.parseInt(N);
        // Check if the number is divisible by the sum of its digits
        if (m % n == 0) {
            System.out.println("Yes"); // Print "Yes" if divisible
        } else {
            System.out.println("No"); // Print "No" if not divisible
        }
    }

    // ---------------------------------------------------------

    // Pair class to hold a pair of integers
    private static class Pair {
        int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Pairs is a list of Pair objects
    private static class Pairs extends ArrayList<Pair> {
        // Implement Len method for sorting
        int len() {
            return this.size();
        }

        // Implement Swap method for sorting
        void swap(int i, int j) {
            Pair temp = this.get(i);
            this.set(i, this.get(j));
            this.set(j, temp);
        }

        // Implement Less method for sorting based on the second element of the Pair
        boolean less(int i, int j) {
            return this.get(i).b < this.get(j).b;
        }
    }

    // Utility functions for various operations

    // Check if a value is within a range
    private static boolean in(int c, int a, int z) {
        return c >= a && c < z;
    }

    // Check if a value is outside a range
    private static boolean out(int c, int a, int z) {
        return !in(c, a, z);
    }

    // Convert boolean to integer (1 for true, 0 for false)
    private static int btoi(boolean b) {
        return b ? 1 : 0;
    }

    // Convert integer to boolean (non-zero to true, zero to false)
    private static boolean itob(int a) {
        return a != 0;
    }

    // Return the maximum value from a list of integers
    private static int max(int... a) {
        int r = a[0];
        for (int i : a) {
            if (r < i) {
                r = i;
            }
        }
        return r;
    }

    // Return the minimum value from a list of integers
    private static int min(int... a) {
        int r = a[0];
        for (int i : a) {
            if (r > i) {
                r = i;
            }
        }
        return r;
    }

    // Calculate the sum of a slice of integers
    private static int sum(int[] a) {
        int r = 0;
        for (int i : a) {
            r += i;
        }
        return r;
    }

    // Calculate the product of a slice of integers
    private static int pro(int[] a) {
        int r = a[0];
        for (int i = 1; i < a.length; i++) {
            r *= a[i];
        }
        return r;
    }

    // Fill a slice with a specified value
    private static int[] fill(int[] a, int n) {
        for (int i = 0; i < a.length; i++) {
            a[i] = n;
        }
        return a;
    }

    // Return the minimum and maximum of two integers
    private static int[] minmax(int a, int b) {
        return a > b ? new int[]{b, a} : new int[]{a, b};
    }

    // Return the absolute value of an integer
    private static int abs(int a) {
        return a < 0 ? -a : a;
    }

    // Calculate the ceiling of a division of two integers
    private static int ceil(int a, int b) {
        return a % b != 0 ? 1 : 0;
    }

    // Print a slice of strings with space separation
    private static void printStrings(String[] out) {
        for (int i = 0; i < out.length; i++) {
            System.out.print(out[i]);
            if (i != out.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    // Print a slice of integers with space separation
    private static void printInts(int[] out) {
        for (int i = 0; i < out.length; i++) {
            System.out.print(out[i]);
            if (i != out.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
