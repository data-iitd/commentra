
import java.util.Scanner;

public class Main {
    // Instance variables to store the input values and the result of subtraction
    int high;
    int low;
    int sa;
    
    // Method to read inputs, calculate the difference, and print the result
    public void solve(){
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Loop to read two integers seven times
        for(int i=0;i<7;i++){
            // Read the high and low values from the user
            high = sc.nextInt();
            low = sc.nextInt();
            
            // Calculate the difference between high and low
            sa = high - low;
            
            // Print the result of the subtraction
            System.out.println(sa);
        }
    }
    
    // Main method to execute the program
    public static void main(String[] args){
        // Create an instance of the Main class
        Main obj = new Main();
        
        // Call the solve method to start the program
        obj.solve();
    }
}

