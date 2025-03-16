
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Initialize Scanner to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read the number of elements
    int n = sc.nextInt();
    
    // Initialize a HashMap to store the frequency of each integer
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    // Loop to read n integers and update the HashMap with their frequencies
    for(int i = 0; i < n; i++) {
      int a = sc.nextInt();
      if(map.containsKey(a)) {
        // If the integer is already in the HashMap, increment its frequency
        map.put(a, map.get(a) + 1);
      } else {
        // If the integer is not in the HashMap, add it with a frequency of 1
        map.put(a, 1);
      }
    }
    
    // Initialize a variable to count the number of integers with odd frequencies
    int ans = 0;
    
    // Iterate over the keys of the HashMap and check if their frequencies are odd
    for(int key : map.keySet()) {
      if((map.get(key) % 2) == 1) ans++;
    }
    
    // Print the number of integers with odd frequencies
    System.out.println(ans);
  }
}

