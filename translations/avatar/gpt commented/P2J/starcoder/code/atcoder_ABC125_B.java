// Read the number of elements
int N = Integer.parseInt(input());

// Read the values into a list and convert them to integers
String[] V = input().split(" ");
int[] V = new int[N];
for (int i = 0; i < N; i++) {
    V[i] = Integer.parseInt(V[i]);
}

// Read the costs into a list and convert them to integers
String[] C = input().split(" ");
int[] C = new int[N];
for (int i = 0; i < N; i++) {
    C[i] = Integer.parseInt(C[i]);
}

// Initialize a list to store the profit differences, starting with 0
List<Integer> profit_differences = new ArrayList<Integer>();
profit_differences.add(0);

// Initialize a variable to hold the total profit
int ans = 0;

// Initialize variables to hold current value and cost
int X = 0;
int Y = 0;

// Iterate through each item
for (int i = 0; i < N; i++) {
    // Check if the value is greater than the cost
    if (V[i] - C[i] > 0) {
        // Assign the current value and cost to X and Y
        X = V[i];
        Y = C[i];
        // Calculate the profit and append it to the profit differences list
        profit_differences.add(X - Y);
    }
}

// Calculate and print the total profit by summing the profit differences
for (int i = 0; i < profit_differences.size(); i++) {
    ans += profit_differences.get(i);
}

System.out.println(ans);

