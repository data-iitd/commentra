// Define the number of items in the input array
int n = Integer.parseInt(sc.nextLine());

// Initialize an empty list to store the input data
ArrayList<Integer> input_array = new ArrayList<Integer>();

// Read n items from the standard input and append them to the input_array
for (int i = 0; i < n; i++) {
    String[] input = sc.nextLine().split(" ");
    int S = Integer.parseInt(input[0]);
    int R = Integer.parseInt(input[1]);
    int H = Integer.parseInt(input[2]);
    int C = Integer.parseInt(input[3]);
    input_array.add(S);
    input_array.add(R);
    input_array.add(H);
    input_array.add(C);
}

// Initialize an empty list to store the outdated items
ArrayList<Integer> outdated = new ArrayList<Integer>();

// Check for outdated items in the input array
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Check if the current item is older and smaller than the next one
        if (input_array.get(i * 4) < input_array.get(j * 4) &&
            input_array.get(i * 4 + 1) < input_array.get(j * 4 + 1) &&
            input_array.get(i * 4 + 2) < input_array.get(j * 4 + 2)) {
            // Append the current item to the outdated list
            outdated.add(i);
        }
    }
}

// Convert the outdated list to a set to remove duplicates
Set<Integer> outdated_set = new HashSet<Integer>(outdated);

// Initialize minimum_cost and input_number to large initial values
int minimum_cost = 100000;
int input_number = 0;

// Find the item with the minimum cost that is not outdated
for (int i = 0; i < n; i++) {
    int current_item = i;
    int cost = input_array.get(i * 4 + 3);
    // Check if the current item is not outdated and has a smaller cost than minimum_cost
    if (!outdated_set.contains(current_item) && cost < minimum_cost) {
        // Update minimum_cost and input_number
        minimum_cost = cost;
        input_number = i + 1;
    }
}

// Print the index of the item with the minimum cost that is not outdated
System.out.println(input_number);

