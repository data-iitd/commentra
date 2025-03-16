// Read two integers from input: h (height) and a (height per shoe)
Scanner sc = new Scanner(System.in);
int h = sc.nextInt();
int a = sc.nextInt();

// Calculate the number of shoes needed by performing integer division
int sho = h / a;

// Calculate the remaining height after accounting for full shoes
int am = h % a;

// If there is any remaining height, we need one additional shoe
if (am != 0) {
    sho++;  // Increment the shoe count by 1 for the remaining height
} else {
    // No additional shoe needed if there is no remaining height
}

// Print the total number of shoes required
System.out.println(sho);

