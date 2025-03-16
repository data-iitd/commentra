import java.util.Scanner;

public class Average {
    public static void main(String[] args) {
        // Declare variables to store input value and average
        double a;
        double ave = 0;
        int i;
        
        // Create a Scanner object to read input from the keyboard
        Scanner input = new Scanner(System.in);
        
        // Loop to read 5 input values
        for (i = 0; i < 5; i++){
            // Read a double value from user input
            a = input.nextDouble();
            
            // Check if the input value is less than or equal to 40
            if (a <= 40){
                // If so, add 40 to the average instead of the input value
                ave += 40;
            }
            else {
                // Otherwise, add the input value to the average
                ave += a;
            }
        }
        
        // Calculate the average by dividing the total by the number of inputs (5)
        ave /= 5.0;
        
        // Print the calculated average, formatted as an integer
        System.out.printf("%.0f\n", ave);
    }
}
