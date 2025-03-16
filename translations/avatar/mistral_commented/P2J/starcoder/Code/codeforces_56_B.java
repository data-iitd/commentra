#######
# Code
#######

// Read the number of elements in the list 'A'
int N = Integer.parseInt(input());

// Initialize an empty list 'A' with the given size 'N'
// and read the elements from the standard input
List<Integer> A = new ArrayList<Integer>();
for (int i = 0; i < N; i++) {
    A.add(Integer.parseInt(input()));
}

// Initialize minimum and maximum indices'mn' and'mx'
int mn = N + 1, mx = -1;

// Iterate through the list 'A' from index 0 to 'N-1'
for (int i = 0; i < N; i++) {
    // Check if the current index 'i' is not equal to the next element
    if (i + 1!= A.get(i)) {
        // Update the minimum and maximum indices'mn' and'mx'
        mn = Math.min(mn, i);
        mx = Math.max(mx, i);
    }
}

// Check if the maximum index'mx' is still equal to -1
if (mx == -1) {
    // If yes, print '0 0' as the output
    System.out.println("0 0");
} else {
    // Slice the list 'A' based on the indices'mn' and'mx+1'
    List<Integer> B = A.subList(0, mn);
    B.addAll(A.subList(mn, mx + 1).descendingIterator());
    B.addAll(A.subList(mx + 1, A.size()));
    
    // Check if the sliced list 'B' is sorted in ascending order
    if (B.stream().sorted().collect(Collectors.toList()).equals(B)) {
        // If yes, print the minimum and maximum indices'mn+1' and'mx+1' as the output
        System.out.println(mn + 1 + " " + mx + 1);
    } else {
        // If no, print '0 0' as the output
        System.out.println("0 0");
    }
}

