
// Read an integer input which represents the number of lists to be processed
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize an empty list to store the input lists
ArrayList<String[]> q = new ArrayList<String[]>();

// Initialize a counter to keep track of the matching conditions
int count = 0;

// Loop to read 'n' lines of input and store them in the list 'q'
for (int i = 0; i < n; i++) {
    // Read a line of input, split it into a list of strings, and append it to 'q'
    String[] a = sc.nextLine().split(" ");
    q.add(a);
}

// Nested loop to compare each list in 'q' with every other list
for (int j = 0; j < q.size(); j++) {
    for (int k = 0; k < q.size(); k++) {
        // Skip comparison if both lists are the same
        if (k == j) {
            continue;
        }
        // Check if the first element of list 'j' matches the last element of list 'k'
        else if (q.get(j)[0].equals(q.get(k)[q.get(k).length - 1])) {
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

