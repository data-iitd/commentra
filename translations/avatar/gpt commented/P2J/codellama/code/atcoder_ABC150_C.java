// Read an integer input n, which defines the range of numbers to permute
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Import the itertools module to use its permutations function
import java.util.ArrayList;
import java.util.List;

// Generate all possible permutations of the numbers from 1 to n
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

// Read the first permutation input as a tuple of integers
List<Integer> p = new ArrayList<>();
for (int i = 0; i < n; i++) {
    p.add(sc.nextInt());
}

// Read the second permutation input as a tuple of integers
List<Integer> q = new ArrayList<>();
for (int i = 0; i < n; i++) {
    q.add(sc.nextInt());
}

// Find the index of the first permutation in the list of all permutations
int pn = orig.indexOf(p);

// Find the index of the second permutation in the list of all permutations
int qn = orig.indexOf(q);

// Calculate and print the absolute difference between the two indices
System.out.println(Math.abs(pn - qn));

