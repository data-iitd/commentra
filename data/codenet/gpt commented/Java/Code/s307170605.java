import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Loop to read up to 5 integers from the user
        for(int i = 0; i < 5; i++){
            // Check if the input integer is zero
            if(sc.nextInt() == 0){
                // If zero is entered, print the position (1-based index) and exit the loop
                System.out.println(i + 1);
                break; // Exit the loop as we found a zero
            }
        }
        // Close the scanner to prevent resource leaks (optional but good practice)
        sc.close();
    }
}
