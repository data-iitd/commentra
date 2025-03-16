// Read the number of elements
int n = Integer.parseInt(input());

// Read the elements into a list and convert them to integers
List<Integer> a = Arrays.stream(input().split()).map(Integer::parseInt).collect(Collectors.toList());

// Initialize a list 'b' with zeros to store the positions of elements
List<Integer> b = new ArrayList<>(Collections.nCopies(n, 0));

// Populate the list 'b' with the indices of elements from list 'a'
for (int i = 0; i < n; i++) {
    b.set(a.get(i) - 1, i); // Store the index of each element in 'b' based on its value in 'a'
}

// Initialize the result variable to accumulate the total distance
int res = 0;

// Calculate the total distance between consecutive elements in 'b'
for (int i = 1; i < n; i++) {
    res += Math.abs(b.get(i) - b.get(i - 1)); // Add the absolute difference of indices to the result
}

// Print the final result
System.out.println(res);

