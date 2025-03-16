import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take the number of elements as input
        ArrayList<int[]> inputArray = new ArrayList<>();  // Initialize an empty list to store tuples

        // Loop to take inputs and append them as tuples to inputArray
        for (int i = 0; i < n; i++) {
            int S = scanner.nextInt();
            int R = scanner.nextInt();
            int H = scanner.nextInt();
            int C = scanner.nextInt();
            inputArray.add(new int[]{S, R, H, C});  // Append the tuple to inputArray
        }

        HashSet<int[]> outdated = new HashSet<>();  // Initialize an empty set to store outdated elements

        // Nested loop to compare each element in inputArray with every other element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (inputArray.get(i)[0] < inputArray.get(j)[0] &&
                    inputArray.get(i)[1] < inputArray.get(j)[1] &&
                    inputArray.get(i)[2] < inputArray.get(j)[2]) {
                    outdated.add(inputArray.get(i));  // Add outdated elements to outdated set
                }
            }
        }

        int minimumCost = Integer.MAX_VALUE;  // Initialize minimumCost to a large value
        int inputNumber = 0;  // Initialize inputNumber to 0

        // Iterate through inputArray to find the item with the minimum cost that is not outdated
        for (int i = 0; i < n; i++) {
            int[] currentItem = inputArray.get(i);
            int cost = currentItem[3];
            if (!outdated.contains(currentItem) && cost < minimumCost) {
                minimumCost = currentItem[3];  // Update minimumCost
                inputNumber = i + 1;  // Update inputNumber
            }
        }

        System.out.println(inputNumber);  // Print the input number of the item with the minimum cost that is not outdated
    }
}
