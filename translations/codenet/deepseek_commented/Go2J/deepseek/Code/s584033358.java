public class Main {
    public static void main(String[] args) {
        // Declare integer variables n and k to store input values
        int n, k;
        
        // Read two integers from standard input and store them in n and k
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check if k is less than or equal to half of n, considering n's parity
        if (k <= (n + n % 2) / 2) {
            // If true, print "YES"
            System.out.println("YES");
        } else {
            // If false, print "NO"
            System.out.println("NO");
        }
    }
}
