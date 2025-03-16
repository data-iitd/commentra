public class Main {
    public static void main(String[] args) {
        int n, i;
        
        // Read an integer n from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Iterate from 1 to n (inclusive)
        for (i = 1; i <= n; i++) {
            int a = i;
            
            // Check if the current number i is divisible by 3
            if (a % 3 == 0) {
                System.out.print(" " + i);
            } else {
                // Check each digit of i to see if it contains the digit 3
                for (; a != 0; ) {
                    if (a % 10 == 3) {
                        System.out.print(" " + i);
                        a = 0;
                    }
                    a = a / 10;
                }
            }
        }
        
        // Print a newline character
        System.out.println();
    }
}
