
import java.util.Scanner;

public class s639919182{
    public static void main(String[] args) {
        // Declare an array to hold 10 integers
        int[] v = new int[10];
        
        // Initialize a variable to hold the sum of the integers
        int sum = 0;
        
        // Declare a loop variable
        int i;
        
        // Prompt the user to enter 10 integers and store them in the array
        Scanner scanner = new Scanner(System.in);
        for(i = 0; i < 10; i++)
            v[i] = scanner.nextInt();
        
        // Calculate the sum of the integers stored in the array
        for(i = 0; i < 10; i++)
            sum += v[i];
        
        // Output the calculated sum to the console
        System.out.println(sum);
        
        // Return 0 to indicate successful completion of the program
        System.exit(0);
    }
}
