// Take the number of test cases as input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read the first list 'a' of numbers from the standard input
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Read the second list 'b' of numbers from the standard input
int[] b = new int[n];
for (int i = 0; i < n; i++) {
    b[i] = sc.nextInt();
}

// Read the third list 'c' of numbers from the standard input
int[] c = new int[n];
for (int i = 0; i < n; i++) {
    c[i] = sc.nextInt();
}

// Initialize variables x, y, and z to 0
int x = 0;
int y = 0;
int z = 0;

// Iterate through each number in list 'a' and add it to the variable 'x'
for (int i = 0; i < n; i++) {
    x += a[i];
}

// Iterate through each number in list 'b' and add it to the variable 'y'
for (int i = 0; i < n; i++) {
    y += b[i];
}

// Iterate through each number in list 'c' and add it to the variable 'z'
for (int i = 0; i < n; i++) {
    z += c[i];
}

// Print the absolute difference between 'x' and 'y'
System.out.println(Math.abs(x - y));

// Print the absolute difference between 'y' and 'z'
System.out.println(Math.abs(y - z));

