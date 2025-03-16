// Read two integers n and m from input, where n is the number of elements and m is the divisor
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Read a list of n integers from input
int[] l = new int[n];
for (int i = 0; i < n; i++) {
    l[i] = sc.nextInt();
}

// Initialize an empty list to store the results after processing the input list
List<Integer> l2 = new ArrayList<>();

// Iterate through each element in the input list
for (int i = 0; i < n; i++) {
    // If the current element is divisible by m, append the quotient to l2
    if (l[i] % m == 0) {
        l2.add(l[i] / m);
    }
    // If the current element is not divisible by m, append the quotient plus one to l2
    else {
        l2.add(l[i] / m + 1);
    }
}

// Find the maximum value in the processed list l2
int mx = Collections.max(l2);

// Iterate through the range of n to find the index of the maximum value in l2
for (int i = 0; i < n; i++) {
    if (l2.get(i) == mx) {
        int ind = i; // Store the index of the maximum value
    }
}

// Print the index of the maximum value (1-based index)
System.out.println(ind + 1);

