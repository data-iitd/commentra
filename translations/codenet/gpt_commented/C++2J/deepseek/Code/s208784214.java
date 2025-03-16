public class Main {
    public static void main(String[] args) {
        // Declare two integer variables N and A
        int N, A;

        // Read two integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        A = scanner.nextInt();

        // Check if the remainder of N divided by 500 is less than or equal to A
        // If true, print "Yes"; otherwise, print "No"
        System.out.println(N % 500 <= A ? "Yes" : "No");
    }
}
