// Initialize an empty list to store the sequence
List<Integer> L = new ArrayList<Integer>();

// Read input (not used, but could be for prompting the user)
//input();

// Initialize a variable 'r' to keep track of the current number to be added to the list
int r = 1;

// Read a line of input, split it into parts, and iterate over each part
for (String k : input().split()) {
    // Extend the list 'L' by adding 'r' for 'int(k)' times
    for (int i = 0; i < Integer.parseInt(k); i++) {
        L.add(r);
    }
    // Increment 'r' for the next number
    r += 1;
}

// Read another line of input (not used, but could be for prompting the user)
//input();

// Read a line of input, split it into parts, and iterate over each part
for (String j : input().split()) {
    // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
    System.out.println(L.get(Integer.parseInt(j) - 1));
}

