
public class Main {
    public static void main(String[] args) {
        int n, i, a;
        
        // Read an integer n from the standard input
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        // Iterate from 1 to n (inclusive)
        for (i = 1; i <= n; i++) {
            a = i;
            
            // Check if the current number i is divisible by 3
            if ((a % 3) == 0) {
                System.out.print(" " + i);
            } else {
                // Check each digit of i to see if it contains the digit 3
                while (a > 0) {
                    if ((a % 10) == 3) {
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

