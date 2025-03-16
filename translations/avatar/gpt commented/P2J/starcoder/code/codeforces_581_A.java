// Read two integers from input and unpack them into variables a and b
Scanner scanner = new Scanner(System.in);
int a = scanner.nextInt();
int b = scanner.nextInt();

// Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
// Print the minimum value and the calculated half difference
System.out.println(Math.min(a, b) + " " + ((Math.max(a, b) - Math.min(a, b)) / 2));

