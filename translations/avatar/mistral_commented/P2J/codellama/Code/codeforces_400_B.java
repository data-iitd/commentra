// Read input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize an empty set
HashSet<Integer> c = new HashSet<>();

// Populate set c with differences between indices of 'S' and 'G' in each string
for (int i = 0; i < n; i++) {
    String s = sc.next();
    int index_S = s.indexOf('S');
    int index_G = s.indexOf('G');
    int difference = index_S - index_G;
    c.add(difference);
}

// Check if there is any negative number in set c and print accordingly
if (c.contains(-1)) {
    System.out.println(-1);
} else {
    System.out.println(c.size());
}

