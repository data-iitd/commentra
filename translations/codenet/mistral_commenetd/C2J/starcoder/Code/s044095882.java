
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n; // Declare a variable to store the number of elements in the array

    System.out.print("Enter the number of elements: ");
    n = sc.nextLong(); // Read the number of elements from the standard input and store it in n

    long[] a = new long[(int) n]; // Declare an array of size n to store the input numbers
    long[] count = new long[(int) n]; // Declare an array of size n to store the count of occurrences of each number

    System.out.print("Enter " + n + " numbers:\n");
    for (long i = 0; i < n; i++) { // Initialize the array a with input numbers
      a[i] = sc.nextLong();
    }

    System.out.print("Initializing count array with zeros:\n");
    for (long i = 0; i < n; i++) { // Initialize all elements of the count array to zero
      count[i] = 0;
    }

    System.out.print("Counting occurrences:\n");
    for (long i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
      count[a[i]-1]++;
    }

    System.out.print("Printing the contents of the count array:\n");
    for (long i = 0; i < n; i++) { // Print the contents of the count array to the standard output
      System.out.println(count[i]);
    }

    System.out.print("Program completed successfully.\n");
  }
}

