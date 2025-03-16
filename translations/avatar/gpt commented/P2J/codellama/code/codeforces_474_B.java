// Initialize an empty list to store the sequence
List<Integer> L = new ArrayList<>();

// Read input (not used, but could be for prompting the user)
Scanner sc = new Scanner(System.in);

// Initialize a variable 'r' to keep track of the current number to be added to the list
int r = 1;

// Read a line of input, split it into parts, and iterate over each part
for (String k : sc.nextLine().split(" ")) {
    // Extend the list 'L' by adding 'r' for 'Integer.parseInt(k)' times
    for (int i = 0; i < Integer.parseInt(k); i++) {
        L.add(r);
    }
    // Increment 'r' for the next number
    r++;
}

// Read another line of input (not used, but could be for prompting the user)
sc.nextLine();

// Read a line of input, split it into parts, and iterate over each part
for (String j : sc.nextLine().split(" ")) {
    // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
    System.out.println(L.get(Integer.parseInt(j) - 1));
}

