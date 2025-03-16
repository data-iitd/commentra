import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Create a map to store the counts of integers
        Map<Integer, Integer> m = new HashMap<>();
        
        // Read the number of initial elements (N) and the number of operations (M)
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Read N integers and store their counts in the map
        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        
        // Perform M operations to update the map with new integers and their counts
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }
        
        // Create a list of integers from the map keys
        List<Integer> ints = new ArrayList<>(m.keySet());
        
        // Sort the list of integers in descending order
        Collections.sort(ints, Collections.reverseOrder());
        
        // Initialize variables to keep track of the remaining elements and the sum
        int rest = N;
        int sum = 0;
        
        // Iterate through the sorted integers and calculate the sum based on the conditions
        for (int i : ints) {
            int num = m.get(i);
            if (num >= rest) {
                sum += rest * i;
                break;
            }
            sum += num * i;
            rest -= num;
        }
        
        // Print the calculated sum
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
