import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize a map to store the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
        // Read the number of test cases N
        int N = scanner.nextInt();
        // Read the N integers and store their frequencies in the map
        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Read the number of queries M
        int M = scanner.nextInt();
        // For each query, read the number B and the index C, and update the frequency of the number at index C in the map
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            frequencyMap.put(C, frequencyMap.getOrDefault(C, 0) + B);
        }

        // Create a list of integers from the map keys
        List<Integer> keys = new ArrayList<>(frequencyMap.keySet());
        
        // Sort the list in descending order
        Collections.sort(keys, Collections.reverseOrder());

        // Initialize variables for calculating the sum
        int rest = N;
        int sum = 0;
        
        // Iterate through the sorted list of integers
        for (int key : keys) {
            int num = frequencyMap.get(key);
            // If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
            if (num >= rest) {
                sum += rest * key;
                break;
            }
            // Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
            sum += num * key;
            rest -= num;
        }

        // Print the result
        System.out.println(sum);
    }
}
// <END-OF-CODE>
