// Read input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize an empty set
Set<Integer> c = new HashSet<>();

// Populate set c with differences between indices of 'S' and 'G' in each string
for (int i = 0; i < n; i++) {
    String s = sc.next();

    // Find the indices of 'S' and 'G' in the current string
    int index_S = s.indexOf('S');
    int index_G = s.indexOf('G');

    // Calculate the difference and add it to the set
    int difference = index_S - index_G;
    c.add(difference);
}

// Check if there is any negative number in set c and print accordingly
System.out.println(c.contains(0)? -1 : c.size());

