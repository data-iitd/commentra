import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of elements in the list from user input
        int n = scanner.nextInt();
        
        // Initialize an array to store the input elements
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize two lists to store even and odd elements respectively
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        
        // Iterate through the array 'x' and append even and odd elements to their respective lists
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a.add(x[i]);
            } else {
                b.add(x[i]);
            }
        }
        
        // Initialize two arrays to store the count of each element in lists 'a' and 'b' respectively
        int[] cnta = new int[100003]; // 100002 + 1
        int[] cntb = new int[100003]; // 100002 + 1
        
        // Initialize variables to store the elements with maximum count in lists 'a' and 'b' respectively
        int vala = 0, valb = 0;
        int maxCnta = 0, maxCntb = 0;
        int vala1 = 0, valb1 = 0;
        int maxCnta1 = 0, maxCntb1 = 0;

        // Iterate through list 'a' and update the count of each element in 'cnta'
        for (int i : a) {
            cnta[i]++;
        }

        // Find the element with maximum count in list 'a'
        for (int i : a) {
            if (maxCnta < cnta[i]) {
                vala = i;
                maxCnta = cnta[i];
            }
        }

        // Find the second element with maximum count in list 'a' (different from 'vala')
        for (int i : a) {
            if (maxCnta1 < cnta[i] && i != vala) {
                maxCnta1 = cnta[i];
                vala1 = i;
            }
        }

        // Similar logic for list 'b'
        for (int i : b) {
            cntb[i]++;
        }

        // Find the element with maximum count in list 'b'
        for (int i : b) {
            if (maxCntb < cntb[i]) {
                valb = i;
                maxCntb = cntb[i];
            }
        }

        // Find the second element with maximum count in list 'b' (different from 'valb')
        for (int i : b) {
            if (maxCntb1 < cntb[i] && i != valb) {
                maxCntb1 = cntb[i];
                valb1 = i;
            }
        }

        // Check if 'vala' and 'valb' are same or not
        if (valb != vala) {
            // If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb'
            int res = 0;
            for (int i : a) {
                if (i != vala) {
                    res++;
                }
            }
            for (int i : b) {
                if (i != valb) {
                    res++;
                }
            }
            System.out.println(res);
        } else {
            // If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b'
            // and print the minimum of these two sums
            int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
            for (int i : a) {
                if (i != vala) {
                    resa++;
                }
                if (i != vala1) {
                    resa1++;
                }
            }
            for (int i : b) {
                if (i != valb) {
                    resb++;
                }
                if (i != valb1) {
                    resb1++;
                }
            }
            System.out.println(Math.min(resa + resb1, resa1 + resb));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
