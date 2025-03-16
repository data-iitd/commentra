
import java.util.Objects;
import java.util.Scanner;
public class HashMapCuckooHashing {
    private int tableSize;
    private Integer[] buckets;
    private final Integer emptySlot;
    private int size;
    private int thresh;
    public HashMapCuckooHashing(int tableSize) {
        this.buckets = new Integer[tableSize];
        this.tableSize = tableSize;
        this.emptySlot = Integer.MIN_VALUE;
        this.size = 0;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }
    public int hashFunction1(int key) {
        int hash = key % tableSize;
        return (hash < 0) ? hash + tableSize : hash;
    }
    public int hashFunction2(int key) {
        int hash = key / tableSize;
        hash %= tableSize;
        return (hash < 0) ? hash + tableSize : hash;
    }
    public void insertKey2HashTable(int key) {
        Integer wrappedInt = key;
        Integer temp;
        int hash;
        int loopCounter = 0;
        if (isFull()) {
            System.out.println("Hash table is full, rehashing...");
            reHashTableIncreasesTableSize();
        }
        while (loopCounter <= thresh) {
            loopCounter++;
            hash = hashFunction1(key);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt;
                size++;
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
            hash = hashFunction2(temp);
            if (buckets[hash] == null || Objects.equals(buckets[hash], emptySlot)) {
                buckets[hash] = wrappedInt;
                size++;
                return;
            }
            temp = buckets[hash];
            buckets[hash] = wrappedInt;
            wrappedInt = temp;
        }
        System.out.println("Infinite loop detected, rehashing...");
        reHashTableIncreasesTableSize();
        insertKey2HashTable(key);
    }
    public void reHashTableIncreasesTableSize() {
        HashMapCuckooHashing newT = new HashMapCuckooHashing(tableSize * 2);
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] != null && !Objects.equals(buckets[i], emptySlot)) {
                newT.insertKey2HashTable(buckets[i]);
            }
        }
        this.buckets = newT.buckets;
        this.tableSize = newT.tableSize;
        this.thresh = (int) (Math.log(tableSize) / Math.log(2)) + 2;
    }
    public void deleteKeyFromHashTable(int key) {
        int hash = hashFunction1(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            return;
        }
        hash = hashFunction2(key);
        if (Objects.equals(buckets[hash], key)) {
            buckets[hash] = emptySlot;
            size--;
            return;
        }
        System.out.println("Key " + key + " not found.");
    }
    public void displayHashtable() {
        for (int i = 0; i < tableSize; i++) {
            if (buckets[i] == null || Objects.equals(buckets[i], emptySlot)) {
                System.out.println("Bucket " + i + ": Empty");
            } else {
                System.out.println("Bucket " + i + ": " + buckets[i]);
            }
        }
    }
    public boolean isFull() {
        for (Integer bucket : buckets) {
            if (bucket == null || Objects.equals(bucket, emptySlot)) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int initialSize = scanner.nextInt();
        HashMapCuckooHashing hashMap = new HashMapCuckooHashing(initialSize);
        int operations = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < operations; i++) {
            String[] command = scanner.nextLine().split(" ");
            switch (command[0].toUpperCase()) {
                case "INSERT":
                    hashMap.insertKey2HashTable(Integer.parseInt(command[1]));
                    break;
                case "DELETE":
                    hashMap.deleteKeyFromHashTable(Integer.parseInt(command[1]));
                    break;
                case "DISPLAY":
                    hashMap.displayHashtable();
                    break;
                default:
                    System.out.println("Invalid command");
            }
        }
        scanner.close();
    }
}
