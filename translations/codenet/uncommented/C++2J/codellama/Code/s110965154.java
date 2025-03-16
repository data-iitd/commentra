/*
 * InsertionSort.java
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
import java.util.Scanner;
import java.util.Vector;
 
public class InsertionSort {
 
    public static void main(String[] args) {
 
        Scanner scanner = new Scanner(System.in);
        int iNum = scanner.nextInt();
        Vector<Integer> vecIntValue = new Vector<Integer>();
        while (iNum > 0) {
            int iIntValue = scanner.nextInt();
            vecIntValue.add(iIntValue);
            iNum--;
        }
 
        sort(vecIntValue);
    }
 
    public static void sort(Vector<Integer> a_rvecIntValue) {
 
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
 
            if (i != 0) {
 
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
                if (k != a_rvecIntValue.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
