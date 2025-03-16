import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a long integer input from the user
        long n = Long.parseLong(sc.nextLine());

        // Calculate the square root of the input number
        double sqrt = Math.sqrt(n);
        
        // Find the largest integer less than or equal to the square root
        double nearNum = Math.floor(sqrt);

        // Calculate the square of the largest integer found
        long ans = (long) Math.pow(nearNum, 2);

        // Output the result to the console
        System.out.println(ans);

        // Close the Scanner to free up resources
        sc.close();
    }
}
