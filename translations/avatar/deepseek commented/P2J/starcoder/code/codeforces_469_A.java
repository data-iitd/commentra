// The code starts by taking input for the maximum level and two lists of integers.
int max_level = Integer.parseInt(input());
List<Integer> x = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
List<Integer> y = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
x.remove(0);
y.remove(0);
Set<Integer> x_set = new HashSet<>(x);
Set<Integer> y_set = new HashSet<>(y);

// If there's a 0 in either set, discard it from the set.
if (x_set.contains(0)) {
    x_set.remove(0);
}
if (y_set.contains(0)) {
    y_set.remove(0);
}

// Find the union of the two sets and check if its length is equal to the maximum level.
Set<Integer> z = new HashSet<>(x_set);
z.addAll(y_set);
if (z.size()!= max_level) {
    System.out.println("Oh, my keyboard!");
} else {
    System.out.println("I become the guy.");
}

