
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in); // Initialize object for reading input

    int n = sc.nextInt(); // Read number of elements 'n'
    int m = sc.nextInt(); // Read number of queries'm'

    int a[] = new int[m]; // Initialize array 'a' of size'm'
    int b[] = new int[m]; // Initialize array 'b' of size'm'
    int cnt = 0; // Initialize counter for unique elements
    int t = 0; // Initialize variable for temporary storage

    for(int i = 0;i < m;i++) a[i] = sc.nextInt(); // Read elements
    for(int i = 0;i < m;i++) b[i] = sc.nextInt(); // Read queries

    quicksort(a,b,0,m-1); // Call quicksort function to sort elements

    for(int i = 0;i < m;i++){ // Iterate through sorted elements
      if(t <= a[i]){ // If current element is greater than previous element, increment counter
        t = b[i]; // Set current query as new temporary storage
        cnt++; // Increment counter
      }
    }

    System.out.println(cnt); // Print the number of unique queries
  }

  // Function to partition the array using quicksort algorithm
  public static void quicksort(int a[],int b[],int l,int r){
    int i,j,x,t; // Initialize variables

    i = l - 1; // Initialize index 'i' for smaller elements
    j = r; // Initialize index 'j' for greater elements

    x = b[r]; // Set pivot as last element

    while(1){ // While loop for partitioning
      while(b[++i] < x); // Move 'i' to next smaller element
      while(i < --j && x < b[j]); // Move 'j' to previous greater element

      if(i >= j) break; // If 'i' and 'j' meet, partitioning is done

      t = a[i]; a[i] = a[j]; a[j] = t; // Swap elements in 'a' array
      t = b[i]; b[i] = b[j]; b[j] = t; // Swap elements in 'b' array
    }

    t = a[i]; a[i] = a[r]; a[r] = t; // Swap pivot with last element in 'a' array
    t = b[i]; b[i] = b[r]; b[r] = t; // Swap pivot with last element in 'b' array
  }
}

