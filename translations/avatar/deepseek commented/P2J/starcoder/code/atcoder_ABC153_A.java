// Step 1: Taking input from the user
Scanner sc = new Scanner(System.in);
int h = sc.nextInt();
int a = sc.nextInt();

// Step 2: Calculating the number of times 'a' fits into 'h' and the remainder
int sho = h / a;
int am = h % a;

// Step 3: Checking if there is a remainder and incrementing the count if necessary
if (am!= 0) {
    sho += 1;
} else {
    pass;
}

// Step 4: Printing the result
System.out.println(sho);

