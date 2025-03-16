import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the number of items in the input array
        int n = scanner.nextInt();
        
        // Initialize an empty list to store the input data
        List<int[]> inputArray = new ArrayList<>();
        
        // Read n items from the standard input and append them to the inputArray
        for (int i = 0; i < n; i++) {
            int S = scanner.nextInt();
            int R = scanner.nextInt();
            int H = scanner.nextInt();
            int C = scanner.nextInt();
            inputArray.add(new int[]{S, R, H, C});
        }
        
        // Initialize a set to store the outdated items
        Set<int[]> outdated = new HashSet<>();
        
        // Check for outdated items in the input array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if the current item is older and smaller than the next one
                if (inputArray.get(i)[0] < inputArray.get(j)[0] &&
                    inputArray.get(i)[1] < inputArray.get(j)[1] &&
                    inputArray.get(i)[2] < inputArray.get(j)[2]) {
                    // Add the current item to the outdated set
                    outdated.add(inputArray.get(i));
                }
            }
        }
        
        // Initialize minimum_cost and input_number to large initial values
        int minimumCost = Integer.MAX_VALUE;
        int inputNumber = 0;
        
        // Find the item with the minimum cost that is not outdated
        for (int i = 0; i < n; i++) {
            int[] currentItem = inputArray.get(i);
            int cost = currentItem[3];
            // Check if the current item is not outdated and has a smaller cost than minimumCost
            if (!outdated.contains(currentItem) && cost < minimumCost) {
                // Update minimumCost and inputNumber
                minimumCost = currentItem[3];
                inputNumber = i + 1;
            }
        }
        
        // Print the index of the item with the minimum cost that is not outdated
        System.out.println(inputNumber);
        
        scanner.close();
    }
}
// <END-OF-CODE>
