
// Read the number of items from user input
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();

// Initialize an empty list to store the input items
List<Integer> inputArray = new ArrayList<>();

// Loop to read each item's attributes (S, R, H, C)
for (int i = 0; i < n; i++) {
    // Read the attributes S, R, H, C and convert them to integers
    int S = scanner.nextInt();
    int R = scanner.nextInt();
    int H = scanner.nextInt();
    int C = scanner.nextInt();
    // Append the attributes as a tuple to the input_array
    inputArray.add(S);
    inputArray.add(R);
    inputArray.add(H);
    inputArray.add(C);
}

// Initialize a list to keep track of outdated items
List<Integer> outdated = new ArrayList<>();

// Compare each item with every other item to find outdated ones
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Check if item i is outdated compared to item j
        if (inputArray.get(4 * i) < inputArray.get(4 * j) &&
                inputArray.get(4 * i + 1) < inputArray.get(4 * j + 1) &&
                inputArray.get(4 * i + 2) < inputArray.get(4 * j + 2)) {
            // If outdated, add item i to the outdated list
            outdated.add(inputArray.get(4 * i));
            outdated.add(inputArray.get(4 * i + 1));
            outdated.add(inputArray.get(4 * i + 2));
            outdated.add(inputArray.get(4 * i + 3));
        }
    }
}

// Initialize variables to track the minimum cost and corresponding item index
int minimumCost = 100000;
int inputNumber = 0;

// Loop through the input items to find the one with the minimum cost that is not outdated
for (int i = 0; i < n; i++) {
    int currentItem = inputArray.get(4 * i + 3);  // Get the cost of the current item
    // Check if the current item is not outdated and has a lower cost than the current minimum
    if (!outdated.contains(inputArray.get(4 * i)) && currentItem < minimumCost) {
        minimumCost = currentItem;  // Update the minimum cost
        inputNumber = i + 1;  // Store the index of the current item (1-based index)
    }
}

// Print the index of the item with the minimum cost that is not outdated
System.out.println(inputNumber);

