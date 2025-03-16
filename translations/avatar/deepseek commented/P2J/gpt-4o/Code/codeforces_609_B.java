import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the list of elements
        int[] lst = new int[n];
        for (int i = 0; i < n; i++) {
            lst[i] = scanner.nextInt();
        }
        
        // Initialize a map to store the frequency of elements
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
        // Populate the map with the frequency of each element in the list
        for (int i = 0; i < n; i++) {
            frequencyMap.put(lst[i], frequencyMap.getOrDefault(lst[i], 0) + 1);
        }
        
        // Initialize the result variable to store the final result
        long res = 0;
        
        // Iterate over the list to calculate the result
        for (int i = 0; i < n; i++) {
            if (frequencyMap.get(lst[i]) > 1) {
                // Calculate the number of pairs that can be formed with the current element
                res += n - i - frequencyMap.get(lst[i]);
                // Decrement the frequency of the current element in the map
                frequencyMap.put(lst[i], frequencyMap.get(lst[i]) - 1);
            } else {
                // If the frequency is not greater than 1, calculate the number of pairs
                res += n - i - 1;
            }
        }
        
        // Print the final result
        System.out.println(res);
        
        scanner.close();
    }
}
// <END-OF-CODE>
