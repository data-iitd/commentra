import java.util.*;

public class Main {
  public static void main(String[] args) {
    int i, a, b, s; // Step 1: Declare necessary variables
    int count[] = new int[4]; // Step 2: Declare an array to store the count of connections for each node

    for(i = 0; i < 4; i++) count[i] = 0; // Step 3: Initialize the count array

    for(i = 0; i < 3; i++){ // Step 4: Read input values and update the count array
      Scanner sc = new Scanner(System.in);
      a = sc.nextInt();
      b = sc.nextInt();
      count[a-1]++; // Increment the count for node a
      count[b-1]++; // Increment the count for node b
    }

    s = 1; // Initialize s to 1
    for(i = 0; i < 4; i++) s *= count[i]; // Step 5: Calculate the product of the counts

    if(s == 4) System.out.println("YES"); // Step 6: Check if the product is 4 and print the result
    else System.out.println("NO");
  }
}
