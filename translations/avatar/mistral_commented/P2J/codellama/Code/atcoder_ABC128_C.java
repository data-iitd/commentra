// Define the main function
public static void main(String[] args) {
    // Read input: number of test cases, number of lists, and the lists themselves
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[][] li = new int[m][];
    for (int i = 0; i < m; i++) {
        li[i] = new int[sc.nextInt()];
        for (int j = 0; j < li[i].length; j++) {
            li[i][j] = sc.nextInt();
        }
    }

    // Read input: pattern
    int[] p = new int[m];
    for (int i = 0; i < m; i++) {
        p[i] = sc.nextInt();
    }

    // Create a set of all elements in the lists
    Set<Integer> q = new HashSet<>();
    for (int[] u : li) {
        for (int v : u) {
            q.add(v);
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    Set<Integer> r = new HashSet<>();
    for (int i = 1; i < n+1; i++) {
        r.add(i);
    }

    // Find the set of numbers in r that are not in q
    Set<Integer> v = new HashSet<>(r);
    v.removeAll(q);

    // Initialize answer to 0
    long ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i <= q.size(); i++) {
        // Iterate through all combinations of i elements from q
        for (int[] s : combinations(q, i)) {
            // Iterate through each list and pattern
            for (int[] u : li) {
                // Convert s to a set
                Set<Integer> s_set = new HashSet<>(Arrays.asList(s));
                // Check if the current combination of lists and pattern match the current subset of q
                if (s_set.size() % 2 != p[s_set.size()]) {
                    // If not, break out of the inner loop and move on to the next combination
                    break;
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            ans += (long) Math.pow(2, v.size());
        }
    }

    // Print the answer
    System.out.println(ans);
}

// Define a function to generate all combinations of i elements from a set
public static int[][] combinations(Set<Integer> q, int i) {
    // Initialize the answer to an empty array
    int[][] ans = new int[0][];

    // If i is 0, return the empty array
    if (i == 0) {
        return ans;
    }

    // If i is 1, return all elements of q
    if (i == 1) {
        ans = new int[q.size()][];
        int j = 0;
        for (int v : q) {
            ans[j] = new int[]{v};
            j++;
        }
        return ans;
    }

    // If i is greater than 1, iterate through all combinations of i-1 elements from q
    for (int[] s : combinations(q, i-1)) {
        // Iterate through all elements of q
        for (int v : q) {
            // If v is not in s, add v to s and add s to the answer
            if (!Arrays.asList(s).contains(v)) {
                int[] s_new = Arrays.copyOf(s, s.length+1);
                s_new[s.length] = v;
                ans = Arrays.copyOf(ans, ans.length+1);
                ans[ans.length-1] = s_new;
            }
        }
    }

    // Return the answer
    return ans;
}

// End of code
