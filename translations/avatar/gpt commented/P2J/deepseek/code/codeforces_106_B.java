import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of items from user input
        int n = scanner.nextInt();
        
        // Initialize an empty list to store the input items
        List<int[]> inputArray = new ArrayList<>();
        
        // Loop to read each item's attributes (S, R, H, C)
        for (int i = 0; i < n; i++) {
            // Read the attributes S, R, H, C and convert them to integers
            int S = scanner.nextInt();
            int R = scanner.nextInt();
            int H = scanner.nextInt();
            int C = scanner.nextInt();
            // Append the attributes as an array to the inputArray
            inputArray.add(new int[]{S, R, H, C});
        }
        
        // Initialize a list to keep track of outdated items
        List<int[]> outdated = new ArrayList<>();
        
        // Compare each item with every other item to find outdated ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if item i is outdated compared to item j
                if (inputArray.get(i)[0] < inputArray.get(j)[0] && 
                    inputArray.get(i)[1] < inputArray.get(j)[1] && 
                    inputArray.get(i)[2] < inputArray.get(j)[2]) {
                    // If outdated, add item i to the outdated list
                    outdated.add(inputArray.get(i));
                }
            }
        }
        
        // Convert the outdated list to a set to remove duplicates
        Set<int[]> outdatedSet = new HashSet<>(outdated);
        
        // Initialize variables to track the minimum cost and corresponding item index
        int minimumCost = Integer.MAX_VALUE;
        int inputNumber = 0;
        
        // Loop through the input items to find the one with the minimum cost that is not outdated
        for (int i = 0; i < n; i++) {
            int[] currentItem = inputArray.get(i);
            int cost = currentItem[3];  // Get the cost of the current item
            // Check if the current item is not outdated and has a lower cost than the current minimum
            if (!outdatedSet.contains(currentItem) && cost < minimumCost) {
                minimumCost = currentItem[3];  // Update the minimum cost
                inputNumber = i + 1;  // Store the index of the current item (1-based index)
            }
        }
        
        // Print the index of the item with the minimum cost that is not outdated
        System.out.println(inputNumber);
    }
}
