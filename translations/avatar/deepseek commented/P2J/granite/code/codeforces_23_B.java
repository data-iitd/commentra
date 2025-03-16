

Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input from the user.
int n = scanner.nextInt();  // Taking an integer input `n` which represents the number of iterations.
for (int i = 0; i < n; i++) {  // Looping `n` times.
    int a = scanner.nextInt();  // Taking an integer input `a` for each iteration.
    if (a < 2) {  // Checking if `a` is less than 2.
        System.out.println(0);  // Printing 0 if `a` is less than 2.
    } else {  // If `a` is not less than 2.
        System.out.println(a - 2);  // Printing the result of `a - 2`.
    }
}
// 