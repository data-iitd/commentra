// Read the maximum level from user input
int max_level = Integer.parseInt(System.console().readLine());

// Read the levels completed by player X and convert them to a list of integers
List<Integer> x = Arrays.stream(System.console().readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Read the levels completed by player Y and convert them to a list of integers
List<Integer> y = Arrays.stream(System.console().readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Remove the first element from both lists, which represents the count of levels
x.remove(0);
y.remove(0);

// Convert the lists of levels into sets to eliminate duplicates
Set<Integer> xSet = new HashSet<>(x);
Set<Integer> ySet = new HashSet<>(y);

// Check if player X has completed level 0, if so, remove it from the set
if (xSet.contains(0)) {
    xSet.remove(0);
}
// If player X has not completed level 0, check if player Y has, and remove it if present
else if (ySet.contains(0)) {
    ySet.remove(0);
}

// Create a union of both sets to combine all unique levels completed by both players
Set<Integer> zSet = new HashSet<>(xSet);
zSet.addAll(ySet);

// Check if the number of unique levels completed matches the maximum level
if (zSet.size()!= max_level) {
    // If not, print a message indicating that not all levels were completed
    System.out.println("Oh, my keyboard!");
} else {
    // If all levels were completed, print a success message
    System.out.println("I become the guy.");
}

