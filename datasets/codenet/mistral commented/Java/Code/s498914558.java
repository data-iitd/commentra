import java.util.*; // We import the Java Util library to use the Scanner class

public class Main { // This is the main class
  public static void main(String[]args) { // This is the main method where the program starts
    Scanner sc=new Scanner(System.in); // Create a new Scanner object to read input from the console
    
    int n=sc.nextInt(); int m=sc.nextInt(); // Read the first two integers as input (number of elements and capacity)

    int po[]=new int[n]; // Create an integer array of size n to store the weights of the objects

    for(int i=0;i<n;i++){ // Iterate through the array to read the weights of each object and subtract it from the capacity
      po[i]=sc.nextInt();
      m-=po[i]; // Subtract the weight of the current object from the remaining capacity
    }

    Arrays.sort(po); // Sort the array in ascending order

    System.out.println(n+m/po[0]); // Print the result which is the number of objects plus the number of objects that can be added with the remaining capacity
  }
}
