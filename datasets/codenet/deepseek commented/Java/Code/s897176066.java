
import java.util.*;
public class Main {
  public static void main(String[] args){
    // Importing Scanner class for reading input
    Scanner sc = new Scanner(System.in);
    
    // Reading the number of elements N
    int N = sc.nextInt();
    
    // Declaring an array A of size N to store the input elements
    long A[] = new long[N];
    
    // Reading N long integers into the array A
    for(int i = 0; i < N; i++){
      A[i] = sc.nextLong();
    }
    
    // Sorting the array A to facilitate comparison
    Arrays.sort(A);
    
    // Checking for duplicates in the sorted array
    for(int j = 1; j < N; j++){
      if(A[j] == A[j-1]){
        // If duplicates are found, print "NO" and exit
        System.out.println("NO");
        System.exit(0);
      }
    }
    
    // If no duplicates are found, print "YES"
    System.out.println("YES");
  }
}

