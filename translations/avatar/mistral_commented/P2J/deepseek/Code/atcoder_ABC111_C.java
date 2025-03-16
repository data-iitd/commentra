import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of elements in the list from user input
        int n = scanner.nextInt();
        
        // Initialize an empty list 'x' to store the input elements
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        
        // Iterate through the list 'x' and append even and odd elements to their respective lists
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a.add(x[i]);
            } else {
                b.add(x[i]);
            }
        }
        
        // Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
        int[] cnta = new int[100003];
        int[] cntb = new int[100003];
        
        // Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
        int vala = 0;
        int valb = 0;
        
        // Initialize two variables 'maxCnta' and 'maxCntb' to store the maximum count of an element in lists 'a' and 'b' respectively
        int maxCnta = 0;
        int maxCntb = 0;
        
        // Initialize two variables 'maxCnta1' and 'maxCntb1' to store the second maximum count of an element in lists 'a' and 'b' respectively
        int maxCnta1 = 0;
        int maxCntb1 = 0;
        
        // Initialize two variables 'vala1' and 'valb1' to store the second element with maximum count in lists 'a' and 'b' respectively
        int vala1 = 0;
        int valb1 = 0;
        
        // Iterate through list 'a' and update the count of each element in 'cnta'
        for (int i : a) {
            cnta[i]++;
        }
        
        // Find the element with maximum count in list 'a' and update 'vala' and 'maxCnta'
        for (int i : a) {
            if (maxCnta < cnta[i]) {
                vala = i;
                maxCnta = cnta[i];
            }
        }
        
        // Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and 'maxCnta1'
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
        
        // Find the element with maximum count in list 'b' and update 'valb' and 'maxCntb'
        for (int i : b) {
            if (maxCntb < cntb[i]) {
                valb = i;
                maxCntb = cntb[i];
            }
        }
        
        // Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and 'maxCntb1'
        for (int i : b) {
            if (maxCntb1 < cntb[i] && i != valb) {
                maxCntb1 = cntb[i];
                valb1 = i;
            }
        }
        
        // Check if 'vala' and 'valb' are same or not
        if (valb != vala) {
            // If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
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
            // If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
            // and print the minimum of these two sums
            int resa = 0;
            int resb = 0;
            int resa1 = 0;
            int resb1 = 0;
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
    }
}
