public class Main {
    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int r;
        while ((r = a % b) > 0) {
            a = b;
            b = r;
        }
        return b;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Read the number of integers.

        int ans = scanner.nextInt();

        // Read the first integer and initialize the answer.

        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt();
            ans = gcd(ans, a);
        }

        // Read the remaining integers, compute their GCD with the current answer,
        // and update the answer accordingly.

        System.out.println(ans);

        // Print the final result, which is the GCD of all the input integers.
    }
}
