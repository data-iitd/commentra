public class Main {
    public static void main(String[] args) {
        int N, D; // N, Dは1以上20以下の整数
        int ans, rem;

        // Read two integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        D = scanner.nextInt();

        // Calculate the number of groups that can be formed
        ans = N / (D * 2 + 1);
        rem = N % (D * 2 + 1);

        // If there are remaining items, increment the number of groups
        if (rem != 0) {
            ans = ans + 1;
        }

        // Print the result to standard output
        System.out.println(ans);
    }
}
