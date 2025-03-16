import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the list
        int n = scanner.nextInt();
        
        // Initialize a map to count occurrences of each integer
        Map<Integer, Integer> countMap = new HashMap<>();
        
        // Read the list of integers and count the occurrences
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        // Initialize a variable to store the count of pairs
        long c = 0;
        
        // Iterate over each integer in the count map
        for (int key : countMap.keySet()) {
            // If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
            if (key == 0) {
                int count = countMap.get(key);
                c += (long) count * (count - 1);
            } else {
                // If the integer is not 0, check if its negative counterpart is also in the map
                if (countMap.containsKey(-key)) {
                    c += (long) countMap.get(key) * countMap.get(-key);
                }
            }
        }
        
        // Print the result of c / 2, which represents the number of unique pairs
        System.out.println(c / 2);
        
        scanner.close();
    }
}
// <END-OF-CODE>
