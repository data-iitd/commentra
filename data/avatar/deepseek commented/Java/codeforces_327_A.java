import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input
        
        if (scanner.hasNext()) { // Checking if there is input available
            int n = scanner.nextInt(); // Reading the size of the array
            int arr[] = new int[n]; // Declaring and initializing the array
            
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt(); // Reading the elements of the array
            }
            
            int max = Integer.MIN_VALUE; // Initializing max to the minimum possible integer value
            
            for (int i = 0; i < n; i++) { // Iterating over all possible starting points of subarrays
                for (int j = i; j < n; j++) { // Iterating over all possible ending points of subarrays
                    int x = 0;
                    int brr[] = new int[n]; // Declaring and initializing a copy of the array
                    
                    for (int k : arr) {
                        brr[x++] = k; // Copying the elements of arr to brr
                    }
                    
                    for (int k = i; k <= j; k++) { // Flipping the elements in the current subarray
                        if (brr[k] == 0) {
                            brr[k] = 1;
                        } else {
                            brr[k] = 0;
                        }
                    }
                    
                    int count = checkNo(brr); // Counting the number of 1s in the modified subarray
                    
                    if (count > max) {
                        max = count; // Updating max if the current count is greater
                    }
                }
            }
            
            if (n == 1) { // Handling the special case of a single element array
                if (arr[0] == 1) {
                    System.out.println(0);
                } else {
                    System.out.println(1);
                }
            } else {
                System.out.println(max); // Printing the maximum count of 1s found
            }
        }
    }
    
    private static int checkNo(int[] brr) { // Helper method to count the number of 1s in an array
        int val = 0;
        for (int i : brr) {
            if (i == 1) {
                ++val;
            }
        }
        return val;
    }
}
