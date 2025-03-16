import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user
        int x = sc.nextInt();
        
        // Close the Scanner to free up resources
        sc.close();

        // Calculate the result based on the input value
        // The formula (2199 - x) / 200 computes a specific value based on the input
        int ans = (2199 - x) / 200;
        
        // Output the calculated result to the console
        System.out.println(ans);
    }
}
