import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        List<Integer> A = new ArrayList<>();
        for (String part : parts) {
            A.add(Integer.parseInt(part));
        }

        // Adding the first element of the list to the beginning of the list
        // to make the first index 0 based instead of 1 based
        A.add(0, A.get(0));
        A.remove(1);

        // Assigning the length of the list to a variable for easier reference
        int N = A.size();

        // Defining a helper function to find the index of the last occurrence of an element
        // in a list, and the index and value of the previous occurrence
        List<int[]> cut(List<int[]> array, int index) {
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
            return array;
        }

        // Defining a helper function to check if it's possible to add a certain number of elements
        // to the list while maintaining the condition that the previous element is smaller than the current one
        boolean is_possible(int K) {
            // Initializing an empty list to store the indices and values of the elements in the list
            List<int[]> dp = new ArrayList<>();
            dp.add(new int[]{A.get(0), 0});

            // Iterating through the list starting from the second element
            for (int a : A.subList(1, A.size())) {
                // If the current element is smaller than the last element in the dp list,
                // we need to cut the list at the previous index and add the current element
                if (a <= dp.get(dp.size() - 1)[0]) {
                    dp = cut(dp, a);
                }

                // Adding the current element to the dp list
                dp.add(new int[]{a, 0});

                // Initializing a flag to check if we need to add an element to the dp list
                boolean is_added = false;

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
                            is_added = true;
                            break;
                        }
                    }
                }

                // If we didn't add an element to the dp list, the current number can't be added
                if (!is_added) {
                    return false;
                }
            }
            return true;
        }

        // Defining a helper function to find the binary index of a number in the list
        int bis(int x, int y) {
            // Base case: if y is one more than x, return y
            if (y == x + 1) {
                return y;
            }

            // Recursively finding the binary index of x and y using the is_possible function
            if (is_possible((x + y) / 2)) {
                return bis(x, (x + y) / 2);
            } else {
                return bis((x + y) / 2, y);
            }
        }

        // Printing the result of the binary index function
        System.out.println(bis(0, N));
    }
}
