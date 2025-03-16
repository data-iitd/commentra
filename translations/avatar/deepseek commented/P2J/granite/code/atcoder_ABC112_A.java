

Scanner scanner = new Scanner(System.in);
int age = scanner.nextInt();  // Taking an integer input for the variable `age`
if (age == 1) {  // Checking if `age` is equal to 1
    System.out.println("Hello World");  // If `age` is 1, it prints "Hello World"
} else {  // If `age` is not 1
    int a = scanner.nextInt();  // Taking an integer input for the variable `a`
    int b = scanner.nextInt();  // Taking an integer input for the variable `b`
    System.out.println(a + b);  // Printing the sum of `a` and `b`
}
// END-OF-CODE