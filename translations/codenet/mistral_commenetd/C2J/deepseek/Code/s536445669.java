public class Main {
    public static void main(String[] args) {
        // Declare two integer variables 'n' and 'k'
        int n, k;

        // Read two integers from the standard input using Scanner
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check if 'n' is divisible by 'k'
        if(n % k == 0) {
            // If it is, print '0' to the standard output
            System.out.println("0");
        } else {
            // If it's not, print '1' to the standard output
            System.out.println("1");
        }
    }
}
