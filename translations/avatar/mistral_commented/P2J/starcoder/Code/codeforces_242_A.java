// Get user input as a string and convert it to a list of integers
Scanner sc = new Scanner(System.in);
String[] input = sc.nextLine().split(" ");
int x = Integer.parseInt(input[0]);
int y = Integer.parseInt(input[1]);
int a = Integer.parseInt(input[2]);
int b = Integer.parseInt(input[3]);
// Initialize an empty list to store the games
List<Tuple<Integer, Integer>> games = new ArrayList<>();

// Iterate through a range of numbers from a to x+1
for (int i = a; i <= x + 1; i++) {
    // If i is less than or equal to b, skip to the next iteration
    if (i <= b) {
        continue;
    }
    // Iterate through a range of numbers from b to y+1
    for (int j = b; j <= y + 1; j++) {
        // If i is greater than j, append the tuple (i, j) to the games list
        if (i > j) {
            games.add(new Tuple(i, j));
        }
    }
}

// Print the length of the games list
System.out.println(games.size());
// Iterate through the games list and print each tuple
for (Tuple<Integer, Integer> i : games) {
    // Print the tuple as a string in the format "i j"
    System.out.println(i.getKey() + " " + i.getValue());
}

