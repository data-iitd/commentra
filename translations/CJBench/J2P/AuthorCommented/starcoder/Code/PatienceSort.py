import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

"""

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

class Main:

    def main(self):
        scanner = java.util.Scanner(System.in);

        # Input: size of the array
        n = scanner.nextInt();
        array = new Integer[n];

        # Input: array elements
        for i in range(n):
            array[i] = scanner.nextInt();

        # Sort the array using Patience Sort
        self.patienceSort(array);

        # Output: sorted array
        for num in array:
            System.out.print(num + " ");

        scanner.close();

    def patienceSort(self, array):
        if array.length == 0:
            return array;

        final List<List<T>> piles = self.formPiles(array);
        final PriorityQueue<PileNode<T>> pq = self.mergePiles(piles);
        self.extractPiles(array, pq);

        return array;

    def formPiles(self, array):
        final List<List<T>> piles = new ArrayList<>();
        final List<T> lastElements = new ArrayList<>();

        for x in array:
            int pos = Collections.binarySearch(lastElements, x);
            if pos < 0:
                pos = -pos - 1;

            if pos < piles.size():
                piles.get(pos).add(x);
                lastElements.set(pos, x);
            else:
                List<T> newPile = new ArrayList<>();
                newPile.add(x);
                piles.add(newPile);
                lastElements.add(x);
        return piles;

    def mergePiles(self, piles):
        PriorityQueue<PileNode<T>> pq = new PriorityQueue<>();
        for pile in piles:
            pq.add(new PileNode<>(pile.remove(pile.size() - 1), pile));
        return pq;

    def extractPiles(self, array, pq):
        int index = 0;
        while (!pq.isEmpty()):
            PileNode<T> node = pq.poll();
            array[index++] = node.value;
            if (!node.pile.isEmpty()):
                pq.add(new PileNode<>(node.pile.remove(node.pile.size() - 1), node.pile));

class PileNode<T extends Comparable<T>> implements Comparable<PileNode<T>>:
    final T value;
    final List<T> pile;

    public PileNode(T value, List<T> pile):
        self.value = value;
        self.pile = pile;

    @Override
    public int compareTo(PileNode<T> other):
        return self.value.compareTo(other.value);

