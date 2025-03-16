// The code starts by taking input for the maximum level and two lists of integers.
Scanner sc = new Scanner(System.in);
int max_level = sc.nextInt();
int[] x = new int[max_level];
int[] y = new int[max_level];

// Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
for (int i = 0; i < max_level; i++) {
    x[i] = sc.nextInt();
}
for (int i = 0; i < max_level; i++) {
    y[i] = sc.nextInt();
}

x[0] = 0;
y[0] = 0;

HashSet<Integer> xSet = new HashSet<Integer>();
HashSet<Integer> ySet = new HashSet<Integer>();

for (int i = 1; i < max_level; i++) {
    xSet.add(x[i]);
    ySet.add(y[i]);
}

if (xSet.contains(0) || ySet.contains(0)) {
    if (xSet.contains(0)) {
        xSet.remove(0);
    } else {
        ySet.remove(0);
    }
}

// Find the union of the two sets and check if its length is equal to the maximum level.
HashSet<Integer> zSet = new HashSet<Integer>();
zSet.addAll(xSet);
zSet.addAll(ySet);

if (zSet.size() != max_level) {
    System.out.println("Oh, my keyboard!");
} else {
    System.out.println("I become the guy.");
}

