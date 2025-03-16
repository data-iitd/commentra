import java.util.Scanner; // Step 1: Import necessary libraries
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Step 2: Create a scanner object
        int a = sc.nextInt(); // Step 3: Read input values
        int b = sc.nextInt();
        if (a <= 8 && b <= 8) System.out.println("Yay!"); // Step 4: Check the condition and print the result
    }
}
