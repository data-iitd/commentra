import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Define the number of items in the input array
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        // Initialize an empty list to store the input data
        ArrayList<int[]> inputArray = new ArrayList<>();

        // Read n items from the standard input and append them to the inputArray
        for (int i = 0; i < n; i++) {
            String[] parts = scanner.nextLine().split(" ");
            int S = Integer.parseInt(parts[0]);
            int R = Integer.parseInt(parts[1]);
            int H = Integer.parseInt(parts[2]);
            int C = Integer.parseInt(parts[3]);
            inputArray.add(new int[]{S, R, H, C});
        }

        // Initialize an empty list to store the outdated items
        ArrayList<int[]> outdated = new ArrayList<>();

        // Check for outdated items in the input array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if the current item is older and smaller than the next one
                if (inputArray.get(i)[0] < inputArray.get(j)[0] &&
                    inputArray.get(i)[1] < inputArray.get(j)[1] &&
                    inputArray.get(i)[2] < inputArray.get(j)[2]) {
                    // Append the current item to the outdated list
                    outdated.add(inputArray.get(i));
                }
            }
        }

        // Convert the outdated list to a set to remove duplicates
        HashSet<int[]> outdatedSet = new HashSet<>(outdated);

        // Initialize minimum_cost and input_number to large initial values
        int minimum_cost = Integer.MAX_VALUE;
        int input_number = 0;

        // Find the item with the minimum cost that is not outdated
        for (int i = 0; i < n; i++) {
            int[] current_item = inputArray.get(i);
            int cost = current_item[3];
            // Check if the current item is not outdated and has a smaller cost than minimum_cost
            if (!outdatedSet.contains(current_item) && cost < minimum_cost) {
                // Update minimum_cost and input_number
                minimum_cost = current_item[3];
                input_number = i + 1;
            }
        }

        // Print the index of the item with the minimum cost that is not outdated
        System.out.println(input_number);
    }
}
