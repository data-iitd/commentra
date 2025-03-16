// Declare a variable named 'age' and assign it the value of an integer input from the user
Scanner scanner = new Scanner(System.in);
int age = scanner.nextInt();

// Check if the value of 'age' is equal to 1
if (age == 1) {
    // If the condition is met, print 'Hello World'
    System.out.println("Hello World");
} else {
    // If the condition is not met, declare two variables 'a' and 'b' and assign them the values of two integer inputs from the user
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    // Print the sum of 'a' and 'b'
    System.out.println(a + b);
}

