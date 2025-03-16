
public class Main {

    public static void main(String[] args) {

        // Read input: number of elements 'n' and the difference 'k'
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Read input: list of elements 'elems'
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = sc.nextInt();
        }

        // Helper function to check if all elements in a list are the same
        public boolean allSame(int[] arr) {
            // Return True if all elements in the list are the same, else False
            for (int i = 1; i < arr.length; i++) {
                if (arr[i]!= arr[0]) {
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
        if (!allSame(Arrays.copyOfRange(elems, n - k, n))) {
            // If last 'k' elements are not all the same, print -1 and exit
            System.out.println(-1);
            return;
        }

        // Initialize target element
        int target = elems[n - 1];

        // Initialize list 'to_delete' to store elements to be deleted
        List<Integer> to_delete = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            to_delete.add(elems[i]);
        }

        // While 'to_delete' is not empty and its last element is 'target'
        while (!to_delete.isEmpty() && to_delete.get(to_delete.size() - 1) == target) {
            // Pop the last element from 'to_delete'
            to_delete.remove(to_delete.size() - 1);
        }

        // Print the length of 'to_delete'
        System.out.println(to_delete.size());
    }
}

