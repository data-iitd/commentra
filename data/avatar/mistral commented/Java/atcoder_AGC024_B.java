
import java.util.ArrayList ;
import java.util.HashMap ;
import java.util.List ;
import java.util.Map ;
import java.util.Scanner ;

public class Main {

  // Initialize scanner to read input from the standard input
  Scanner scan = new Scanner(System.in);

  public static void main(String[] args) {

    // Read the number of elements in the array P from the standard input
    int N = scan.nextInt();

    // Initialize an integer array P of size N
    int[] P = new int[N];

    // Read each element of P from the standard input and store it in the corresponding index of the array
    for (int i = 0; i < N; ++i)
      P[i] = scan.nextInt() - 1;

    // Create an empty HashMap to store the indices of the array P corresponding to each unique element
    Map<Integer, Integer> map = new HashMap<>();

    // Iterate through each element of the array P and add its index to the HashMap
    for (int i = 0; i < N; ++i)
      map.put(P[i], i);

    // Create an empty ArrayList to store the indices of the non-decreasing subsequences
    List<Integer> nglist = new ArrayList<>();

    // Iterate through each index i of the array P, where i < N - 1
    for (int i = 0; i < N - 1; ++i) {
      // If the index i corresponds to a smaller element than the next index, add its index to the ArrayList
      if (map.get(i) > map.get(i + 1))
        nglist.add(i);
    }

    // If there are no non-decreasing subsequences, print 0 and exit the program
    if (nglist.isEmpty()) {
      System.out.println(0);
      return;
    }

    // Calculate the answer by finding the minimum length of a non-decreasing subsequence
    int ans = Math.min(N - nglist.get(0) - 1, nglist.get(nglist.size() - 1) + 1);

    // Iterate through each pair of consecutive indices in the ArrayList nglist and update the answer if necessary
    for (int i = 0; i < nglist.size() - 1; ++i) {
      ans = Math.min(nglist.get(i) + 1 + N - nglist.get(i + 1) - 1, ans);
    }

    // Print the answer
    System.out.println(ans);
  }
}