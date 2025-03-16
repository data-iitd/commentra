// Function to perform binary search on a sorted list
public static int binarySearch(int key) {
    // Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
    int bad = -1, good = ans.size();

    // Continue searching until the subarray is not divided anymore
    while (good - bad > 1) {
        // Calculate the middle index of the subarray
        int mid = (bad + good) / 2;

        // Check if the middle element is less than the key
        if (ans.get(mid).get(ans.get(mid).size() - 1) < key) {
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
int N = scanner.nextInt();

// Initialize an empty list to store the elements
ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

// Read each element and perform binary search to find its position in the list
for (int i = 0; i < N; i++) {
    // Read an element
    int A = scanner.nextInt();

    // Perform binary search to find the index of the element
    int idx = binarySearch(A);

    // If the element is not already in the list, append it to the list
    if (idx == ans.size()) {
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(A);
        ans.add(temp);
    } else {
        // If the element is already in the list, append it to the existing list
        ans.get(idx).add(A);
    }
}

// Print the number of unique elements in the list
System.out.println(ans.size());

