import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input from the user
        sc.nextLine();
        
        // Parse the input into a list of integers
        List<Integer> A = new ArrayList<Integer>();
        for (String s : sc.nextLine().split(" ")) {
            A.add(Integer.parseInt(s));
        }
        
        // Filter the list to keep only non-increasing elements
        List<Integer> B = new ArrayList<Integer>();
        B.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i) > B.get(B.size() - 1)) {
                B.add(A.get(i));
            }
        }
        
        // Get the length of the filtered list
        int N = B.size();
        
        // Function to cut the array based on a given index
        public List<Integer> cut(List<Integer> array, int index) {
            // If the index is less than 1, return an empty list
            if (index < 1) {
                return new ArrayList<Integer>();
            }
            
            // If the index is less than or equal to the first element, return it with the first element's second value
            if (index <= array.get(0)) {
                List<Integer> result = new ArrayList<Integer>();
                result.add(index);
                result.add(array.get(0));
                return result;
            }
            
            // Iterate backwards through the array to find the appropriate cut point
            for (int i = array.size() - 1; i >= 0; i--) {
                if (array.get(i - 1) < index) {
                    List<Integer> result = new ArrayList<Integer>();
                    for (int j = 0; j < i; j++) {
                        result.add(array.get(j));
                    }
                    result.add(index);
                    result.add(array.get(i));
                    return result;
                }
            }
        }
        
        // Function to check if a certain condition is possible with K
        public boolean isPossible(int K) {
            // Initialize the dynamic programming array with the first element
            List<Integer> dp = new ArrayList<Integer>();
            dp.add(B.get(0));
            
            // Iterate through the remaining elements in A
            for (int i = 1; i < N; i++) {
                // If the current element is less than or equal to the last element in dp, cut dp
                if (B.get(i) <= dp.get(dp.size() - 1)) {
                    dp = cut(dp, B.get(i));
                } else {
                    // Otherwise, append the current element to dp
                    dp.add(B.get(i));
                }
                
                boolean isAdded = false;
                
                // Iterate backwards through dp to check conditions
                for (int j = dp.size() - 1; j >= 0; j--) {
                    // If the second value of the current tuple is less than K-1
                    if (dp.get(j) < K - 1) {
                        // Cut dp and increment the second value of the current tuple
                        dp = cut(dp, dp.get(j) - 1) + new ArrayList<Integer>(Arrays.asList(dp.get(j), dp.get(j) + 1));
                        
                        // If the last element in dp is less than a, append a to dp
                        if (dp.get(dp.size() - 1) < B.get(i)) {
                            dp.add(B.get(i));
                        }
                        
                        isAdded = true;
                        break;
                    }
                }
                
                // If no element was added, return False
                if (!isAdded) {
                    return false;
                }
            }
            
            // If all conditions are satisfied, return True
            return true;
        }
        
        // Function to perform binary search to find the maximum K
        public int bis(int x, int y) {
            // If the range is narrowed down to one element, return y
            if (y == x + 1) {
                return y;
            }
            // If is_possible is true for the midpoint, search in the left half
            else if (isPossible((x + y) / 2)) {
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

