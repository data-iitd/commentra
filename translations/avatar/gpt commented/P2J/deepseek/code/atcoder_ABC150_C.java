import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input n, which defines the range of numbers to permute
        int n = scanner.nextInt();
        
        // Generate all possible permutations of the numbers from 1 to n
        List<String> orig = new ArrayList<>();
        permute(1, n, new ArrayList<>(), orig);
        
        // Read the first permutation input as a list of integers
        List<Integer> pList = new ArrayList<>();
        String[] pInput = scanner.next().split(",");
        for (String s : pInput) {
            pList.add(Integer.parseInt(s));
        }
        String p = pList.toString();
        
        // Read the second permutation input as a list of integers
        List<Integer> qList = new ArrayList<>();
        String[] qInput = scanner.next().split(",");
        for (String s : qInput) {
            qList.add(Integer.parseInt(s));
        }
        String q = qList.toString();
        
        // Find the index of the first permutation in the list of all permutations
        int pn = orig.indexOf(p);
        
        // Find the index of the second permutation in the list of all permutations
        int qn = orig.indexOf(q);
        
        // Calculate and print the absolute difference between the two indices
        System.out.println(Math.abs(pn - qn));
    }
    
    // Helper function to generate all permutations of numbers from start to end
    private static void permute(int start, int end, List<Integer> current, List<String> result) {
        if (start > end) {
            result.add(current.toString());
            return;
        }
        
        for (int i = start; i <= end; i++) {
            current.add(i);
            permute(i + 1, end, current, result);
            current.remove(current.size() - 1);
        }
    }
}
