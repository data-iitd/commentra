
import java.util.*;

public class s550008428{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt(); // Read the initial number from the user
        Set<Integer> a = new HashSet<>();
        a.add(s); // Insert the initial number into the set

        int d = 2;
        while(true) { // Start an infinite loop
            if(s%2==0){ // Check if the current number is even
                int x = s/2; // Halve the number
                if(a.contains(x)) { // Check if the halved number has been encountered before
                    System.out.println(d); // Output the current step count and terminate the program
                    return;
                }
                a.add(x); // Insert the halved number into the set
            } else { // The current number is odd
                int x = 3*s + 1; // Triple the number and add one
                if(a.contains(x)) { // Check if the new number has been encountered before
                    System.out.println(d); // Output the current step count and terminate the program
                    return;
                }
                a.add(x); // Insert the new number into the set
            }
            s = x; // Update the current number to the new number
            d++; // Increment the step count
        }

        System.out.println(d); // Output the step count (this line will never be reached)
    }
}
