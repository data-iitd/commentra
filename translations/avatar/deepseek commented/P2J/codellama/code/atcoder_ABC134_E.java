public static int binarySearch(int key) {
    // Initialize bad and good indices for binary search
    int bad = -1, good = ans.size();
    
    // Perform binary search to find the correct position
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans.get(mid).get(ans.get(mid).size() - 1) < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    
    // Return the index where the key should be inserted
    return good;
}

// Read the number of elements
int N = Integer.parseInt(scanner.nextLine());

// Initialize the list of lists
ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

// Read each element and insert it into the appropriate position
for (int i = 0; i < N; i++) {
    int A = Integer.parseInt(scanner.nextLine());
    int idx = binarySearch(A);
    if (idx == ans.size()) {
        // If the key should be inserted at the end, append a new sublist
        ans.add(new ArrayList<Integer>(Arrays.asList(A)));
    } else {
        // Otherwise, insert the key into the appropriate sublist
        ans.get(idx).add(A);
    }
}

// Print the number of unique elements
System.out.println(ans.size());

