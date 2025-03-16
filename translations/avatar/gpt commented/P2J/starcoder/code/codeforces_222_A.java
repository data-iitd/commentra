public class Main {
    public static void main(String[] args) {
        // Read two integers n and k from input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // Read a list of n integers from input
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = sc.nextInt();
        }
        
        // Define a lambda function to check if all elements in an array are the same
        Predicate<int[]> all_same = arr -> {
            for (int i = 1; i < arr.length; i++) {
                if (arr[i]!= arr[0]) {
                    return false;
                }
            }
            return true;
        };
        
        // If all elements in elems are the same, print 0 and exit
        if (all_same.test(elems)) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // If the last k-1 elements are not the same, print -1 and exit
        if (!all_same.test(Arrays.copyOfRange(elems, elems.length - k + 1, elems.length))) {
            System.out.println(-1);
            return;
        }
        
        // Set the target value to the last element of elems
        int target = elems[elems.length - 1];
        
        // Create a list of elements to delete, which are the first k-1 elements
        List<Integer> to_delete = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            to_delete.add(elems[i]);
        }
        
        // Remove elements from to_delete that are equal to the target from the end
        while (!to_delete.isEmpty() && to_delete.get(to_delete.size() - 1) == target) {
            to_delete.remove(to_delete.size() - 1);
        }
        
        // Print the number of elements that need to be deleted
        System.out.println(to_delete.size());
    }
}

