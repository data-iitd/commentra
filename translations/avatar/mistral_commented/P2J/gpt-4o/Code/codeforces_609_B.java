import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Function to read input as a list of integers
    public static int[] readInput() {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] result = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            result[i] = Integer.parseInt(input[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        // Read number of elements 'n' and size 'm' of the list 'lst'
        int[] nm = readInput();
        int n = nm[0];
        int m = nm[1];

        // Initialize an empty array 'lst' to store the elements
        int[] lst = readInput();
        Map<Integer, Integer> l = new HashMap<>();

        // Iterate through each element in the list 'lst'
        for (int i = 0; i < n; i++) {
            // If the current element is not already present in the map 'l'
            l.put(lst[i], l.getOrDefault(lst[i], 0) + 1);
        }

        // Initialize result variable 'res' to 0
        long res = 0;

        // Iterate through each element in the list 'lst'
        for (int i = 0; i < n; i++) {
            // If the frequency of the current element in the map 'l' is greater than 1
            if (l.get(lst[i]) > 1) {
                // Calculate the number of elements that have a smaller frequency than the current element
                // and add it to the result variable 'res'
                res += n - i - l.get(lst[i]);
                // Decrease the frequency of the current element in the map 'l' by 1
                l.put(lst[i], l.get(lst[i]) - 1);
            } else {
                // If the frequency of the current element in the map 'l' is equal to 1
                // Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
                res += n - i - 1;
            }
        }

        // Print the final result
        System.out.println(res);
    }
}
// <END-OF-CODE>
