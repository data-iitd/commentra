import java.util.*; // Step 1: Import necessary classes

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Step 2: Initialize Scanner object
        int n = sc.nextInt(); // Step 3: Read input values
        long k = sc.nextLong(); // Step 3: Read input values
        long[] arr = new long[n]; // Step 3: Read input values
        HashSet<Long> set = new HashSet<>(); // Step 3: Read input values

        for (int i = 0; i < n; i++) { // Step 4: Read array elements
            arr[i] = sc.nextLong();
        }

        Arrays.sort(arr); // Step 5: Sort the array

        int count = 0; // Step 6: Initialize count variable

        for (int i = 0; i < n; i++) { // Step 7: Iterate through the array
            if (arr[i] % k != 0) { // Check if the element is not divisible by k
                count++; // Increment the count
                set.add(arr[i]); // Add the element to the set
            } else if (!set.contains(arr[i] / k)) { // Check if the quotient is not in the set
                count++; // Increment the count
                set.add(arr[i]); // Add the element to the set
            }
        }

        System.out.println(count); // Step 8: Print the result
    }
}
