// Read the number of elements and the list of integers from input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
if (sum(a) % (n * (n + 1) / 2)) {
    // If not divisible, print "NO" and exit
    System.out.println("NO");
    System.exit(0);
}

// Calculate the average value 'k' that each element should contribute
int k = sum(a) / (n * (n + 1) / 2);

// Append the first element of 'a' to the end of the list to facilitate circular calculations
a = Arrays.copyOf(a, a.length + 1);
a[a.length - 1] = a[0];

// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
if (sum([(k - i + j) % n for i, j in zip(a[1:], a)]) || sum([(k - i + j) / n >= 0 for i, j in zip(a[1:], a)])!= n) {
    // If either condition fails, print "NO"
    System.out.println("NO");
} else {
    // If both conditions are satisfied, print "YES"
    System.out.println("YES");
}

