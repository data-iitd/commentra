
import java.util.ArrayList; // Importing ArrayList class for creating dynamic arrays
import java.util.Arrays; // Importing Arrays class for creating fixed size arrays
import java.util.List; // Importing List interface for creating dynamic arrays
import java.util.Scanner; // Importing Scanner class for reading user input

public class Main {

 // Function to find permutations of a given string
 public static List<String> permutation(List<String> list, String target, String ans) {
 if (target.length() <= 1) { // Base case: if the target string length is less than or equal to 1
 list.add(ans + target); // Add the current permutation to the list
 } else {
 for (int i = 0; i < target.length(); i++) { // Iterate through each character in the target string
 permutation(list, target.substring(0, i) + target.substring(i + 1), ans + target.charAt(i)); // Recursive call to find permutations of the remaining string
 }
 }
 return list; // Return the list of permutations
 }

 // Main function to read user input and find the sum of the permutations
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read user input
 Integer n; // Declare an integer variable to store the number of test cases

 // Read the number of test cases from the user
 n = Integer.parseInt(scanner.next());

 String number = ""; // Declare an empty string variable to store the number string
 for (int i = 1; i <= n; i++) { // Iterate through each test case and create the number string
 number += i;
 }

 List<String> listA = new ArrayList<>(); // Declare an empty ArrayList to store the permutations
 permutation(listA, number, ""); // Call the permutation function to find all permutations of the number string

 int sum = 0; // Declare an integer variable to store the sum of the indices of the matching permutations
 for (int j = 0; j < line.length; j++) { // Iterate through each line read from the user
 for (int i = 0; i < listA.size(); i++) { // Iterate through each permutation in the list
 if (listA.get(i).equals(line[j][0])) { // Check if the current permutation matches the current line
 if (sum == 0) { // If this is the first matching permutation
 sum += i; // Add the index of the matching permutation to the sum
 } else { // If there is already a matching permutation in the sum
 sum -= i; // Subtract the index of the previous matching permutation from the sum
 }
 }
 }
 }

 System.out.println(Math.abs(sum)); // Print the absolute value of the sum
 }
}