
// Function to perform binary search on a sorted list
public static int binary_search(int key) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = ans.size();

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (ans.get(mid)[-1] < key) {
            // If yes, update 'good' to be the new left index
            good = mid;
        } else {
            // If no, update 'bad' to be the new right index
            bad = mid;
        }
    }

    // Return the index where the key is located
    return good;
}

// Read the number of elements in the list
int N = Integer.parseInt(input());

// Initialize an empty list to store the elements
List<List<Integer>> ans = new ArrayList<>();

// Read each element and perform binary search to find its position in the list
for (int i = 0; i < N; i++) {
    // Read an element
    int A = Integer.parseInt(input());

    // Perform binary search to find the index of the element
    int idx = binary_search(A);

    // If the element is not already in the list, append it to the list
    if (idx == ans.size()) {
        ans.add(new ArrayList<>(Arrays.asList(A)));
    } else {
        // If the element is already in the list, append it to the existing list
        ans.get(idx).add(A);
    }
}

// Print the number of unique elements in the list
System.out.println(ans.size());

