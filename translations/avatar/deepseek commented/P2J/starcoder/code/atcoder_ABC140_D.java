import java.util.*;  // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object for reading input
        int N = sc.nextInt();  // Read the number of elements N from the input
        int K = sc.nextInt();  # Read the parameter K from the input
        String S = sc.next();  # Read the string S from the input

        int seg_cnt = 0;  // Initialize a counter for the number of segments
        for (int i = 0; i < N - 1; i++) {  // Loop through the string to count segments
            if (S.charAt(i)!= S.charAt(i + 1)) {  // Check if the current character is different from the next
                seg_cnt++;  // Increment the segment counter if a change is found
            }
        }

        int cur_happy = N - 1 - seg_cnt;  // Calculate the initial happiness based on the number of segments

        if (2 * K >= seg_cnt) {  // Check if the number of operations allows for maximum happiness
            int ans = N - 1;  // If yes, set the answer to the maximum possible happiness
        } else {
            int ans = cur_happy + 2 * K;  // Otherwise, adjust the happiness based on the number of operations
        }

        System.out.println(ans);  // Print the final happiness value
    }
}

