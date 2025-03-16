// Read the first line of input which indicates the number of iterations
int firstline = Integer.parseInt(scanner.nextLine());

// Initialize total to keep track of the accumulated value
int total = 0;

// Create an empty list to store the memory of actions taken
ArrayList<String> memory = new ArrayList<String>();

// Loop through the range defined by firstline
for (int x = 0; x < firstline; x++) {
    // Read two integers A and G from input, separated by space
    int A = Integer.parseInt(scanner.next());
    int G = Integer.parseInt(scanner.next());

    // Check if adding A to total does not exceed the limit of 500
    if (total + A <= 500) {
        // If within limit, add A to total
        total += A;
        // Record the action "A" in memory
        memory.add("A");
    } else {
        // If limit exceeded, subtract G from total
        total -= G;
        // Record the action "G" in memory
        memory.add("G");
    }
}

// Print the sequence of actions taken as a single string
for (String action : memory) {
    System.out.print(action);
}

// End of code
