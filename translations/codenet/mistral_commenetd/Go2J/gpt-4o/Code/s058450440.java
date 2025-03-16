import java.util.*;

public class Main {
    static List<Integer> a = new ArrayList<>();
    static int ans = 0;

    public static void dfs(int left, int i, int res) {
        // Function to perform Depth First Search (DFS) algorithm
        if (left == 0) {
            ans += res;
            return;
        }

        for (int j = i; j < a.size(); j++) {
            dfs(left - 1, j + 1, res * a.get(j));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the number of test cases
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Initializing an empty map to store the frequency of each character
        Map<Character, Integer> dic = new HashMap<>();

        // Reading strings and updating the map
        for (int k = 0; k < n; k++) {
            char c = scanner.nextLine().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        // Converting map values to integers and appending them to the 'a' list
        for (int v : dic.values()) {
            a.add(v);
        }

        // Calling the 'dfs' function with initial arguments
        dfs(3, 0, 1);

        // Printing the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
