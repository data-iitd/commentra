
// Read three integers from input: n (number of elements), a, and b
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int a = sc.nextInt();
int b = sc.nextInt();

// Read a list of integers from input and store it in lista
int[] lista = new int[n];
for (int i = 0; i < n; i++) {
    lista[i] = sc.nextInt();
}

// Read another list of integers from input and store it in listb
int[] listb = new int[n];
for (int i = 0; i < n; i++) {
    listb[i] = sc.nextInt();
}

// Iterate through the range of n (from 0 to n-1)
for (int k = 0; k < n; k++) {
    // Check if the current index + 1 is present in lista
    if (Arrays.binarySearch(lista, k + 1) >= 0) {
        // If present, print 1 followed by a space
        System.out.print(1 + " ");
    } else {
        // If not present, print 2 followed by a space
        System.out.print(2 + " ");
    }
}

// End of code
