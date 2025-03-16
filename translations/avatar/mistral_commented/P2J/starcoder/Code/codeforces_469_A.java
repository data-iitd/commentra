// User inputs the maximum level of the set
int max_level = Integer.parseInt(input());

// User inputs two lists, x and y, separated by a newline
String[] x = input().split("\\n");
String[] y = input().split("\\n");

// Remove the first element from both lists, as they are not part of the sets
x = Arrays.copyOfRange(x, 1, x.length);
y = Arrays.copyOfRange(y, 1, y.length);

// Convert both lists to sets for faster set operations
Set<Integer> x_set = new HashSet<>();
Set<Integer> y_set = new HashSet<>();

for (String s : x) {
    x_set.add(Integer.parseInt(s));
}

for (String s : y) {
    y_set.add(Integer.parseInt(s));
}

// Check if zero is present in the first set
if (x_set.contains(0)) {
    // If it is, remove it
    x_set.remove(0);
}
// Else, check if zero is present in the second set
else {
    if (y_set.contains(0)) {
        // If it is, remove it
        y_set.remove(0);
    }
}

// Combine both sets into a new set z
Set<Integer> z = new HashSet<>();
z.addAll(x_set);
z.addAll(y_set);

// Check if the size of the combined set is equal to the maximum level
if (z.size()!= max_level) {
    // If not, print an error message
    System.out.println("Oh, my keyboard!");
}
// Else, print a success message
else {
    System.out.println("I become the guy.");
}

