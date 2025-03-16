// Step 1: Input the number of nodes (n) and the number of edges (m)
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Step 2: Create a list of positions (p) from 1 to n
List<Integer> p = new ArrayList<>();
for (int i = 1; i <= n; i++) {
    p.add(i);
}

// Step 3: Input the heights (h) of the nodes
List<Integer> h = new ArrayList<>();
for (int i = 0; i < n; i++) {
    h.add(sc.nextInt());
}

// Step 4: Create a dictionary (hp) mapping positions to heights
Map<Integer, Integer> hp = new HashMap<>();
for (int i = 0; i < n; i++) {
    hp.put(p.get(i), h.get(i));
}

// Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
Map<Integer, List<Integer>> path = new HashMap<>();
for (int i = 1; i <= n; i++) {
    path.put(i, new ArrayList<>());
}

// Step 6: Input the edges of the graph and populate the adjacency list
for (int i = 0; i < m; i++) {
    int a = sc.nextInt();
    int b = sc.nextInt();
    path.get(a).add(b);
    path.get(b).add(a);
}

// Step 7: Count the number of nodes that are the highest in their neighborhoods
int c = 0;
for (int i : path.keySet()) {
    boolean f = false;
    for (int j : path.get(i)) {
        if (hp.get(i) <= hp.get(j)) {
            f = true;
            break;
        }
    }
    if (!f) {
        c++;
    }
}

// Step 8: Output the count of such nodes
System.out.println(c);

