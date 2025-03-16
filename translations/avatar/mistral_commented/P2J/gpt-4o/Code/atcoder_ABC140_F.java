import java.util.*;

public class Main {
    // Function to read an integer from standard input
    public static int I() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a list of integers from standard input
    public static List<Integer> LI() {
        Scanner scanner = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    // Main function to solve the problem
    public static String mainLogic() {
        // Read the number of test cases
        int N = I();

        // Read the list of integers and sort it in descending order
        List<Integer> S = LI();
        Collections.sort(S, Collections.reverseOrder());

        // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
        boolean[] flag = new boolean[S.size()];
        Arrays.fill(flag, true);

        // Initialize an empty list to store the current subsequence
        List<Integer> cur = new ArrayList<>();

        // Start from the first integer and include it in the subsequence
        cur.add(S.get(0));
        flag[0] = false;

        // For each integer in the sorted list
        for (int i = 0; i < N; i++) {
            // Initialize variables
            int j = 0;
            int jM = cur.size();

            // Try to include the current integer in the subsequence
            for (int k = 0; k < S.size(); k++) {
                // If the flag of the current integer is true and it is smaller than the last integer in the subsequence
                if (flag[k] && S.get(k) < cur.get(j)) {
                    // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                    cur.add(S.get(k));
                    j++;
                    flag[k] = false;
                    // If the length of the subsequence hasn't changed, break the loop
                    if (j == jM) {
                        break;
                    }
                }
            }

            // If we couldn't include any integer in the subsequence after the current one, return "No"
            if (j == jM) {
                return "No";
            }

            // Sort the subsequence in descending order
            Collections.sort(cur, Collections.reverseOrder());
        }

        // If we could include all the integers in the subsequence, return "Yes"
        return "Yes";
    }

    // Run the main function if the script is executed directly
    public static void main(String[] args) {
        System.out.println(mainLogic());
    }
}

// <END-OF-CODE>
