// Take input from the user
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Check if the sum of the elements in the list is divisible by the formula
if (Arrays.stream(a).sum() % (n * (n + 1) / 2)!= 0) {
    System.out.println("NO");
    return;
}

// Calculate the average of the elements in the list
double k = Arrays.stream(a).sum() / (n * (n + 1) / 2);

// Add the first element to the end of the list for simplification
a = Arrays.copyOf(a, n + 1);
a[n] = a[0];

// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
if (Arrays.stream(a).mapToObj(i -> (k - i + a[(i + 1) % n]) % n).mapToInt(Integer::intValue).sum()!= 0 ||
    Arrays.stream(a).mapToObj(i -> (k - i + a[(i + 1) % n]) / n).mapToInt(Double::intValue).sum()!= n) {
    System.out.println("NO");
    return;
}

// If all checks pass, print YES
System.out.println("YES");

