
import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array from the user input
        int N = sc.nextInt();

        // Allocate memory for the array of size N
        long a[] = new long[N];

        // Initialize variables for temporary storage and answer
        int tmp;
        int ans = 0;

        // Read each element of the array from the user input
        for (int z = 0; N > z; z++) {
            a[z] = sc.nextInt(); // Read the next integer from the user input and store it in the array
        }

        // Sort the array in ascending order
        Arrays.sort(a);

        // Check if the array has only one element
        if (N == 1) {
            // If the array has only one element and its value is greater than 1, then the answer is 1
            if (a[0] > 1) {
                ans = 1;
            }
        } else {
            // Iterate through the array starting from the first element
            for (int j = 0; N > j; j++) {
                // Check if the current element is different from the previous element
                if (j == 0 || a[j] != a[j - 1]) {
                    // Initialize a variable to count the number of consecutive elements equal to the current element
                    tmp = 1;

                    // Count the number of consecutive elements equal to the current element
                    for (int i = j+1; N > i; i++) {
                        // If the current and next elements are equal, increment the counter
                        if (a[j] == a[i]) {
                            tmp++;
                        }
                        // If the current and next elements are not equal, break the loop
                        else{
                            break;
                        }
                    }

                    // Update the answer based on the number of consecutive elements
                    if (tmp > a[j]) {
                        ans += tmp - a[j];
                    } else if (tmp < a[j]) {
                        ans += tmp;
                    }
                }
            }
        }

        // Print the answer to the console
        System.out.println(ans);
    }
}

