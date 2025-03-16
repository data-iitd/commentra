public class Main {
    public static void main(String[] args) {
        // Step 1: Declare variables
        int N, A;

        // Step 2: Read input values
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        A = scanner.nextInt();

        // Step 3: Perform the required operation
        // We check if the remainder of N divided by 500 is less than or equal to A.
        // If the condition is true, we print "Yes"; otherwise, we print "No".
        System.out.println(N % 500 <= A ? "Yes" : "No");

        // Step 4: Return from the main function
        // We don't need to return a value in Java, so we just end the method.
    }
}
