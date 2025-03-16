import java.util.Scanner;

public class Main {
    // Declare variables to store high, low, and the difference (sa)
    int high;
    int low;
    int sa;
    
    // Method to solve the problem
    public void solve(){
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Loop to read input for 7 days
        for(int i = 0; i < 7; i++){
            // Read the high temperature for the day
            high = sc.nextInt();
            // Read the low temperature for the day
            low = sc.nextInt();
            // Calculate the difference between high and low temperatures
            sa = high - low;
            // Print the calculated difference
            System.out.println(sa);
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
    
    // Main method to execute the program
    public static void main(String[] args){
        // Create an instance of the Main class
        Main obj = new Main();
        // Call the solve method to perform the calculations
        obj.solve();
    }
}
