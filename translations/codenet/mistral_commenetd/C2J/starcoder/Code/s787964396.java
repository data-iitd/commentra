import java.util.*;

public class CountingSort{
  public static void main(String[] args){
    // Read the number of elements 'n' from the user
    System.out.print("Enter the number of elements: ");
    int n = Integer.parseInt(System.in.readLine());

    // Declare and initialize an array 'a' of size 'n'
    int a[] = new int[n];
    for(int i = 0; i < n; i++)a[i] = Integer.parseInt(System.in.readLine());

    // Call the CountingSort function to sort the array 'a' using counting sort algorithm
    CountingSort(a);

    // Print the sorted elements of array 'a'
    for(int i = 0; i < n; i++)System.out.print(a[i] + " ");
    System.out.println();
  }

  // Function to perform counting sort algorithm
  public static void CountingSort(int a[]){
    // Declare an array 'c' of size I to store the count of occurrences of each element
    int c[] = new int[I];

    // Initialize all elements of array 'c' to zero
    for(int i = 0; i < I; i++)c[i] = 0;

    // Count the occurrences of each element in array 'a' and store it in array 'c'
    for(int j = 0; j < a.length; j++)c[a[j]]++;

    // Calculate the cumulative sum of all elements in array 'c'
    for(int i = 1; i < I; i++)c[i] += c[i-1];

    // Sort the array 'a' by placing each element 'a[j]' at its correct position in array 'a'
    for(int j = a.length-1; j >= 0; j--){
      a[c[a[j]]-1] = a[j];
      c[a[j]]--;
    }
  }
}
