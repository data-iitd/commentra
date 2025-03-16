// Read three integers r, D, and x from input
Scanner sc = new Scanner(System.in);
int r = sc.nextInt();
int D = sc.nextInt();
int x = sc.nextInt();

// Loop from 2 to 11 (inclusive)
for (int i = 2; i <= 11; i++) {
    // Calculate the value using the given formula and print the integer result
    int result = (int) ((Math.pow(r, i - 1) * (x + (D / (1 - r)))) - (D / (1 - r)));
    System.out.println(result);
}

