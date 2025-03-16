
// Read the number of elements
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();

// Read the values into a list and convert them to integers
List<Integer> V = new ArrayList<>();
for (int i = 0; i < N; i++) {
    V.add(scanner.nextInt());
}

// Read the costs into a list and convert them to integers
List<Integer> C = new ArrayList<>();
for (int i = 0; i < N; i++) {
    C.add(scanner.nextInt());
}

// Initialize a list to store the profit differences, starting with 0
List<Integer> profitDifferences = new ArrayList<>();
profitDifferences.add(0);

// Initialize a variable to hold the total profit
int ans = 0;

// Initialize variables to hold current value and cost
int X = 0;
int Y = 0;

// Iterate through each item
for (int i = 0; i < N; i++) {
    // Check if the value is greater than the cost
    if (V.get(i) - C.get(i) > 0) {
        // Assign the current value and cost to X and Y
        X = V.get(i);
        Y = C.get(i);
        // Calculate the profit and append it to the profit differences list
        profitDifferences.add(X - Y);
    }
}

// Calculate and print the total profit by summing the profit differences
for (int i = 1; i < profitDifferences.size(); i++) {
    ans += profitDifferences.get(i);
}
System.out.println(ans);

