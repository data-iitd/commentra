
import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
    while(sc.hasNext()) { // Loop until there is no more input
      String str = sc.next(); // Read a string input from the user
      String[] strArr = str.split(","); // Split the input string by commas
      int[] l = new int[10]; // Initialize an array to store 10 integers
      int d = 0; // Initialize a variable to keep track of the sum of elements
      
      // Loop through the first 10 elements of strArr, parse them into integers, and store them in l
      for (int i = 0; i < 10; i++) {
        l[i] = Integer.parseInt(strArr[i]);
        d += l[i];
      }
      
      // Parse two integers from the input string and store them in an array v
      int[] v = {Integer.parseInt(strArr[10]),Integer.parseInt(strArr[11])};
      
      // Calculate the average speed of the two values in v
      double t = (double)d/(v[0] + v[1]);
      
      // Reset d to 0
      d = 0;
      
      // Loop through the first 11 elements of strArr
      for(int i = 0; i < 11; i++) {
        // Check if the distance covered by the first vehicle in time t is less than or equal to d
        if(v[0]*t <= d) {
          System.out.println(i); // Print the index if the condition is true
          break; // Exit the loop
        }
        else {
          d += l[i]; // Add the value of l[i] to d
        }
      }
    }
  }
}