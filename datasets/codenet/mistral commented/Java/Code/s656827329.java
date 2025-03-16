import java.util.*; // Importing the utility class Scanner from the java.util package

public class Main { // Defining a public class named Main
  public static void main(String[] args){ // Defining the main method that is the entry point of the program
    Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream
    int n = sc.nextInt(); // Reading the number of elements in the array from the user input

    // Allocating an integer array of size 'n' and initializing it with user input
    int[] a = new int[n];
    for(int i = 0;i<n;i++){
      a[i] = sc.nextInt(); // Reading each element of the array from the user input
    }

    int count = 1; // Initializing a counter variable to keep track of the number of increasing sequences
    int now = 0; // Initializing a variable 'now' to store the comparison result between the current and previous elements
    int bef = 0; // Initializing a variable 'bef' to store the comparison result between the previous and second previous elements

    // Iterating through the array starting from the second element
    for(int i = 1;i<n;i++){
      if(a[i-1]<a[i]){ // Comparing the previous and current elements
        now = 1; // Setting 'now' to 1 if the current element is greater than the previous one
      }else if(a[i-1]>a[i]){ // Comparing the previous and current elements
        now = -1; // Setting 'now' to -1 if the current element is smaller than the previous one
      }else{ // If the previous and current elements are equal
        continue; // Skipping the current iteration and moving to the next one
      }

      // Checking the condition for a new increasing sequence
      if(bef == 0){ // If the comparison result between the second previous and previous elements is 0
        bef = now; // Setting 'bef' to the current comparison result
      }
      if(bef != now){ // If the comparison result between the second previous and current elements is not the same
        count++; // Incrementing the counter variable
        bef = 0; // Resetting 'bef' to 0
      }
    }

    System.out.println(count); // Printing the number of increasing sequences found in the array
  }
}
