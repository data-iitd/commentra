// Read two integers from input, separated by a space
Scanner scanner = new Scanner(System.in);
int vamshi = scanner.nextInt();
int z = scanner.nextInt();

// Calculate the smallest multiple of z that is greater than or equal to vamshi
// This is done by performing integer division of vamshi by z, adding 1, and then multiplying by z
int result = (vamshi / z + 1) * z;

// Print the result
System.out.println(result);

