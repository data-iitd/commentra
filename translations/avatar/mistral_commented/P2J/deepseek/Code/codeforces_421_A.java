public class Main {
    public static void main(String[] args) {
        // Assigning the values of input variables to n, a, and b
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Creating two lists, lista and listb, from the input
        int[] lista = new int[a];
        int[] listb = new int[b];

        for (int i = 0; i < a; i++) {
            lista[i] = scanner.nextInt();
        }

        for (int i = 0; i < b; i++) {
            listb[i] = scanner.nextInt();
        }

        // Iterating through the range of n
        for (int k = 0; k < n; k++) {
            // Checking if k+1 is present in the lista list
            boolean isInLista = false;
            for (int j = 0; j < a; j++) {
                if (k + 1 == lista[j]) {
                    isInLista = true;
                    break;
                }
            }

            // Printing 1 if k+1 is present in the lista list
            if (isInLista) {
                System.out.print(1 + " ");
            } else {
                // Printing 2 if k+1 is not present in the lista list
                System.out.print(2 + " ");
            }
        }
        System.out.println(); // Print a newline at the end
    }
}
