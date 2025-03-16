// Main function starts here
public static void main(String[] args)
{
  // Initialize variables
  int N, T; // N is the number of elements in the array A, T is an input value

  // Read input values from the standard input
  Scanner sc = new Scanner(System.in);
  N = sc.nextInt();
  T = sc.nextInt();

  // Allocate memory for an integer array A of size N
  int[] A = new int[N];

  // Allocate memory for a vector B of size N
  int[] B = new int[N];

  // Read integer values from the standard input and store them in array A
  for(int i = 0; i < N; i++) A[i] = sc.nextInt();

  // Initialize variable m with the minimum value among the first two elements of array A
  int m = A[0];
  if(A[1] < m) m = A[1];

  // Set the first element of vector B with the difference between the second element of array A and the initialized value of m
  B[1] = A[1] - m;

  // Iterate through the remaining elements of array A starting from the third one
  for(int i = 2; i < N; i++){
    // Update the value of m with the minimum value between it and the current element of array A
    m = Math.min(m, A[i]);

    // Set the current element of vector B with the difference between the current element of array A and the updated value of m
    B[i] = A[i] - m;
  }

  // Print the output value to the standard output
  System.out.println(count(B));

  // End of main function
}

// Function to count the number of elements in vector B that are equal to the maximum element of vector B
public static int count(int[] B){
  int max = B[0];
  for(int i = 1; i < B.length; i++){
    if(B[i] > max) max = B[i];
  }
  int count = 0;
  for(int i = 0; i < B.length; i++){
    if(B[i] == max) count++;
  }
  return count;
}

