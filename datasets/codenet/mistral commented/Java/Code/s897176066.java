import java.util.*; // Import the Scanner class and other utility classes

public class Main {
  public static void main(String[] args){
    // Create a new Scanner object to read input from the standard input
    Scanner sc =new Scanner(System.in);

    // Read the first integer N from the user input
    int N =sc.nextInt();

    // Create an array A of length N to store the input long integers
    long A[] =new long[N];

    // Use a for loop to read N long integers from the user input and store them in the A array
    for(int i=0;i<N;i++){
      A[i]=sc.nextLong(); // Read the next long integer from the user input and store it in the A array at index i
    }

    // Use the Arrays.sort method to sort the elements of the A array in ascending order
    Arrays.sort(A);

    // Use another for loop to check if there are any consecutive duplicate elements in the A array
    for(int j=1;j<N;j++){
      // Check if the current element is equal to the previous element
      if(A[j]==A[j-1]){
        // If so, print "NO" and exit the program
        System.out.println("NO");
        System.exit(0);
      }
    }

    // If we have gone through the entire array without finding any consecutive duplicate elements, print "YES"
    System.out.println("YES");
  }
}
