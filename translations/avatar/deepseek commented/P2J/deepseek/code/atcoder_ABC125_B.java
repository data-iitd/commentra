import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Taking an integer input N, which represents the number of elements.
        String[] V = scanner.next().split(" ");  // Taking the first line of space-separated integers and storing them in array V.
        int[] V_int = new int[N];  // Creating an integer array V_int to store the converted elements.
        for (int i = 0; i < N; i++) {
            V_int[i] = Integer.parseInt(V[i]);  // Converting each element in V to an integer and storing it in V_int.
        }
        String[] C = scanner.next().split(" ");  // Taking the second line of space-separated integers and storing them in array C.
        int[] C_int = new int[N];  // Creating an integer array C_int to store the converted elements.
        for (int i = 0; i < N; i++) {
            C_int[i] = Integer.parseInt(C[i]);  // Converting each element in C to an integer and storing it in C_int.
        }

        // Initializing an array list named list with a single element 0 and an integer ans set to 0.
        int[] list = new int[1];
        list[0] = 0;
        int ans = 0;
        int X = 0;
        int Y = 0;

        // Entering a for loop that iterates N times.
        for (int i = 0; i < N; i++) {
            // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
            if (V_int[i] - C_int[i] > 0) {
                X = V_int[i];  // Assigning the i-th element of V to X.
                Y = C_int[i];  // Assigning the i-th element of C to Y.
                int[] newList = new int[list.length + 1];  // Creating a new array to hold the updated list.
                System.arraycopy(list, 0, newList, 0, list.length);  // Copying the old list to the new list.
                newList[newList.length - 1] = X - Y;  // Appending the difference X - Y to the new list.
                list = newList;  // Updating the list to the new list.
            }
        }

        // Calculating the sum of the list.
        for (int num : list) {
            ans += num;  // Adding each element in the list to ans.
        }

        // Printing the sum of the list.
        System.out.println(ans);
    }
}
