public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases
        int n = scanner.nextInt();
        
        // Read the first list 'a' of numbers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Read the second list 'b' of numbers
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        
        // Read the third list 'c' of numbers
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }
        
        // Initialize variables x, y, and z to 0
        int x = 0;
        int y = 0;
        int z = 0;
        
        // Iterate through each number in list 'a' and add it to the variable 'x'
        for (int i : a) {
            x += i;
        }
        
        // Iterate through each number in list 'b' and add it to the variable 'y'
        for (int i : b) {
            y += i;
        }
        
        // Iterate through each number in list 'c' and add it to the variable 'z'
        for (int i : c) {
            z += i;
        }
        
        // Print the absolute difference between 'x' and 'y'
        System.out.println(Math.abs(x - y));
        
        // Print the absolute difference between 'y' and 'z'
        System.out.println(Math.abs(y - z));
    }
}
