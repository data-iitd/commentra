
import java.util.ArrayList; // Importing ArrayList class from java.util package
import java.util.Arrays; // Importing Arrays class from java.util package
import java.util.Collections; // Importing Collections class from java.util package
import java.util.Comparator; // Importing Comparator class from java.util package
import java.util.HashSet; // Importing HashSet class from java.util package
import java.util.List; // Importing List class from java.util package
import java.util.PriorityQueue; // Importing PriorityQueue class from java.util package
import java.util.Scanner; // Importing Scanner class from java.util package
import java.util.Set; // Importing Set class from java.util package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
        int n = sc.nextInt(); // Read the number of elements (n) from the user
        int[] a = new int[n]; // Initialize an array 'a' of size n to store the elements
        int r = 0; // Initialize a variable 'r' to store the result of XOR operation

        // Read the elements of the array 'a' from the user and perform XOR operation on each element
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            r ^= a[i];
        }

        // Print the result of XOR operation for each element in the array 'a'
        for (int i = 0; i < n; i++) {
            if (i != 0) System.out.print(" "); // Print a space before each element except the first one
            System.out.print(r ^ a[i]); // Print the result of XOR operation for each element
        }
    }
}

