import java.util.*;

class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the console
    Scanner sc = new Scanner(System.in);
    
    // Read the number of pairs to be processed
    int n = sc.nextInt();
    
    // Initialize a counter for consecutive equal pairs
    int c = 0;
    
    // Flag to indicate if there are at least 3 consecutive equal pairs
    int flg = 0;
    
    // Loop through n pairs of integers
    while(n-- > 0) {
      // Read the next pair of integers
      int x = sc.nextInt();
      int y = sc.nextInt();
      
      // Check if the two integers are equal
      if(x == y) {
        // Increment the counter for consecutive equal pairs
        c++;
        
        // Check if the count of consecutive equal pairs is 3 or more
        if(c >= 3) {
          // Set the flag to indicate that we found 3 or more consecutive equal pairs
          flg = 1;
        }
      } else {
        // Reset the counter if the pair is not equal
        c = 0;
      }
    }
    
    // Check the flag to determine the output
    if(flg == 0) {
      // If no consecutive equal pairs were found, print "No"
      System.out.println("No");
    } else {
      // If at least 3 consecutive equal pairs were found, print "Yes"
      System.out.println("Yes");
    }
  }
}
