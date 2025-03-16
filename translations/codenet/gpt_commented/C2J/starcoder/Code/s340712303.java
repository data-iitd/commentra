import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1, math[] = new int[2000];
        int a, num2, ans, sum = 0;
        int i, j;

        // Initialize the first element of the math array to 1
        math[0] = 1;

        // Read the number of elements for the first set
        num1 = sc.nextInt();

        // Loop to read each element and update the possible sums
        for(i = 0; i < num1; i++) {
            a = sc.nextInt(); // Read the current element
            sum += a; // Update the total sum

            // Update the math array to reflect the new possible sums
            for(j = sum - a; j >= 0; j--) {
                if(math[j] == 1) {
                    math[j + a] = 1; // Mark the new sum as possible
                }
            }
        }

        // Read the number of queries for possible sums
        num2 = sc.nextInt();

        // Loop to check if each queried sum is possible
        for(i = 0; i < num2; i++) {
            ans = sc.nextInt(); // Read the queried sum
            // Check if the queried sum is possible and print the result
            if(math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
