// Read an integer input which represents the number of lists to process
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize a counter to keep track of lists with a sum greater than 1
int c = 0;

// Loop through the range of n to process each list
for (int i = 0; i < n; i++) {
    // Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
    String[] l1 = sc.nextLine().split(" ");
    int[] l2 = new int[l1.length];
    for (int j = 0; j < l1.length; j++) {
        l2[j] = Integer.parseInt(l1[j]);
    }
    
    // Check if the sum of the current list is greater than 1
    if (sum(l2) > 1) {
        // Increment the counter if the condition is met
        c = c + 1;
    }
}

// Print the final count of lists that had a sum greater than 1
System.out.println(c);

