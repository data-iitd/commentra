public class Main {
    public static void main(String[] args) {
        // Read the number of elements N
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        
        // Read N integers into an array `a`
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize idx to 1 and ans to 0
        int idx = 1;
        int ans = 0;
        
        // Iterate through the array `a`
        for (int i = 0; i < N; i++) {
            // If the current element is equal to `idx`, increment `idx`
            if (a[i] == idx) {
                idx++;
            } else {
                // If not, increment `ans`
                ans++;
            }
        }
        
        // If `idx` is still 1, it means no elements matched, so print `-1`
        if (idx == 1) {
            System.out.println(-1);
        } else {
            // Otherwise, print `ans`
            System.out.println(ans);
        }
    }
}
