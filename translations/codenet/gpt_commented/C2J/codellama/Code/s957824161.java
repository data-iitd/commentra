
// Declare global variables for storing two integers
int x, y;

public static void main(String[] args) {
    // Read two integers from user input
    Scanner sc = new Scanner(System.in);
    x = sc.nextInt();
    y = sc.nextInt();
    
    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    System.out.println(x * y + " " + 2 * x + 2 * y);
    
    // Return 0 to indicate successful completion of the program
    return;
}

