import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers 'n' and 'd' from the standard input
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
        double a = d * 2 + 1;

        // Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
        // Print the result to the standard output
        System.out.println(Math.ceil(n / a));

        // Return 0 to indicate successful execution of the program
    }
}
