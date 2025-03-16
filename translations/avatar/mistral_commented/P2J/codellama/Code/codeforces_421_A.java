// Assigning the values of input variables to n, a, and b
int n = Integer.parseInt(scanner.nextLine());
int a = Integer.parseInt(scanner.nextLine());
int b = Integer.parseInt(scanner.nextLine());

// Creating two lists, lista and listb, from the input
List<Integer> lista = new ArrayList<>();
List<Integer> listb = new ArrayList<>();

// Iterating through the range of n
for (int k = 0; k < n; k++) {
    // Checking if k+1 is present in the lista list
    if (lista.contains(k + 1)) {
        // Printing 1 if k+1 is present in the lista list
        System.out.print(1 + " ");
    } else {
        // Printing 2 if k+1 is not present in the lista list
        System.out.print(2 + " ");
    }
}

