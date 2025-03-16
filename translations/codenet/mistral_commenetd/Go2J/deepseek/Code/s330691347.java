import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of data points N from the input
        int N = scanner.nextInt();

        // Read number of queries L from the input
        int L = scanner.nextInt();

        // Initialize a list of Data type named s
        List<Data> s = new ArrayList<>();

        // Read data points X from the input and store them in the list s
        for (int i = 0; i < N; i++) {
            s.add(new Data(scanner.next()));
        }

        // Sort the list s in ascending order based on X field
        Collections.sort(s);

        // Initialize an empty string ans to store the concatenated X values
        StringBuilder ans = new StringBuilder();

        // Iterate through the list s and concatenate X values to the string ans
        for (Data data : s) {
            ans.append(data.getX());
        }

        // Print the concatenated string ans to the console
        System.out.println(ans.toString());
    }

    // Define a class Data to represent a single data point
    static class Data implements Comparable<Data> {
        private String X;

        // Constructor for Data class
        public Data(String X) {
            this.X = X;
        }

        // Getter method for X
        public String getX() {
            return X;
        }

        // Implement compareTo method to sort the Data objects based on X field
        @Override
        public int compareTo(Data other) {
            return this.X.compareTo(other.X);
        }
    }
}
