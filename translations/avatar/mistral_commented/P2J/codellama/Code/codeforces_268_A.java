// Ask user for the number of arrays (n) they want to input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Create an empty list called 'q' to store these arrays
ArrayList<String[]> q = new ArrayList<String[]>();

// Use a for loop to iterate through the range of 'n' and for each iteration,
// ask the user for an array (a) and append it to our list 'q'
for (int i = 0; i < n; i++) {
    // Ask user for an array (a)
    String[] a = sc.nextLine().split(" ");
    // Append array 'a' to our list 'q'
    q.add(a);
}

// Use another for loop to iterate through each array in our list 'q'
for (String[] j : q) {
    // For each array 'j', use another for loop to iterate through every other array in our list 'q'
    for (String[] k : q) {
        // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
        if (k == j) {
            continue;
        }
        // Check if the last element of the second array 'k' matches the first element of the first array 'j'
        else if (j[0].equals(k[k.length - 1])) {
            // If it does, increment our 'count' variable
            count++;
        }
    }
}

// Finally, print out the value of our 'count' variable
System.out.println(count);

