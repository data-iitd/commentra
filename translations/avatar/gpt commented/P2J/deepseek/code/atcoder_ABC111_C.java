import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the elements into an array
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize two arrays to hold elements at even and odd indices
        int[] a = new int[n];
        int[] b = new int[n];
        
        // Distribute elements into arrays based on their index (even or odd)
        int evenIndex = 0, oddIndex = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[evenIndex++] = x[i];  // Append to array 'a' if index is even
            } else {
                b[oddIndex++] = x[i];  // Append to array 'b' if index is odd
            }
        }
        
        // Initialize counters for occurrences of elements in arrays 'a' and 'b'
        int[] cnta = new int[100003];
        int[] cntb = new int[100003];
        
        // Variables to track the most frequent elements in array 'a'
        int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
        
        // Count occurrences of each element in array 'a'
        for (int i = 0; i < evenIndex; i++) {
            cnta[a[i]]++;
        }
        
        // Find the most frequent element in array 'a'
        for (int i = 0; i < evenIndex; i++) {
            if (maxCnta < cnta[a[i]]) {
                vala = a[i];
                maxCnta = cnta[a[i]];
            }
        }
        
        // Find the second most frequent element in array 'a'
        for (int i = 0; i < evenIndex; i++) {
            if (maxCnta1 < cnta[a[i]] && vala != a[i]) {
                maxCnta1 = cnta[a[i]];
                vala1 = a[i];
            }
        }
        
        // Variables to track the most frequent elements in array 'b'
        int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
        
        // Count occurrences of each element in array 'b'
        for (int i = 0; i < oddIndex; i++) {
            cntb[b[i]]++;
        }
        
        // Find the most frequent element in array 'b'
        for (int i = 0; i < oddIndex; i++) {
            if (maxCntb < cntb[b[i]]) {
                valb = b[i];
                maxCntb = cntb[b[i]];
            }
        }
        
        // Find the second most frequent element in array 'b'
        for (int i = 0; i < oddIndex; i++) {
            if (maxCntb1 < cntb[b[i]] && valb != b[i]) {
                maxCntb1 = cntb[b[i]];
                valb1 = b[i];
            }
        }
        
        // Check if the most frequent elements from both arrays are different
        if (valb != vala) {
            int res = 0;
            // Count elements in 'a' that are not the most frequent element
            for (int i = 0; i < evenIndex; i++) {
                if (a[i] != vala) {
                    res++;
                }
            }
            // Count elements in 'b' that are not the most frequent element
            for (int i = 0; i < oddIndex; i++) {
                if (b[i] != valb) {
                    res++;
                }
            }
            // Print the total count of elements that are not the most frequent
            System.out.println(res);
        } else {
            // Initialize counters for elements not equal to the most frequent elements
            int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
            
            // Count elements in 'a' that are not the most frequent and second most frequent
            for (int i = 0; i < evenIndex; i++) {
                if (a[i] != vala) {
                    resa++;
                }
                if (a[i] != vala1) {
                    resa1++;
                }
            }
            
            // Count elements in 'b' that are not the most frequent and second most frequent
            for (int i = 0; i < oddIndex; i++) {
                if (b[i] != valb) {
                    resb++;
                }
                if (b[i] != valb1) {
                    resb1++;
                }
            }
            
            // Print the minimum of the two possible results
            System.out.println(Math.min(resa + resb1, resa1 + resb));
        }
    }
}
