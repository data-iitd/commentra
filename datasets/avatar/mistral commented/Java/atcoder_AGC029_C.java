
import java.io.BufferedReader; // BufferedReader for reading input
import java.io.InputStreamReader; // InputStreamReader for wrapping the System.in
import java.io.IOException; // Exception for I/O errors
import java.util.Arrays; // Utility class for array manipulation
import java.util.TreeMap; // Sorted map implementation

public class Main {

 private int n; // Number of elements in the array 'a'
 private int[] a; // Array of integers
 private TreeMap<Integer, Integer> s; // Sorted map to store the count of each element

 public static void main(String[] args) {
 Main m = new Main(); // Create an instance of Main class
 m.solve(); // Call the solve method to find the solution
 }

 private void set() {
 try {
 BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader for reading input
 String line = br.readLine(); // Read the first line containing the number of elements 'n'
 n = Integer.parseInt(line); // Parse the string to integer 'n'
 line = br.readLine(); // Read the second line containing the elements of the array 'a'
 a = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray(); // Parse the string to an integer array 'a'
 s = new TreeMap<>(); // Initialize an empty TreeMap 's'
 } catch (IOException e) {
 e.printStackTrace(); // Print the stack trace if any I/O error occurs
 }
 }

 private void solve() {
 set(); // Call the set method to read the input
 int ng = 0; // Initialize the lower bound of the search range
 int ok = n; // Initialize the upper bound of the search range

 while (ok - ng > 1) { // Run the while loop until the search range is narrowed down to a single element
 int k = (ng + ok) / 2; // Calculate the middle index of the search range
 if (isPossible(k)) { // If the middle index 'k' is a valid solution, update the upper bound
 ok = k;
 } else { // Otherwise, update the lower bound
 ng = k;
 }
 }

 System.out.println(ok); // Print the solution
 }

 private boolean isPossible(int k) {
 s.clear(); // Clear the TreeMap 's' before processing the new condition
 int current = 0; // Initialize the current index in the array 'a'

 for (int ai : a) { // Iterate through each element in the array 'a'
 if (ai <= current) { // If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
 if (k == 1) return false; // If 'k' is 1, return false as there is no possible solution

 while (!s.isEmpty() && s.lastKey() >= ai) { // If there is an element greater than or equal to 'ai' in the TreeMap, remove it
 s.pollLastEntry();
 }

 int p = ai - 1; // Calculate the previous index 'p'
 while (true) { // Find the previous index 'p' with the count 'k' in the TreeMap
 if (p < 0) return false; // If 'p' is out of the array bounds, return false

 int sp = s.getOrDefault(p, 0) + 1; // Get the count of 'p' in the TreeMap or initialize it to 1
 s.put(p, sp); // Update the count of 'p' in the TreeMap

 if (sp == k) { // If the count of 'p' is equal to 'k', remove it and move to the previous index
 s.remove(p);
 p--;
 } else { // Otherwise, break the loop
 break;
 }
 }
 }
 current = ai; // Update the current index
 }

 return true; // If all elements in the array 'a' are processed, return true as a valid solution is found
 }
}

These comments should provide a clear understanding of the code logic and flow. Let me know if you need any further assistance.