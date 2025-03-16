import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Helper function to find the index of the last occurrence of an element
    // in a list, and the index and value of the previous occurrence
    public static List<int[]> cut(List<int[]> array, int index) {
        // Base case: if index is less than 1, return an empty list
        if (index < 1) {
            return new ArrayList<>();
        }

        // Base case: if index is less than or equal to the first element in the array
        if (index <= array.get(0)[0]) {
            List<int[]> result = new ArrayList<>();
            result.add(new int[]{index, array.get(0)[1]});
            return result;
        }

        // Iterating through the array from the end to the beginning
        for (int i = array.size() - 1; i > 0; i--) {
            // If the previous element is smaller than the index, return the sublist up to that index
            if (array.get(i - 1)[0] < index) {
                List<int[]> result = new ArrayList<>(array.subList(0, i));
                result.add(new int[]{index, array.get(i)[1]});
                return result;
            }
        }
        return new ArrayList<>();
    }

    // Helper function to check if it's possible to add a certain number of elements
    // to the list while maintaining the condition that the previous element is smaller than the current one
    public static boolean isPossible(int K, List<Integer> A) {
        List<int[]> dp = new ArrayList<>();
        dp.add(new int[]{A.get(0), 0});

        // Iterating through the list starting from the second element
        for (int i = 1; i < A.size(); i++) {
            int a = A.get(i);
            // If the current element is smaller than the last element in the dp list,
            // we need to cut the list at the previous index and add the current element
            if (a <= dp.get(dp.size() - 1)[0]) {
                dp = cut(dp, a);
            }

            // Adding the current element to the dp list
            dp.add(new int[]{a, 0});

            // Initializing a flag to check if we need to add an element to the dp list
            boolean isAdded = false;

            // Iterating through the dp list from the end to the beginning
            for (int j = dp.size() - 1; j >= 0; j--) {
                // If the previous element has a smaller value and enough space to add the current element,
                // we need to cut the list at the previous index and add the current element
                if (dp.get(j)[1] < K - 1) {
                    dp = cut(dp, dp.get(j)[0] - 1);
                    dp.add(new int[]{dp.get(j)[0], dp.get(j)[1] + 1});

                    // Checking if the last element in the dp list is smaller than the current element
                    if (dp.get(dp.size() - 1)[0] < a) {
                        dp.add(new int[]{a, 0});
                        isAdded = true;
                        break;
                    }
                }
            }

            // If we didn't add an element to the dp list, the current number can't be added
            if (!isAdded) {
                return false;
            }
        }
        return true;
    }

    // Helper function to find the binary index of a number in the list
    public static int bis(int x, int y, List<Integer> A) {
        // Base case: if y is one more than x, return y
        if (y == x + 1) {
            return y;
        }

        // Recursively finding the binary index of x and y using the isPossible function
        if (isPossible((x + y) / 2, A)) {
            return bis(x, (x + y) / 2, A);
        } else {
            return bis((x + y) / 2, y, A);
        }
    }

    public static void main(String[] args) {
        // Taking input from user and converting it into a list of integers
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        List<Integer> A = new ArrayList<>();
        for (String s : inputArray) {
            A.add(Integer.parseInt(s));
        }

        // Adding the first element of the list to the beginning of the list
        // to make the first index 0 based instead of 1 based
        List<Integer> modifiedA = new ArrayList<>();
        modifiedA.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i - 1) >= A.get(i)) {
                modifiedA.add(A.get(i));
            }
        }

        // Assigning the length of the list to a variable for easier reference
        int N = modifiedA.size();

        // Printing the result of the binary index function
        System.out.println(bis(0, N, modifiedA));
    }
}
// <END-OF-CODE>
