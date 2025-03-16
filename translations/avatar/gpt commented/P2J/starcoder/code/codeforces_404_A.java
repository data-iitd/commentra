// Read the number of rows/columns for the square matrix
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize an empty list to store the input strings
List<String> s = new ArrayList<>();

// Read n strings from input and append them to the list s
for (int i = 0; i < n; i++) {
    String k = sc.next();
    s.add(k);
}

// Initialize a flag variable (not used in this code)
int flag = 0;

// Initialize lists to store diagonal elements
List<String> d1 = new ArrayList<>();  // Primary diagonal
List<String> d2 = new ArrayList<>();  // Secondary diagonal

// Initialize a set to store non-diagonal elements
Set<String> rem = new HashSet<>();

// Iterate through the matrix to populate the diagonals and non-diagonal elements
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // If it's a primary diagonal element
        if (i == j) {
            d1.add(s.get(i).charAt(j));
        }
        // If it's a secondary diagonal element
        if (i == n - j - 1) {
            d2.add(s.get(i).charAt(j));
        }
        // If it's a non-diagonal element
        if (i!= j && i!= n - j - 1) {
            rem.add(s.get(i).charAt(j));
        }
    }
}

// Check conditions to determine the output
// If the number of unique non-diagonal elements is not 1
if (rem.size()!= 1) {
    System.out.println("NO");
}
// If the primary and secondary diagonals are not equal
else if (!d1.equals(d2)) {
    System.out.println("NO");
}
// If the primary diagonal does not consist of the same element
else if (d1.size()!= 1) {
    System.out.println("NO");
}
// If the unique element in the primary diagonal is also in the non-diagonal set
else if (d1.get(0) == rem.iterator().next()) {
    System.out.println("NO");
}
// If all conditions are satisfied, print 'YES'
else {
    System.out.println("YES");
}

