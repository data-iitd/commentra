import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the console
    Scanner sc = new Scanner(System.in);
    
    // Read the number of elements (N) from the input
    int N = sc.nextInt();
    
    // Initialize a HashMap to store the integer values with their corresponding indices
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    // Loop through the range from 1 to N and populate the map with input values
    for (int i = 1; i < N + 1; i++)
      map.put(i, sc.nextInt());
    
    // Sort the map entries by their values and collect the keys in a sorted order
    // Convert the keys to a space-separated string and print the result
    System.out.println(String.join(" ", 
      map.entrySet().stream()
        .sorted(Entry.<Integer, Integer>comparingByValue())
        .map(Map.Entry::getKey)
        .map(String::valueOf)
        .collect(Collectors.toList())
    ));
  }
}
