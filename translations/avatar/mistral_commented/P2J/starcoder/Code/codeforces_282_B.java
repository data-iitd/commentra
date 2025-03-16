// Take the first line as an input
Scanner sc = new Scanner(System.in);
int firstline = sc.nextInt();

// Initialize total and memory lists
int total = 0;
List<String> memory = new ArrayList<>();

// Loop through the given number of lines
for (int x = 0; x < firstline; x++) {
    // Take two integers as input, A and G
    int A = sc.nextInt();
    int G = sc.nextInt();
    
    // Check if adding A to the total memory usage is within the limit
    if (total + A <= 500) {
        // If yes, add A to the total and append 'A' to the memory list
        total += A;
        memory.add("A");
    } else {
        // If no, subtract G from the total and append 'G' to the memory list
        total -= G;
        memory.add("G");
    }
}

// Print the final memory state
for (String s : memory) {
    System.out.print(s);
}

