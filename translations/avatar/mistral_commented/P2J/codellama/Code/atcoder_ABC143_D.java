// Import the java.util.Arrays class for efficient sorting of arrays
import java.util.Arrays;

// Read the number of elements 'n' and a list 'l' of 'n' integers from standard input
int n = Integer.parseInt(new java.util.Scanner(System.in).nextLine());
int[] l = new int[n];
for (int i = 0; i < n; i++) {
    l[i] = Integer.parseInt(new java.util.Scanner(System.in).nextLine());
}

// Sort the list 'l' in ascending order
Arrays.sort(l);

// Initialize an answer variable 'ans' to zero
int ans = 0;

// Iterate through each pair of indices 'i' and 'j' in the list 'l'
for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
        // Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
        int a = l[i];
        int b = l[j];

        // Use the Arrays.binarySearch method to find the index 'right' where an element greater than 'a+b' is present
        int right = Arrays.binarySearch(l, a+b);
        if (right < 0) {
            right = -right - 1;
        }

        // Use the Arrays.binarySearch method to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
        int left = Arrays.binarySearch(l, Math.max(a-b, b-a));
        if (left < 0) {
            left = -left - 1;
        }

        // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
        int tmp = Math.max(0, right-left);

        // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
        if (left <= i && i < right) {
            tmp -= 1;
        }
        if (left <= j && j < right) {
            tmp -= 1;
        }

        // Add the temporary answer 'tmp' to the final answer 'ans'
        ans += tmp;
    }
}

// Print the final answer 'ans' divided by three
System.out.println(ans / 3);

