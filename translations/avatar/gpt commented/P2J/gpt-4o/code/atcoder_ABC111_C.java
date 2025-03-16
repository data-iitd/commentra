import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the elements into a list
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize two lists to hold elements at even and odd indices
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        
        // Distribute elements into lists based on their index (even or odd)
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a.add(x[i]);  // Append to list 'a' if index is even
            } else {
                b.add(x[i]);  // Append to list 'b' if index is odd
            }
        }
        
        // Initialize counters for occurrences of elements in lists 'a' and 'b'
        int[] cnta = new int[100003]; // 100002 + 1
        int[] cntb = new int[100003]; // 100002 + 1
        
        // Variables to track the most frequent elements in list 'a'
        int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;

        // Count occurrences of each element in list 'a'
        for (int i : a) {
            cnta[i]++;
        }

        // Find the most frequent element in list 'a'
        for (int i : a) {
            if (maxCnta < cnta[i]) {
                vala = i;
                maxCnta = cnta[i];
            }
        }

        // Find the second most frequent element in list 'a'
        for (int i : a) {
            if (maxCnta1 < cnta[i] && vala != i) {
                maxCnta1 = cnta[i];
                vala1 = i;
            }
        }

        // Variables to track the most frequent elements in list 'b'
        int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;

        // Count occurrences of each element in list 'b'
        for (int i : b) {
            cntb[i]++;
        }

        // Find the most frequent element in list 'b'
        for (int i : b) {
            if (maxCntb < cntb[i]) {
                valb = i;
                maxCntb = cntb[i];
            }
        }

        // Find the second most frequent element in list 'b'
        for (int i : b) {
            if (maxCntb1 < cntb[i] && valb != i) {
                maxCntb1 = cntb[i];
                valb1 = i;
            }
        }

        // Check if the most frequent elements from both lists are different
        if (valb != vala) {
            int res = 0;
            // Count elements in 'a' that are not the most frequent element
            for (int i : a) {
                if (i != vala) {
                    res++;
                }
            }
            // Count elements in 'b' that are not the most frequent element
            for (int i : b) {
                if (i != valb) {
                    res++;
                }
            }
            // Print the total count of elements that are not the most frequent
            System.out.println(res);
        } else {
            // Initialize counters for elements not equal to the most frequent elements
            int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
            
            // Count elements in 'a' that are not the most frequent and second most frequent
            for (int i : a) {
                if (i != vala) {
                    resa++;
                }
                if (i != vala1) {
                    resa1++;
                }
            }
            
            // Count elements in 'b' that are not the most frequent and second most frequent
            for (int i : b) {
                if (i != valb) {
                    resb++;
                }
                if (i != valb1) {
                    resb1++;
                }
            }
            
            // Print the minimum of the two possible results
            System.out.println(Math.min(resa + resb1, resa1 + resb));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
