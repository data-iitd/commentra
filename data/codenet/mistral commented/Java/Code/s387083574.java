
import java.util.Scanner; // Importing Scanner class for reading input from the console
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
    
    // Reading the number of elements in the map (N)
    int N = sc.nextInt();

    // Creating an empty HashMap with Integer keys and Integer values
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();

    // Reading the elements of the map and storing them in the HashMap
    for (int i = 1; i < N + 1; i++) {
      map.put(i, sc.nextInt()); // Reading an integer value and storing it in the HashMap with the corresponding key (i)
    }

    // Sorting the entries in the HashMap based on their values and printing the keys (sorted keys are the desired output)
    System.out.println(String.join(" ", map.entrySet().stream() // Stream of Map.Entry objects
                                        .sorted(Entry.<Integer, Integer>comparingByValue()) // Sorting based on values
                                        .map(Map.Entry::getKey) // Extracting the keys
                                        .map(String::valueOf) // Converting the keys to strings
                                        .collect(Collectors.toList()) // Collecting the strings in a List
    ));
  }
}

