import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input from the user
        scanner.nextLine();
        
        // Parse the input into a list of integers
        List<Integer> A = new ArrayList<>();
        String[] input = scanner.nextLine().split(" ");
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }
        
        // Filter the list to keep only non-increasing elements
        List<Integer> filteredList = new ArrayList<>();
        filteredList.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i - 1) >= A.get(i)) {
                filteredList.add(A.get(i));
            }
        }
        
        // Get the length of the filtered list
        int N = filteredList.size();
        
        // Function to cut the array based on a given index
        List<int[]> cut(List<int[]> array, int index) {
            // If the index is less than 1, return an empty list
            if (index < 1) {
                return new ArrayList<>();
            }
            
            // If the index is less than or equal to the first element, return it with the first element's second value
            if (index <= array.get(0)[0]) {
                List<int[]> result = new ArrayList<>();
                result.add(new int[]{index, array.get(0)[1]});
                return result;
            }
            
            // Iterate backwards through the array to find the appropriate cut point
            for (int i = array.size() - 1; i > 0; i--) {
                if (array.get(i - 1)[0] < index) {
                    List<int[]> result = new ArrayList<>(array.subList(0, i));
                    result.add(new int[]{index, array.get(i)[1]});
                    return result;
                }
            }
            return array;
        }
        
        // Function to check if a certain condition is possible with K
        boolean is_possible(int K) {
            // Initialize the dynamic programming array with the first element
            List<int[]> dp = new ArrayList<>();
            dp.add(new int[]{filteredList.get(0), 0});
            
            // Iterate through the remaining elements in A
            for (int a : filteredList.subList(1, filteredList.size())) {
                // If the current element is less than or equal to the last element in dp, cut dp
                if (a <= dp.get(dp.size() - 1)[0]) {
                    dp = cut(dp, a);
                } else {
                    // Otherwise, append the current element to dp
                    dp.add(new int[]{a, 0});
                }
                
                boolean is_added = false;
                
                // Iterate backwards through dp to check conditions
                for (int j = dp.size() - 1; j >= 0; j--) {
                    // If the second value of the current tuple is less than K-1
                    if (dp.get(j)[1] < K - 1) {
                        // Cut dp and increment the second value of the current tuple
                        dp = cut(dp, dp.get(j)[0] - 1);
                        dp.add(new int[]{dp.get(j)[0], dp.get(j)[1] + 1});
                        
                        // If the last element in dp is less than a, append a to dp
                        if (dp.get(dp.size() - 1)[0] < a) {
                            dp.add(new int[]{a, 0});
                        }
                        
                        is_added = true;
                        break;
                    }
                }
                
                // If no element was added, return false
                if (!is_added) {
                    return false;
                }
            }
            
            // If all conditions are satisfied, return true
            return true;
        }
        
        // Function to perform binary search to find the maximum K
        int bis(int x, int y) {
            // If the range is narrowed down to one element, return y
            if (y == x + 1) {
                return y;
            }
            // If is_possible is true for the midpoint, search in the left half
            else if (is_possible((x + y) / 2)) {
                return bis(x, (x + y) / 2);
            }
            // Otherwise, search in the right half
            else {
                return bis((x + y) / 2, y);
            }
        }
        
        // Print the result of the binary search
        System.out.println(bis(0, N));
    }
}
