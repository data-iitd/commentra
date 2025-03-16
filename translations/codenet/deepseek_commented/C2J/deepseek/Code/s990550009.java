public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int[] a = new int[100000];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read the elements into the array
        }
        
        int cnt = 1;
        boolean isup = a[0] < a[1];
        boolean issame = a[0] == a[1];
        
        for (int i = 1; i < n - 1; i++) {
            if (issame) {
                if (a[i] != a[i + 1]) {
                    issame = false;
                    isup = a[i] < a[i + 1];
                }
            } else {
                if (isup && a[i] <= a[i + 1]) {
                    // Continue if the current trend is increasing and the next element is greater or equal
                } else if (!isup && a[i] >= a[i + 1]) {
                    // Continue if the current trend is decreasing and the next element is less or equal
                } else {
                    if (i + 2 < n) {
                        if (a[i + 1] < a[i + 2])
                            isup = true; // Update the trend if the next element indicates a change
                        else if (a[i + 1] > a[i + 2])
                            isup = false;
                        else
                            issame = true;
                        cnt++; // Increment the count for a new segment
                    } else {
                        cnt++; // Increment the count for the last segment
                        break;
                    }
                }
            }
        }
        
        System.out.println(cnt); // Print the count of segments
    }
}
