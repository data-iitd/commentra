// Prompt the user to input their age and convert it to an integer
Scanner scanner = new Scanner(System.in);
int age = scanner.nextInt();

// Check if the age is equal to 1
if (age == 1) {
    // If age is 1, print 'Hello World'
    System.out.println("Hello World");
} else {
    // If age is not 1, prompt the user to input two integers
    Scanner scanner2 = new Scanner(System.in);
    int a = scanner2.nextInt();
    int b = scanner2.nextInt();
    // Calculate and print the sum of the two integers
    System.out.println(a + b);
}

