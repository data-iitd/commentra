public class Main {
    static int[] A = new int[1000000];
    static int n;

    /* 
     * binarySearch function performs a binary search on the array A to find a given key.
     * It returns 1 if the key is found, otherwise it returns 0.
     */
    static int binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(key == A[mid]) return 1; /* keyを発見 */
            if(key > A[mid]) left = mid + 1; /* 後半を探索 */
            else if(key < A[mid]) right = mid; /* 前半を探索 */
        }
        return 0;
    }

    /* 
     * main function is the entry point of the program.
     * It reads the size of the array and the elements of the array from the user.
     * It then reads the number of queries and performs binary search for each query.
     * Finally, it prints the number of elements found.
     */
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        for(int i=0; i<n; i++) {
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int sum = 0;
        for(int i=0;i<q;i++) {
            int k = scanner.nextInt();
            if(binarySearch(k))
                sum++;
        }
        System.out.println(sum);
    }
}
