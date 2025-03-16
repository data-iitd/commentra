import java.util.Scanner;

public class ConsecutiveCharacterCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input string from the user
        String soz = scanner.nextLine();
        
        // Initialize an array 'a' to store the cumulative count of consecutive characters
        // The length of 'a' is one more than the length of 'soz' to handle the base case
        int[] a = new int[soz.length() + 1];
        
        // Iterate through the string to fill the cumulative count array 'a'
        for (int i = 1; i < soz.length(); i++) {
            // Carry forward the previous count
            a[i] = a[i - 1];
            
            // If the current character is the same as the previous one, increment the count
            if (soz.charAt(i - 1) == soz.charAt(i)) {
                a[i]++;
            }
        }
        
        // Read the number of queries from the user
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initialize an empty array to store the results of each query
        int[] arr = new int[n];
        
        // Process each query
        for (int i = 0; i < n; i++) {
            // Read the start and end indices for the query
            String[] input = scanner.nextLine().split(" ");
            int m = Integer.parseInt(input[0]);
            int l = Integer.parseInt(input[1]);
            
            // Calculate the number of consecutive characters between indices m and l
            // and store the result in the 'arr' array
            arr[i] = a[l - 1] - a[m - 1];
        }
        
        // Print the results for each query
        for (int result : arr) {
            System.out.println(result);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
