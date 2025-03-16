public class Main {
    public static void main(String[] args) {
        int n, k;
        long l = 0, r = 0;  // Declare long variables for counting

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();  // Read input value for n
        k = scanner.nextInt();  // Read input value for k

        if (k % 2 == 0) {  // Check if k is even
            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == k / 2)  // Check if i modulo k equals k/2
                    l++;  // Increment l if condition is true
                else if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(l * l * l + r * r * r);  // Print the result of l^3 + r^3
        } else {  // If k is odd
            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(r * r * r);  // Print the result of r^3
        }
    }
}
