import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables a, b, c, d, and e of type int
        int a, b, c, d, e;

        // Read input values for variables a, b, c, d, and e from the standard input
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();

        // Create an array named al with the values of variables a, b, c, d, and e
        int[] al = {a, b, c, d, e};

        // Iterate through each element i in the array al starting from the index 0
        for (int n = 0; n < al.length; n++) {
            int i = al[n];
            // Check if the current element i is equal to 0
            if (i == 0) {
                // Print the index number n+1 as output
                System.out.println(n + 1);
                // Break the loop as soon as the first zero element is found
                break;
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
