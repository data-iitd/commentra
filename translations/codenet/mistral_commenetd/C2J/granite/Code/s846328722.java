
import java.util.*; // Importing the Scanner class from the java.util package

// Function declaration for linear search
public static int linersearch(int [],int,int );

public static void main(String[] args){
  Scanner sc = new Scanner(System.in); // Creating a Scanner object to read user input
  int i, n; // Declaring variables i and n for array index and size
  int s[] = new int[100000]; // Declaring an array s of size 100000
  int q, t; // Declaring variables q and t for number of queries and query elements
  int count = 0; // Initializing count to zero

  // Reading the size of the array from user input
  n = sc.nextInt();

  // Reading array elements into the array s
  for(i=0;i<n;i++){
    s[i] = sc.nextInt();
  }

  // Reading the number of queries from user input
  q = sc.nextInt();

  // Looping through each query
  for(i=0;i<q;i++){
    t = sc.nextInt(); // Reading a query element from user input

    // Calling the linear search function to check if the query element is present in the array
    if( linersearch(s,n,t) ) count++; // If the query element is present, increment the count
  }

  // Printing the final count of query elements present in the array
  System.out.println(count);

  sc.close(); // Closing the Scanner object to release system resources
}

// Function definition for linear search
public static int linersearch(int a[],int n,int key){
  int i=0; // Initializing index i to zero

  // Adding the key to the end of the array for the case when the key is already present at the beginning
  a[n] = key;

  // Linear search algorithm to find the index of the key in the array
  while(a[i]!=key){
    i++; // Incrementing index i until the key is found
  }

  // Returning 1 if the key is found, and 0 otherwise
  return i!=n;
}

