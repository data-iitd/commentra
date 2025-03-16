// Read three integers from input: t (target), s (initial value), and q (growth factor)
Scanner scanner = new Scanner(System.in);
int t = scanner.nextInt();
int s = scanner.nextInt();
int q = scanner.nextInt();

// Initialize a counter for the number of iterations
int ans = 0;

// Loop until the initial value s is less than the target t
while (s < t) {
    // Multiply the current value of s by the growth factor q
    s *= q;
    // Increment the counter for each multiplication
    ans++;
}

// Print the total number of multiplications needed for s to reach or exceed t
System.out.println(ans);

