
import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class Main { // Defining the Main class
    int high; // Declaring an integer variable 'high' to store the high value
    int low; // Declaring an integer variable 'low' to store the low value
    int sa; // Declaring an integer variable 'sa' to store the difference between high and low

    public void solve(){ // Defining a method 'solve'
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
        for(int i=0;i<7;i++){ // Starting a for loop that runs 7 times
            high = sc.nextInt(); // Reading the high value from the console and storing it in the 'high' variable
            low = sc.nextInt(); // Reading the low value from the console and storing it in the 'low' variable
            sa = high - low; // Calculating the difference between 'high' and 'low' and storing it in the 'sa' variable
            System.out.println(sa); // Printing the difference to the console
        }
        sc.close(); // Closing the Scanner object to save system resources
    }

    public static void main(String[] args){ // Defining the main method
        Main obj = new Main(); // Creating a new instance of the Main class
        obj.solve(); // Calling the 'solve' method to execute the code inside it
    }
}

