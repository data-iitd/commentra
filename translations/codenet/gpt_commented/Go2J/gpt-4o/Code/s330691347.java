import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Data implements Comparable<Data> {
    String x;

    Data(String x) {
        this.x = x;
    }

    @Override
    public int compareTo(Data other) {
        return this.x.compareTo(other.x); // Sort based on the string field x
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt(); // Read the number of data entries
        int L = sc.nextInt(); // Read an additional integer (not used further in the code)
        
        List<Data> dataList = new ArrayList<>(N); // Create a list of Data with initial capacity N

        // Read N strings into the list
        for (int i = 0; i < N; i++) {
            String str = sc.next(); // Read the next string
            dataList.add(new Data(str)); // Populate each Data entry with a string
        }

        // Sort the list of Data entries
        Collections.sort(dataList);

        // Concatenate all strings in the sorted list into a single result
        StringBuilder ans = new StringBuilder();
        for (Data data : dataList) {
            ans.append(data.x); // Append each string to ans
        }
        
        System.out.println(ans.toString()); // Print the concatenated result
    }
}

// <END-OF-CODE>
