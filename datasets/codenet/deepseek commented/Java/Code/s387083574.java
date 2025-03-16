
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args) {
    // Initialize Scanner to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read the number of elements
    int N = sc.nextInt();
    
    // Create a HashMap to store the elements with their indices
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    // Read the elements and store them in the map
    for (int i = 1; i < N + 1; i++)
      map.put(i, sc.nextInt());
    
    // Sort the map by values and collect the keys, then print them as a space-separated string
    System.out.println(String.join(" ", map.entrySet().stream().sorted(Entry.<Integer, Integer>comparingByValue()).map(Map.Entry::getKey).map(String::valueOf).collect(Collectors.toList())));
  }
}

