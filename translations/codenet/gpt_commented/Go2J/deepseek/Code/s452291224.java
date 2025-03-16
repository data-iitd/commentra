public class Main {
    public static void main(String[] args) {
        // Declare three integer variables A, B, and C
        int A, B, C;
        
        // Read three integer values from standard input and store them in A, B, and C
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        
        // Check if the expression C - A + B is less than 0
        if (C - A + B < 0) {
            // If the expression is less than 0, print "0"
            System.out.println("0");
        } else {
            // If the expression is 0 or greater, print the result of C - A + B
            System.out.println(C - A + B);
        }
    }
}
