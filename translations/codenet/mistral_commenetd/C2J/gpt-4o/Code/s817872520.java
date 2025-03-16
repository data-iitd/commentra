import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final int INF = 0x5fffffff;
    static int[] a = new int[100002]; // array to store input numbers
    static int[] b = new int[100002]; // array to store the minimum number of steps to reach from the start or end

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;

        // read the number of elements in the array 'a'
        line = reader.readLine();
        int w = Integer.parseInt(line.trim());

        // read the elements of array 'a'
        line = reader.readLine();
        String[] inputs = line.trim().split(" ");
        int ans = 0, f = 0, close = 0;

        for (int i = 0; i < w; i++) {
            int k = Integer.parseInt(inputs[i]);
            // check if the current element is zero
            if (k == 0) {
                f |= 1; // set flag 'f' if there is an element with zero value
                continue;
            }

            // if the current element is negative, update the 'close' variable
            // and set flag 'f' to -2 if all elements are negative
            if (k < 0) {
                if (f < 0 || close - (i - f) > -k) {
                    close = -k;
                    f = i;
                }
                if (f < 0) f = -2;
            }

            // update the 'ans' variable
            ans += k;
        }

        // check if the sum of all positive elements is zero or if flag 'f' is 1
        if (ans == 0 || (f & 1) == 0) {
            System.out.println("0"); // print 0 if the condition is true
            return;
        }

        // if all elements are not negative, calculate the minimum number of steps to reach from the start or end
        if ((f & 2) == 0) {
            System.out.println(ans); // print the answer
            return;
        }

        // initialize variables for the second loop
        for (close = 0, f = w; f >= 1; f--) {
            int i = f - 1; // adjust index for 0-based array
            if (a[i] == 0) {
                close = INF;
                f = -1;
                continue;
            }

            if (a[i] < 0) {
                // if the current element is negative, update the 'close' variable
                // and set flag 'f' to the index of the current element
                if (f < 0 || close - (f - i) > -a[i]) {
                    close = -a[i];
                    f = i;
                }
            } else {
                // if the current element is positive, update the 'b' array
                b[i] = INF;
                if (f >= 0) {
                    int k = close - (f - i); // calculate the minimum number of steps to reach from the start to the current index
                    if (k < 0) k = 0; // if the number is negative, set it to zero
                    b[i] = k; // update the 'b' array
                }
            }
        }

        // initialize variables for the third loop
        for (close = 0, f = w; f >= 1; f--) {
            int i = f - 1; // adjust index for 0-based array
            if (a[i] > 0) {
                // if the current element is positive, update the 'ans' variable
                if (b[i] > a[i]) ans += a[i];
                else ans += b[i];
            }
        }

        // print the answer
        System.out.println(ans);
    }
}
