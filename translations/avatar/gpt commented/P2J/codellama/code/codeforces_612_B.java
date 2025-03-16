// Read the number of elements
int n = sc.nextInt();

// Read the elements into a list and convert them to integers
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Initialize a list 'b' with zeros to store the positions of elements
int[] b = new int[n];

// Populate the list 'b' with the indices of elements from list 'a'
for (int i = 0; i < n; i++) {
    b[a[i] - 1] = i;  // Store the index of each element in 'b' based on its value in 'a'
}

// Initialize the result variable to accumulate the total distance
int res = 0;

// Calculate the total distance between consecutive elements in 'b'
for (int i = 1; i < n; i++) {
    res += Math.abs(b[i] - b[i - 1]);  // Add the absolute difference of indices to the result
}

// Print the final result
System.out.println(res);

