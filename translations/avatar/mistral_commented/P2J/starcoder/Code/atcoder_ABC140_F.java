
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of test cases
        int N = sc.nextInt();

        // Read the list of integers and sort it in descending order
        int[] S = new int[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
        }
        Arrays.sort(S);
        Arrays.sort(S, Collections.reverseOrder());

        // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
        boolean[] flag = new boolean[N];
        for (int i = 0; i < N; i++) {
            flag[i] = true;
        }

        // Initialize an empty list to store the current subsequence
        List<Integer> cur = new ArrayList<Integer>();

        // Start from the first integer and include it in the subsequence
        cur.add(S[0]);
        flag[0] = false;

        // For each integer in the sorted list
        for (int i = 0; i < N; i++) {
            // Initialize variables
            int j = 0;
            int jM = cur.size();

            // Try to include the current integer in the subsequence
            for (int k = 0; k < N; k++) {
                // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
                if (flag[k] && S[k] < cur.get(j)) {
                    // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                    cur.add(S[k]);
                    j += 1;
                    flag[k] = false;
                    // If the length of the subsequence hasn't changed, break the loop
                    if (j == jM) {
                        break;
                    }
                }
            }

            // If we couldn't include any integer in the subsequence after the current one, return "No"
            else {
                System.out.println("No");
                return;
            }

            // Sort the subsequence in descending order
            Collections.sort(cur, Collections.reverseOrder());
        }

        // If we could include all the integers in the subsequence, return "Yes"
        System.out.println("Yes");
    }
}

