// Read an integer input N, which represents the number of elements in the list
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();

// Read a line of input, split it into individual string elements, convert them to integers,
// and store them in a list A
List<Integer> A = new ArrayList<>();
for (int i = 0; i < N; i++) {
    A.add(scanner.nextInt());
}

// Calculate the GCD of all elements in the list A using functools.reduce and fractions.gcd
int gcd = A.stream().reduce(1, (a, b) -> a * b);

// Print the calculated GCD
System.out.println(gcd);

