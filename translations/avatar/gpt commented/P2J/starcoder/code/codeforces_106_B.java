// Read the number of items from user input
int n = Integer.parseInt(sc.next());

// Initialize an empty list to store the input items
ArrayList<Integer> input_array = new ArrayList<Integer>();

// Loop to read each item's attributes (S, R, H, C)
for (int i = 0; i < n; i++) {
    // Read the attributes S, R, H, C and convert them to integers
    int S = Integer.parseInt(sc.next());
    int R = Integer.parseInt(sc.next());
    int H = Integer.parseInt(sc.next());
    int C = Integer.parseInt(sc.next());
    // Append the attributes as a tuple to the input_array
    input_array.add(S);
    input_array.add(R);
    input_array.add(H);
    input_array.add(C);
}

// Initialize a list to keep track of outdated items
ArrayList<Integer> outdated = new ArrayList<Integer>();

// Compare each item with every other item to find outdated ones
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Check if item i is outdated compared to item j
        if (input_array.get(i*4) < input_array.get(j*4) && 
            input_array.get(i*4+1) < input_array.get(j*4+1) && 
            input_array.get(i*4+2) < input_array.get(j*4+2)) {
            // If outdated, add item i to the outdated list
            outdated.add(i);
        }
    }
}

// Convert the outdated list to a set to remove duplicates
Set<Integer> outdated = new HashSet<Integer>(outdated);

// Initialize variables to track the minimum cost and corresponding item index
int minimum_cost = 100000;
int input_number = 0;

// Loop through the input items to find the one with the minimum cost that is not outdated
for (int i = 0; i < n; i++) {
    int current_item = i;
    int cost = input_array.get(i*4+3);  // Get the cost of the current item
    // Check if the current item is not outdated and has a lower cost than the current minimum
    if (current_item not in outdated && cost < minimum_cost) {
        minimum_cost = cost;  // Update the minimum cost
        input_number = i + 1;  // Store the index of the current item (1-based index)
}

// Print the index of the item with the minimum cost that is not outdated
System.out.println(input_number);

