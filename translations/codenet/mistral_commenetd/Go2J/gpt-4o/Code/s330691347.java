import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Define a class Data to represent a single data point
class Data implements Comparable<Data> {
    String x;

    Data(String x) {
        this.x = x;
    }

    @Override
    public int compareTo(Data other) {
        return this.x.compareTo(other.x);
    }
}

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for reading input from stdin
        Scanner sc = new Scanner(System.in);

        // Read number of data points N from the input
        int N = sc.nextInt();

        // Read number of queries L from the input
        int L = sc.nextInt();

        // Initialize a list of Data type named s
        List<Data> s = new ArrayList<>(N);

        // Read data points X from the input and store them in the list s
        for (int i = 0; i < N; i++) {
            String x = sc.next();
            s.add(new Data(x));
        }

        // Print the number of data points N, number of queries L, and the list s
        // out(N, L, s); // Uncomment if you want to print this information

        // Sort the list s in ascending order based on x field
        Collections.sort(s);

        // Initialize an empty string ans to store the concatenated x values
        StringBuilder ans = new StringBuilder();

        // Iterate through the list s and concatenate x values to the string ans
        for (Data data : s) {
            ans.append(data.x);
        }

        // Print the concatenated string ans to the console
        System.out.println(ans.toString());

        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
