public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read input: number of elements 'n' and the difference 'k'
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Read input: list of elements 'elems'
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }

        // Helper function to check if all elements in a list are the same
        boolean allSame(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] != arr[0]) {
                    return false;
                }
            }
            return true;
        }

        // Check if all elements in the list are the same
        if (allSame(elems)) {
            // If all elements are the same, print 0 and exit
            System.out.println(0);
            return;
        }

        // Check if difference 'k' is 1
        if (k == 1) {
            // If difference is 1, print -1 and exit
            System.out.println(-1);
            return;
        }

        // Check if last 'k' elements in the list are not all the same
        if (!allSame(java.util.Arrays.copyOfRange(elems, k - 1, elems.length))) {
            // If last 'k' elements are not all the same, print -1 and exit
            System.out.println(-1);
            return;
        }

        // Initialize target element
        int target = elems[elems.length - 1];

        // Initialize list 'toDelete' to store elements to be deleted
        java.util.ArrayList<Integer> toDelete = new java.util.ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            toDelete.add(elems[i]);
        }

        // While 'toDelete' is not empty and its last element is 'target'
        while (!toDelete.isEmpty() && toDelete.get(toDelete.size() - 1) == target) {
            toDelete.remove(toDelete.size() - 1);
        }

        // Print the length of 'toDelete'
        System.out.println(toDelete.size());
    }
}
