
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s, x, d = 2; // Initialize variables s, x, and d with initial values

        s = sc.nextInt(); // Read an integer value from the standard input and assign it to variable s
        Set<Integer> a = new HashSet<Integer>(); // Create an empty set named a
        a.add(s); // Add the value of s to the set a

        while (true) { // Start an infinite loop
            if (s % 2 == 0) { // Check if s is even
                x = s / 2; // Calculate the half of s and assign it to x
                if (a.contains(x)) { // Check if x is already in the set a
                    System.out.println(d); // If yes, print the value of d and exit the program
                    return;
                }
                a.add(x); // If not, add x to the set a and assign it to s for the next iteration
            } else { // If s is odd
                x = 3 * s + 1; // Calculate 3s + 1 and assign it to x
                if (a.contains(x)) { // Check if x is already in the set a
                    System.out.println(d); // If yes, print the value of d and exit the program
                    return;
                }
                a.add(x); // If not, add x to the set a and assign it to s for the next iteration
            }
            s = x; // Update the value of s with the new value of x
            d++; // Increment the value of d for each iteration
        }

        System.out.println(d); // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the set
    }
}

