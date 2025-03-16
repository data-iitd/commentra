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
    int[] p = new int[sc.nextInt()];
    for (int i = 0; i < p.length; i++) {
        p[i] = sc.nextInt();
    }

    // Create a set of all elements in the lists
    Set<Integer> q = new HashSet<>();
    for (int[] l : li) {
        for (int e : l) {
            q.add(e);
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    Set<Integer> r = new HashSet<>();
    for (int i = 1; i <= n; i++) {
        r.add(i);
    }

    // Find the set of numbers in r that are not in q
    Set<Integer> v = new HashSet<>(r);
    v.removeAll(q);

    // Initialize answer to 0
    int ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i <= q.size(); i++) {
        // Iterate through all combinations of i elements from q
        for (Set<Integer> s : Sets.combinations(q, i)) {
            // Iterate through each list and pattern
            for (int[] u : li) {
                for (int w : p) {
                    // Convert s to a set
                    Set<Integer> s2 = new HashSet<>(s);
                    // Check if the current combination of lists and pattern match the current subset of q
                    if (s2.size()!= 0 && (s2.size() & 1)!= w) {
                        // If not, break out of the inner loop and move on to the next combination
                        break;
                    }
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            else {
                ans += Math.pow(2, v.size());
            }
        }
    }

    // Print the answer
    System.out.println(ans);
}

// Run the main function if the script is executed directly
public static void main(String[] args) {
    main(args);
}

