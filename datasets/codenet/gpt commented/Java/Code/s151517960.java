import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the console
    Scanner sc = new Scanner(System.in);
    
    // Read the number of integers to be processed
    int n = sc.nextInt();
    
    // Initialize a HashMap to store the frequency of each integer
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    // Loop to read 'n' integers and populate the frequency map
    for(int i = 0; i < n; i++) {
      int a = sc.nextInt(); // Read the next integer
      
      // Check if the integer is already in the map
      if(map.containsKey(a)) {
        // If it exists, increment its count
        map.put(a, map.get(a) + 1);
      } else {
        // If it does not exist, add it to the map with a count of 1
        map.put(a, 1);
      }
    }
    
    // Initialize a variable to count how many integers have an odd frequency
    int ans = 0;
    
    // Iterate over the keys in the frequency map
    for(int key : map.keySet()) {
      // Check if the frequency of the current integer is odd
      if((map.get(key) % 2) == 1) 
        ans++; // Increment the count of odd frequencies
    }
    
    // Output the count of integers that have an odd frequency
    System.out.println(ans);
  }
}
