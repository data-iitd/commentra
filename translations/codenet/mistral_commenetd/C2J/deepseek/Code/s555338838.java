public class InsertionSort {
    public static void main(String[] args) {
        // Declare variables
        int key, i, j, len;
        int[] a = new int[101];

        // Read the length of the array from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter the length of the array: ");
        len = scanner.nextInt();

        // Read the elements of the array from the user
        System.out.printf("Enter %d integers: ", len);
        for(i = 0; i < len; i++) {
            a[i] = scanner.nextInt();
        }

        // Sort the array using insertion sort algorithm
        for(j = 1; j < len; j++) {
            // Print the array before each pass
            for(i = 0; i < len; i++) {
                if(i != 0) System.out.print(" " + a[i]);
                else System.out.print(a[i]);
            }
            System.out.println();

            // Set the current key to the next element
            key = a[j];

            // Swap the current key with the previous element if it is greater
            for(i = j - 1; i >= 0 && a[i] > key; i--) {
                a[i + 1] = a[i];
            }

            // Swap the current key with the previous element
            a[i + 1] = key;
        }

        // Print the sorted array
        for(i = 0; i < len; i++) {
            if(i != 0) System.out.print(" " + a[i]);
            else System.out.print(a[i]);
        }
        System.out.println();
    }
}
