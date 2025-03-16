// Read input values for x, y, a, and b and convert them to integers
Scanner scanner = new Scanner(System.in);
int x = scanner.nextInt();
int y = scanner.nextInt();
int a = scanner.nextInt();
int b = scanner.nextInt();

// Initialize an empty list to store valid game pairs
List<Integer[]> games = new ArrayList<>();

// Iterate over the range from a to x (inclusive)
for (int i = a; i <= x; i++) {
    // Skip the iteration if i is less than or equal to b
    if (i <= b) {
        continue;
    }
    // Iterate over the range from b to y (inclusive)
    for (int j = b; j <= y; j++) {
        // Check if the current i is greater than j
        if (i > j) {
            // If the condition is met, append the pair (i, j) to the games list
            games.add(new Integer[] {i, j});
        }
    }
}

// Print the total number of valid game pairs found
System.out.println(games.size());

// Print each valid game pair
for (Integer[] game : games) {
    System.out.println(game[0] + " " + game[1]);
}

