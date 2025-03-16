
import java.util.ArrayList; // Importing ArrayList class
import java.util.Arrays; // Importing Arrays class
import java.util.Collections; // Importing Collections class
import java.util.Comparator; // Importing Comparator class
import java.util.HashSet; // Importing HashSet class
import java.util.List; // Importing List class
import java.util.PriorityQueue; // Importing PriorityQueue class
import java.util.Scanner; // Importing Scanner class
import java.util.Set; // Importing Set class

public class Main {

 // Initializing the Scanner object to read input from the console
 Scanner sc = new Scanner(System.in);

 // Reading the number of elements in the array from the user input
 int n = sc.nextInt();

 // Creating an integer array 'a' of size 'n' to store the input elements
 int[] a = new int[n];

 // Initializing the XOR result to 0
 int r = 0;

 // Reading the elements of the array 'a' from the user input and performing XOR operation
 for (int i = 0; i < n; i++) {
 // Reading the next integer from the user input
 a[i] = sc.nextInt();

 // Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
 r ^= a[i];
 }

 // Printing the XOR result
 for (int i = 0; i < n; i++) {
 // If it's not the first element, print a space before the current element
 if (i != 0)
 System.out.print(" ");

 // Printing the XOR result of 'r' and the current element 'a[i]'
 System.out.print(r ^ a[i]);
 }
}