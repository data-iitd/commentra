import java.util.*;

public class CountingSort{
  public static void main(String[] args){
    int[] a, b, c, i, j, k, max = 0, n;
    
    // Read the number of elements
    Scanner s = new Scanner(System.in);
    n = s.nextInt();
    
    // Dynamically allocate memory for arrays a and b
    a = new int[n + 1];
    b = new int[n + 1];
    
    // Read elements into array a starting from index 1 to n
    for(i = 0; i < n; i++){
      a[i + 1] = s.nextInt();
    }
    
    // Call CountingSort function to sort the array
    CountingSort(a, b, n);
    
    // Print the sorted elements starting from index 1 to n
    System.out.print(b[1]);
    for(i = 2; i < n + 1; i++) System.out.print(" " + b[i]);
    System.out.println();
  }
  
  // Function to perform Counting Sort
  public static void CountingSort(int a[], int b[], int k){
    int[] c, i, j;
    
    // Initialize array c to store the count of each element
    c = new int[I + 1];
    for(i = 0; i <= I; i++) c[i] = 0;
    
    // Count the occurrences of each element in array a
    for(j = 0; j < k; j++) c[a[j + 1]]++;
    
    // Compute the cumulative count to determine the positions of elements in the sorted array
    for(i = 1; i < I + 1; i++) c[i] += c[i - 1];
    
    // Place elements into array b in sorted order
    for(j = k; j > 0; j--){
      b[c[a[j]]] = a[j];
      c[a[j]]--;
    }
  }
}
