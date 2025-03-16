// Read an integer input which represents the number of elements in the lists
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read three lists of integers from input
List<Integer> a = new ArrayList<>();
List<Integer> b = new ArrayList<>();
List<Integer> c = new ArrayList<>();
for (int i = 0; i < n; i++) {
    a.add(sc.nextInt());
}
for (int i = 0; i < n; i++) {
    b.add(sc.nextInt());
}
for (int i = 0; i < n; i++) {
    c.add(sc.nextInt());
}

// Initialize variables to hold the sum of each list
int x = 0;
int y = 0;
int z = 0;

// Calculate the sum of elements in list 'a'
for (int i : a) {
    x += i;
}

// Calculate the sum of elements in list 'b'
for (int i : b) {
    y += i;
}

// Calculate the sum of elements in list 'c'
for (int i : c) {
    z += i;
}

// Print the absolute difference between the sums of list 'a' and list 'b'
System.out.println(Math.abs(x - y));

// Print the absolute difference between the sums of list 'b' and list 'c'
System.out.println(Math.abs(y - z));

