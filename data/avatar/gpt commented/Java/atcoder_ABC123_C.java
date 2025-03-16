import java.util.ArrayDeque; 
import java.util.Queue; 
import java.util.Random; 
import java.util.Scanner; 

public class Main {
    // Create a Scanner object for user input
    private static Scanner sc = new Scanner(System.in); 

    public static void main(String[] args) {
        // Read a long integer N from user input
        long N = sc.nextLong(); 
        
        // Initialize a variable to hold the minimum value
        long min = 0; 
        
        // Loop to read five long integers and find the minimum
        for (int i = 0; i < 5; i++) {
            // For the first iteration, directly assign the value to min
            if (i == 0) {
                min = sc.nextLong(); 
            } else {
                // For subsequent iterations, update min if a smaller value is found
                min = Math.min(min, sc.nextLong()); 
            }
        }
        
        // Calculate the result by dividing N by min, rounding up, and adding 4
        p((long) Math.ceil((double) N / min) + 4); 
    }

    // Overloaded method to print a String result
    static void p(String ans) { 
        System.out.println(ans); 
    }

    // Overloaded method to print an int result
    static void p(int ans) { 
        System.out.println(ans); 
    }

    // Overloaded method to print an empty line
    static void p() { 
        System.out.println(); 
    }

    // Overloaded method to print a long result
    static void p(long ans) { 
        System.out.println(ans); 
    }

    // Overloaded method to print a double result
    static void p(double ans) { 
        System.out.println(ans); 
    }
}
