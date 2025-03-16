public class CountingSort {
    public static void main(String[] args) {
        int[] a, b;
        int i, max = 0, n;
        
        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Dynamically allocate memory for arrays a and b
        a = new int[n + 1];
        b = new int[n + 1];
        
        // Read elements into array a starting from index 1 to n
        for(i = 0; i < n; i++){
            a[i + 1] = scanner.nextInt();
        }
        
        // Call CountingSort function to sort the array
        CountingSort(a, b, n);
        
        // Print the sorted elements starting from index 1 to n
        System.out.print(b[1]);
        for(i = 2; i < n + 1; i++) System.out.print(" " + b[i]);
        System.out.println();
        
        // Free the allocated memory
        a = null;
        b = null;
    }
    
    // Function to perform Counting Sort
    public static void CountingSort(int[] a, int[] b, int k){
        int[] c = new int[10001]; // Define a constant I with the value 10000
        
        // Initialize array c to store the count of each element
        for(int i = 0; i <= 10000; i++) c[i] = 0;
        
        // Count the occurrences of each element in array a
        for(int j = 0; j < k; j++) c[a[j + 1]]++;
        
        // Compute the cumulative count to determine the positions of elements in the sorted array
        for(int i = 1; i < 10001; i++) c[i] += c[i - 1];
        
        // Place elements into array b in sorted order
        for(int j = k; j > 0; j--){
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }
}
