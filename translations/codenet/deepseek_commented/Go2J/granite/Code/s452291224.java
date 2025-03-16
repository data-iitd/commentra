

import java.util.Scanner;

public class s452291224{
    public static void main(String[] args) {
        // Declare three integer variables A, B, and C
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        
        // Check if the expression C-A+B is less than 0
        if (C - A + B < 0) {
            // If true, print "0"
            System.out.println("0");
        } else {
            // Otherwise, print the value of C-A+B
            System.out.printf("%d\n", C - A + B);
        }
    }
}
