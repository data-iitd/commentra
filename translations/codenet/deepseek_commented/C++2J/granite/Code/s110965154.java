
/*
 * InsertionSort.java
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
import java.util.Scanner;
import java.util.Vector;

public class s110965154{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Vector<Integer> vecIntValue = new Vector<Integer>();
        for (int i = 0; i < n; i++) {
            int iIntValue = sc.nextInt();
            vecIntValue.add(iIntValue);
        }
        sort(vecIntValue);
        sc.close();
    }

    public static void sort(Vector<Integer> a_rvecIntValue) {
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            if (i!= 0) {
                int iIntValue = a_rvecIntValue.get(i);
                int j = i - 1;
                while ((j >= 0) && (a_rvecIntValue.get(j) > iIntValue)) {
                    a_rvecIntValue.set(j+1, a_rvecIntValue.get(j));
                    j--;
                }
                a_rvecIntValue.set(j+1, iIntValue);
            }
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k));
                if (k!= a_rvecIntValue.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}

// Step 5: Output
// The program outputs the sorted vector after each insertion.

