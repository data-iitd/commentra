// Read three integers from input: t (target), s (initial value), and q (growth factor)
Scanner sc = new Scanner(System.in);
int t = sc.nextInt();
int s = sc.nextInt();
int q = sc.nextInt();

// Initialize a counter for the number of iterations
int ans = 0;

// Loop until the initial value s is less than the target t
while (s < t) {
    // Multiply the current value of s by the growth factor q
    s *= q;
    // Increment the counter for each multiplication
    ans += 1;
}

// Print the total number of multiplications needed for s to reach or exceed t
System.out.println(ans);

