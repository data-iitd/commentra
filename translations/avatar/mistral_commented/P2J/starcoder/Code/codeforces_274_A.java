
import java.util.*;

public class Main {

    public static void main(String[] args) {

        // Take the first line of input which are two integers 'num' and 'k'
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int k = sc.nextInt();

        // Comment: Initialize 'num' and 'k' with the values from user input

        // Take the second line of input which is a list 'arr' of integers
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = sc.nextInt();
        }

        // Comment: Initialize an empty list 'arr' to store the input integers

        // Create an empty set 'different' to store unique integers
        Set<Integer> different = new HashSet<>();

        // Comment: Initialize an empty set 'different' to store unique integers

        // Sort the list 'arr' in ascending order
        Arrays.sort(arr);

        // Comment: Sort the list 'arr' in ascending order for easier comparison

        // Iterate through each integer 'x' in the sorted list 'arr'
        for (int x : arr) {

            // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
            if (x % k!= 0 ||!different.contains(x / k)) {

                // If the condition is true, add 'x' to the set 'different'
                different.add(x);

                // Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'

            }

        }

        // Comment: After the loop, 'different' stores the unique integers seen during the iteration

        // Print the maximum length of 'different'
        System.out.println(different.size());

        // Comment: Finally, print the maximum length of 'different'

    }

}

