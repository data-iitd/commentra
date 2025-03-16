// Main function
public static void main(String[] args) {
    // Read input
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int Q = sc.nextInt();
    int[] a = new int[Q + 1];
    for (int i = 1; i <= Q; ++i)
        a[i] = sc.nextInt();

    // Initialize variables
    int[] b = new int[m + 1];
    boolean[] vis = new boolean[m + 1];
    int[] cnt = new int[m + 1];
    for (int k = 0, j = Q; j > 0; --j) {
        // Find unvisited elements and add them to the output array
        if (!vis[a[j]]) {
            b[++k] = a[j]; // Add the element to the output array
            vis[a[j]] = true; // Mark it as visited
        }
    }

    // Fill the output array with the remaining unvisited elements
    for (int j = m, i = m; i > 0; --i) {
        if (!vis[i]) {
            b[j--] = i; // Add the element to the output array
        }
    }

    // Assign indices to the output array elements
    int[] id = new int[m + 1];
    for (int i = 1; i <= m; ++i)
        id[b[i]] = i; // Assign index i to the element b[i]

    // Process queries
    boolean flag = true;
    cnt[0] = n; // Initialize counter array with the number of elements in the input array
    for (int i = Q; i > 0; --i) {
        int t = id[a[i]]; // Get the index of the element a[i] in the output array
        if (cnt[t - 1] > 0) { // If the previous element is still present in the input array
            --cnt[t - 1]; // Decrease its counter
            ++cnt[t]; // Increase the counter of the current element
            vis[t] = true; // Mark it as visited
        }
        else if (!vis[t]) { // If the current element is not present in the input array
            flag = false; // Set the flag to false and break the loop
            break;
        }
    }

    // Check the result
    int l;
    for (l = 0; cnt[l] == 0; ++l); // Find the last element that was present in the input array
    for (int i = l + 1; i < m; ++i)
        flag &= b[i] < b[i + 1]; // Check if the output array is sorted in ascending order after the last present element

    // Print the result
    System.out.println(flag ? "Yes" : "No");
}

