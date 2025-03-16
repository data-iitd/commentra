// User inputs the maximum level of the set
int maxLevel = scanner.nextInt();

// User inputs two lists, x and y, separated by a newline
List<Integer> x = new ArrayList<>();
List<Integer> y = new ArrayList<>();

// Remove the first element from both lists, as they are not part of the sets
x.remove(0);
y.remove(0);

// Convert both lists to sets for faster set operations
Set<Integer> xSet = new HashSet<>(x);
Set<Integer> ySet = new HashSet<>(y);

// Check if zero is present in the first set
if (xSet.contains(0)) {
    // If it is, remove it
    xSet.remove(0);
} else {
    // Else, check if zero is present in the second set
    if (ySet.contains(0)) {
        // If it is, remove it
        ySet.remove(0);
    }
}

// Combine both sets into a new set z
Set<Integer> z = new HashSet<>(xSet);
z.addAll(ySet);

// Check if the size of the combined set is equal to the maximum level
if (z.size() != maxLevel) {
    // If not, print an error message
    System.out.println("Oh, my keyboard!");
} else {
    // Else, print a success message
    System.out.println("I become the guy.");
}

