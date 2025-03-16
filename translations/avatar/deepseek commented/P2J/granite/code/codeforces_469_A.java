
// The code starts by taking input for the maximum level and two lists of integers.
Scanner scanner = new Scanner(System.in);
int maxLevel = scanner.nextInt();
List<Integer> x = Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
List<Integer> y = Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
x.remove(0);
y.remove(0);
Set<Integer> xSet = new HashSet<>(x);
Set<Integer> ySet = new HashSet<>(y);

// If there's a 0 in either set, discard it from the set.
if (xSet.contains(0)) {
    xSet.remove(0);
} else if (ySet.contains(0)) {
    ySet.remove(0);
}

// Find the union of the two sets and check if its length is equal to the maximum level.
Set<Integer> z = new HashSet<>(xSet);
z.addAll(ySet);
if (z.size()!= maxLevel) {
    System.out.println("Oh, my keyboard!");
} else {
    System.out.println("I become the guy.");
}

