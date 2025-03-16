
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Initialize a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Use a for loop to read 5 integers from the standard input
        for(int i = 0; i < 5; i++){
            // Read the next integer from the standard input
            int num = sc.nextInt();

            // Check if the integer read is equal to 0
            if(num == 0){
                // If so, print the current value of i to the standard output and break out of the loop
                System.out.println(i+1);
                break;
            }
        }

        // Close the Scanner object to free up system resources
        sc.close();
    }
}

