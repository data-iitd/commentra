import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, S[] = new int[N], T[] = new int[Q], c = 0;  // Declare variables: n for the number of elements, S for the sorted array, T for the query array, c for count of found keys
    
    // Read the number of elements in the sorted array S
    n = sc.nextInt();
    
    // Read the elements into the sorted array S
    for(int i = 0; i < n; i++) {
      S[i] = sc.nextInt();
    }
    
    // Read the number of queries
    q = sc.nextInt();
    
    // Process each query to check if it exists in the sorted array S
    for(int i = 0; i < q; i++) {
      T[i] = sc.nextInt();  // Read the query element into array T
      if(binarySearch(T[i]) == 1) c++;  // If the element is found, increment the count
    }
    System.out.println(c);  // Output the total count of found elements
  }
}
