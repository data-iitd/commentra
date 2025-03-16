

import java.util.*;

public class s982630782{
    public static void main(String[] args) {
        // Initialize an empty map to store the frequency of each number
        Map<Integer, Integer> m = new HashMap<>();

        // Read the number of test cases N
        int N = ReadInt();
        // Read the N integers and store their frequencies in the map
        for (int i = 0; i < N; i++) {
            int num = ReadInt();
            m.put(num, m.getOrDefault(num, 0) + 1);
        }

        // Read the number of queries M
        int M = ReadInt();
        // For each query, read the number B and the index C, and update the frequency of the number at index C in the map
        for (int i = 0; i < M; i++) {
            int B = ReadInt(), C = ReadInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }

        // Create a list of integers from the map keys
        List<Integer> ints = new ArrayList<>(m.keySet());
        // Sort the list in descending order
        Collections.sort(ints, Collections.reverseOrder());

        // Initialize variables for calculating the sum
        int rest = N, sum = 0;
        // Iterate through the sorted list of integers
        for (int i : ints) {
            int num = m.get(i);
            // If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
            if (num >= rest) {
                sum += rest * i;
                break;
            }
            // Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
            sum += num * i;
            rest -= num;
        }

        // Print the result
        System.out.println(sum);
    }

    static int ReadInt() {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        scanner.close();
        return i;
    }
}

