// Ask the user for the size of the permutation list
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Import the itertools module for generating permutations
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Create a list of all possible permutations of numbers from 1 to n
List<List<Integer>> orig = new ArrayList<>();
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            if (i != j && i != k && j != k) {
                List<Integer> perm = new ArrayList<>();
                perm.add(i);
                perm.add(j);
                perm.add(k);
                orig.add(perm);
            }
        }
    }
}

// Ask the user for two permutations as tuples
System.out.print("Enter the first permutation: ");
String p = sc.next();
System.out.print("Enter the second permutation: ");
String q = sc.next();

// Find the indices of p and q in the orig list
int pn = orig.indexOf(p);
int qn = orig.indexOf(q);

// Print the absolute difference between the indices of p and q
System.out.println(Math.abs(pn - qn));

