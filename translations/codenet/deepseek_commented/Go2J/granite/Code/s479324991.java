
import java.util.*;
import java.io.*;

class s479324991 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();
        
        // Initialize an array to hold the float values
        float[] arr = new float[n];
        
        // Read each integer and convert it to float, then store in the array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextFloat();
        }
        
        // Sort the array of float values
        Arrays.sort(arr);
        
        // Initialize a variable to keep track of the running average
        float prev = arr[0];
        
        // Iterate through the sorted array to calculate the average
        for (int i = 1; i < arr.length; i++) {
            prev = (prev + arr[i]) / 2;
        }

        // Print the final average
        System.out.println(prev);
    }
}

class Scanner {
    BufferedReader r;
    StreamTokenizer st;

    public Scanner(InputStream in) {
        r = new BufferedReader(new InputStreamReader(in));
        st = new StreamTokenizer(r);
    }

    public String next() {
        nextToken();
        return st.sval;
    }

    public int nextInt() {
        nextToken();
        return (int)st.nval;
    }

    public float nextFloat() {
        nextToken();
        return (float)st.nval;
    }

    int nextToken() {
        int token = st.TT_EOF;
        try {
            token = st.nextToken();
        } catch (IOException e) {
        }
        return token;
    }
}

