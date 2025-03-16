import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s = scanner.nextInt(); // Read the initial number from the user
        HashSet<Integer> a = new HashSet<>();
        a.add(s); // Insert the initial number into the set
        int d = 2; // Initialize step count

        while (true) { // Start an infinite loop
            int x;
            if (s % 2 == 0) { // Check if the current number is even
                x = s / 2; // Halve the number
                if (a.contains(x)) { // Check if the halved number has been encountered before
                    System.out.println(d); // Output the current step count and terminate the program
                    return;
                }
                a.add(x); // Insert the halved number into the set
            } else { // The current number is odd
                x = 3 * s + 1; // Triple the number and add one
                if (a.contains(x)) { // Check if the new number has been encountered before
                    System.out.println(d); // Output the current step count and terminate the program
                    return;
                }
                a.add(x); // Insert the new number into the set
            }
            s = x; // Update the current number to the new number
            d++; // Increment the step count
        }

        // The following line will never be reached
        // System.out.println(d); 

        scanner.close();
    }
}

// <END-OF-CODE>
