import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define a function named s that takes no arguments
    public static void s() {
        // Read input as a list of integers
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] inputStrings = input.split(" ");
        int[] inputList = new int[inputStrings.length];

        for (int i = 0; i < inputStrings.length; i++) {
            inputList[i] = Integer.parseInt(inputStrings[i]);
        }

        // Sort the input list in ascending order
        Arrays.sort(inputList);

        // Initialize a variable to store the result
        String result = "";

        // Iterate through the sorted list starting from the second element
        for (int i = 1; i < inputList.length; i++) {
            // Compare the current element with the previous one
            int currentElement = inputList[i];
            int previousElement = inputList[i - 1];

            // Check if the current element is less than twice the previous element
            // and if it is not equal to the previous element
            if (currentElement < previousElement * 2 && currentElement != previousElement) {
                // If the condition is true, set the result to 'YES'
                result = "YES";
                // Break out of the loop since we have found the answer
                break;
            }
        }

        // If result is still empty, set it to 'NO'
        if (result.isEmpty()) {
            result = "NO";
        }

        // Print the result
        System.out.println(result);
    }

    public static void main(String[] args) {
        s();
    }
}

// <END-OF-CODE>
