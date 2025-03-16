import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n; // Declare an integer variable 'n' to store the number of elements
           // in the array

    int[] data; // Declare an array 'data' to store the elements of the array

    // Read the number of elements from the user
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of elements: ");
    n = sc.nextInt();

    // Allocate memory for the array of size 'n'
    data = new int[n];

    // Read each element of the array from the user
    for(int i=0; i<n; i++) {
      System.out.print("Enter element " + (i+1) + ": ");
      data[i] = sc.nextInt();
    }

    int max = 0; // Initialize'max' variable to store the maximum element
    int index; // Initialize 'index' variable to store the index of the maximum element

    // Find the maximum element and its index
    for(int i=0; i<n; i++) {
      if(data[i] > max) {
        max = data[i];
        index = i;
      }
    }

    int a = 0; // Initialize 'a' variable to store the sum of all elements except the maximum

    // Calculate the sum of all elements except the maximum
    for(int i=0; i<n; i++) {
      if(i!= index) a += data[i];
    }

    // Check if the sum of all elements except the maximum is greater than the maximum
    if(a > max) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
