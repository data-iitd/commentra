import java.util.Scanner;
import java.util.Arrays;
public class FlashSort {
    private double classificationRatio = 0.45;
    public FlashSort() {}
    public FlashSort(double classificationRatio) {
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }
    public void setClassificationRatio(double classificationRatio) {
        if (classificationRatio <= 0 || classificationRatio >= 1) {
            throw new IllegalArgumentException("Classification ratio must be between 0 and 1 (exclusive).");
        }
        this.classificationRatio = classificationRatio;
    }
    public <T extends Comparable<T>> T[] sort(T[] array) {
        flashSort(array);
        return array;
    }
    private <T extends Comparable<? super T>> void flashSort(T[] arr) {
        if (arr.length == 0) {
            return;
        }
        T min = findMin(arr);
        int maxIndex = findMaxIndex(arr);
        if (arr[maxIndex].compareTo(min) == 0) {
            return; 
        }
        int m = (int) (classificationRatio * arr.length);
        int[] classificationArray = new int[m];
        double c1 = (double) (m - 1) / arr[maxIndex].compareTo(min);
        classify(arr, classificationArray, c1, min);
        transform(classificationArray);
        permute(arr, classificationArray, c1, min, arr.length, m);
        insertionSort(arr);
    }
    private <T extends Comparable<? super T>> T findMin(T[] arr) {
        T min = arr[0];
        for (T t : arr) {
            if (t.compareTo(min) < 0) {
                min = t;
            }
        }
        return min;
    }
    private <T extends Comparable<? super T>> int findMaxIndex(T[] arr) {
        int maxIndex = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i].compareTo(arr[maxIndex]) > 0) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    private <T extends Comparable<? super T>> void classify(T[] arr, int[] classificationArray, double c1, T min) {
        for (T t : arr) {
            int k = (int) (c1 * t.compareTo(min));
            classificationArray[k]++;
        }
    }
    private void transform(int[] classificationArray) {
        for (int i = 1; i < classificationArray.length; i++) {
            classificationArray[i] += classificationArray[i - 1];
        }
    }
    private <T extends Comparable<? super T>> void permute(T[] arr, int[] classificationArray, double c1, T min, int n, int m) {
        int move = 0;
        int j = 0;
        int k = m - 1;
        T flash;
        while (move < n - 1) {
            while (j > classificationArray[k] - 1) {
                j++;
                k = (int) (c1 * arr[j].compareTo(min));
            }
            flash = arr[j];
            while (j != classificationArray[k]) {
                k = (int) (c1 * flash.compareTo(min));
                T temp = arr[classificationArray[k] - 1];
                arr[classificationArray[k] - 1] = flash;
                flash = temp;
                classificationArray[k]--;
                move++;
            }
        }
    }
    private <T extends Comparable<? super T>> void insertionSort(T[] arr) {
        for (int i = 1; i < arr.length; i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].compareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        FlashSort flashSort = new FlashSort();
        flashSort.sort(array);
        for (int num : array) {
            System.out.print(num + " ");
        }
        scanner.close();
    }
}
