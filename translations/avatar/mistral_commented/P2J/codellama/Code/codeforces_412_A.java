// Read the number of elements `n` and the number of queries `k` from the standard input
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int k = scanner.nextInt();

// Read a single string `v` from the standard input
String v = scanner.next();

// Initialize a list `d` with two elements: "LEFT" and "RIGHT"
List<String> d = new ArrayList<String>();
d.add("LEFT");
d.add("RIGHT");

// Determine the direction based on the difference between `k` and `n-k`
boolean f = k - 1 < n - k;

// Determine the number of elements to be appended to the list `a`
int m = Math.min(k - 1, n - k);

// Initialize an empty list `a`
List<String> a = new ArrayList<String>();

// Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
for (int i = 0; i < m; i++) {
    a.add(d.get(f ? 0 : 1));
}

// Iterate through the string `v` with a step of 2 times the value of `f`
for (int i = 0; i < v.length(); i += 2 * f) {
    // Append "PRINT <character>" and the corresponding direction to the list `a`
    a.add("PRINT " + v.charAt(i));
    a.add(d.get(f ? 0 : 1));
}

// Print all the elements of the list `a`, except the last one, separated by newline characters
for (int i = 0; i < a.size() - 1; i++) {
    System.out.println(a.get(i));
}

// Print the last element of the list `a`
System.out.println(a.get(a.size() - 1));

