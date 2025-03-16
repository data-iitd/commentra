// Take the number of rows as input
int n = sc.nextInt();

// Initialize an empty list 's' to store the rows
ArrayList<ArrayList<Integer>> s = new ArrayList<>();

// Read each row and append it to the list 's'
for (int i = 0; i < n; i++) {
    // Read a row as a string and convert it to a list
    String[] k = sc.nextLine().split(" ");
    // Append the list to the list 's'
    s.add(new ArrayList<Integer>());
    for (int j = 0; j < n; j++) {
        s.get(i).add(Integer.parseInt(k[j]));
    }
}

// Initialize flags and empty lists 'd1' and 'd2'
boolean flag = false;
ArrayList<Integer> d1 = new ArrayList<>();
ArrayList<Integer> d2 = new ArrayList<>();

// Iterate through each element in the list 's'
for (int i = 0; i < n; i++) {
    // Iterate through each element in the same row and in the reverse order
    for (int j = 0; j < n; j++) {
        // If the current indices are same, append the element to 'd1'
        if (i == j) {
            d1.add(s.get(i).get(j));
        }
        // If the current indices are reverse of each other, append the element to 'd2'
        if (i == n - j) {
            d2.add(s.get(i).get(j));
        }
        // If the current indices are not same and not reverse, add the element to 'rem' set
        if (i != j && i != n - j) {
            rem.add(s.get(i).get(j));
        }
    }
}

// Check if the size of 'rem' set is not equal to 1
if (rem.size() != 1) {
    // If the condition is true, print 'NO' and exit
    System.out.println("NO");
    return;
}

// Check if 'd1' and 'd2' lists are equal
if (!d1.equals(d2)) {
    // If the condition is true, print 'NO' and exit
    System.out.println("NO");
    return;
}

// Check if all elements in 'd1' are same
if (d1.size() != 1) {
    // If the condition is true, print 'NO' and exit
    System.out.println("NO");
    return;
}

// Check if all elements in 'd1' are present in 'rem' set
if (!rem.containsAll(d1)) {
    // If the condition is true, print 'NO' and exit
    System.out.println("NO");
    return;
}

// If all the above conditions are false, print 'YES'
System.out.println("YES");


Translate the above Java code to C++ and end with comment "