// Read an integer input which represents the number of lists to be processed
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize an empty list to store the input lists
List<List<String>> q = new ArrayList<>();

// Initialize a counter to keep track of the matching conditions
int count = 0;

// Loop to read 'n' lines of input and store them in the list 'q'
for (int i = 0; i < n; i++) {
    // Read a line of input, split it into a list of strings, and append it to 'q'
    String[] a = sc.nextLine().split(" ");
    q.add(Arrays.asList(a));
}

// Nested loop to compare each list in 'q' with every other list
for (List<String> j : q) {
    for (List<String> k : q) {
        // Skip comparison if both lists are the same
        if (k == j) {
            continue;
        }
        // Check if the first element of list 'j' matches the last element of list 'k'
        if (j.get(0).equals(k.get(k.size() - 1))) {
            // Increment the count if the condition is met
            count++;
        } else {
            // Continue to the next iteration if the condition is not met
            continue;
        }
    }
}

// Print the final count of matching conditions
System.out.println(count);

