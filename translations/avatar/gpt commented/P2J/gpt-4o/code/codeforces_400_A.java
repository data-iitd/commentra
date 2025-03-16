import java.util.*;
import java.io.*;

public class Main {
    // Function to read a single line of input and convert it to a list of integers
    public static List<Integer> inList() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        List<Integer> list = new ArrayList<>();
        for (String token : tokens) {
            list.add(Integer.parseInt(token));
        }
        return list;
    }

    // Function to read a single integer from input
    public static int inp() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return Integer.parseInt(br.readLine());
    }

    // Helper function to determine if a specific arrangement is possible
    public static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        // Create sublists of length 'a' from the list 'l'
        for (int i = 0; i < b; i++) {
            List<Integer> sublist = l.subList(i * a, i * a + a);
            tot.add(sublist);
        }

        // Check if any combination of the sublists sums to 'b'
        for (int i = 0; i < a; i++) {
            int sum = 0;
            for (int j = 0; j < tot.size(); j++) {
                sum += tot.get(j).get(i);
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }

    // Main function to solve the problem
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String x = br.readLine();  // Read the input string
        List<Integer> s = new ArrayList<>();

        // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
        for (char i : x.toCharArray()) {
            if (i == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }

        List<int[]> tot = new ArrayList<>();

        // Check for all divisors of 12 to find valid arrangements
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {  // Check if 'i' is a divisor of 12
                if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                    tot.add(new int[]{12 / i, i});  // Store valid arrangements as arrays
                }
            }
        }

        // Print the number of valid arrangements
        System.out.print(tot.size() + " ");

        // Print each valid arrangement in sorted order
        Collections.sort(tot, (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        for (int[] arr : tot) {
            System.out.print(arr[0] + "x" + arr[1] + " ");
        }
        System.out.println();  // Print a newline at the end
    }

    // Entry point of the program
    public static void main(String[] args) throws IOException {
        int testCases = inp();  // Read the number of test cases
        for (int i = 0; i < testCases; i++) {
            solve();  // Solve each case
        }
    }
}

// <END-OF-CODE>
