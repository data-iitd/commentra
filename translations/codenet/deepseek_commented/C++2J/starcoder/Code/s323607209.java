import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object

        int n = sc.nextInt();  // Read input values for n and k
        int k = sc.nextInt();

        if (k % 2 == 0) {  // Check if k is even
            int l = 0, r = 0;  // Declare integer variables for counting

            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == k / 2)  // Check if i modulo k equals k/2
                    l++;  // Increment l if condition is true
                else if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(l * l * l + r * r * r);  // Print the result of l^3 + r^3
        } else {  // If k is odd
            int r = 0;  // Declare integer variable for counting

            for (int i = 1; i <= n; i++) {  // Iterate from 1 to n
                if (i % k == 0)  // Check if i modulo k equals 0
                    r++;  // Increment r if condition is true
            }
            System.out.println(r * r * r);  // Print the result of r^3
        }

        sc.close();  // Close the Scanner object
    }
}

