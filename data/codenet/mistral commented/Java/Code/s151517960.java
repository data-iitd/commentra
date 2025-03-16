
import java.util.*;

public class Main {
  // Initialize Scanner object to read input from standard input
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Read the number of test cases from the standard input
    int n = sc.nextInt();

    // Initialize an empty HashMap to store the frequency of each integer
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

    // Read each test case and update the frequency of the encountered integer in the HashMap
    for(int i = 0; i < n; i++) {
      int a = sc.nextInt(); // Read an integer from the standard input

      // Check if the integer is already present in the HashMap
      if(map.containsKey(a)) {
        // If the integer is already present, increment its frequency in the HashMap
        map.put(a, map.get(a) + 1);
      } else {
        // If the integer is not present, add it to the HashMap with a frequency of 1
        map.put(a, 1);
      }
    }

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through each key (integer) in the HashMap and check if its frequency is odd
    for(int key : map.keySet()) {
      // If the frequency of the integer is odd, increment the answer variable
      if((map.get(key) % 2) == 1) ans++;
    }

    // Print the answer to the standard output
    System.out.println(ans);
  }
}

