public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();
        
        int[] arr = new int[(int)n + 1];
        for(int i = 0; i <= n; i++) {
            arr[i] = 0;
        }
        
        for(int i = 0; i < q; i++) {
            int temp = scanner.nextInt();
            arr[temp] += 1;
        }
        
        for(int i = 1; i <= n; i++) {
            if(arr[i] > (q - k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        
        scanner.close();
    }
}
