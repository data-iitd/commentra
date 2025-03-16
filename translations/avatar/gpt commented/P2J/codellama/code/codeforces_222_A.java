public class Main {
    public static void main(String[] args) {
        // Read two integers n and k from input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read a list of n integers from input
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }
        
        // Define a lambda function to check if all elements in an array are the same
        boolean allSame(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] != arr[0]) {
                    return false;
                }
            }
            return true;
        }
        
        // If all elements in elems are the same, print 0 and exit
        if (allSame(elems)) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // If the last k-1 elements are not the same, print -1 and exit
        if (!allSame(Arrays.copyOfRange(elems, k - 1, n))) {
            System.out.println(-1);
            return;
        }
        
        // Set the target value to the last element of elems
        int target = elems[n - 1];
        
        // Create a list of elements to delete, which are the first k-1 elements
        int[] toDelete = Arrays.copyOfRange(elems, 0, k - 1);
        
        // Remove elements from toDelete that are equal to the target from the end
        while (toDelete.length > 0 && toDelete[toDelete.length - 1] == target) {
            toDelete = Arrays.copyOfRange(toDelete, 0, toDelete.length - 1);
        }
        
        // Print the number of elements that need to be deleted
        System.out.println(toDelete.length);
    }
}
