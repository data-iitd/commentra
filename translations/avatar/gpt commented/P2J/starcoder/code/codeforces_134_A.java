import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();

        // Read the list of integers
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        // Calculate the sum of the list
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }

        // Initialize an empty list to store indices
        List<Integer> d = new ArrayList<>();

        // Iterate through each element in the list
        for (int i = 0; i < n; i++) {
            // Check if removing the current element results in an average equal to the current element
            if ((x - w[i]) / (n - 1) == w[i]) {
                // If the condition is met, append the 1-based index to the list
                d.add(i + 1);
            }
        }

        // Print the number of valid indices found
        System.out.println(d.size());

        // Print the valid indices as a space-separated string
        System.out.print(d.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }
}

