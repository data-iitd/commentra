import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Read two integers from user input
        int N = sc.nextInt();
        int R = sc.nextInt();

        // Check if the first input value N is greater than or equal to 10
        if(N >= 10) {
            // If N is 10 or more, print the value of R as is
            System.out.println(R);
        } else {
            // If N is less than 10, calculate and print R adjusted by the difference from 10
            System.out.println(R + 100 * (10 - N));
        }

        // Close the Scanner object
        sc.close();
    }
}
