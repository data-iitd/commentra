// Read two integers n and m from input, representing the number of strings and some other parameter
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Create a set comprehension to calculate the difference in indices of 'S' and 'G' for each string
// The difference is calculated as the index of 'S' minus the index of 'G'
Set<Integer> c = new HashSet<>();
for (int i = 0; i < n; i++) {
    String s = sc.next();
    c.add(s.indexOf("S") - s.indexOf("G"));
}

// Check if any of the calculated differences are negative
// If any difference is negative, print -1; otherwise, print the number of unique differences
if (c.stream().anyMatch(a -> a < 0)) {
    System.out.println(-1);
} else {
    System.out.println(c.size());
}

