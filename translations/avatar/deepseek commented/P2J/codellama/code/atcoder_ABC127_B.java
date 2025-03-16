// Read three integers r, D, and x from input
Scanner scanner = new Scanner(System.in);
int r = scanner.nextInt();
int D = scanner.nextInt();
int x = scanner.nextInt();

// Loop from 2 to 11 (inclusive)
for (int i = 2; i <= 11; i++) {
    // Calculate the value using the given formula and print the integer result
    int result = (int) ((Math.pow(r, i - 1)) * (x + D / (1 - r)) - D / (1 - r));
    System.out.println(result);
}

