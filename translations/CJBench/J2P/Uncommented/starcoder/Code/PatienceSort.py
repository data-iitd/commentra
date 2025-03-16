import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
def patienceSort(array):
    if array.length == 0:
        return array;
    piles = formPiles(array);
    pq = mergePiles(piles);
    extractPiles(array, pq);
    return array;
def formPiles(array):
    piles = new ArrayList<>();
    lastElements = new ArrayList<>();
    for x in array:
        pos = Collections.binarySearch(lastElements, x);
        if pos < 0:
            pos = -pos - 1;
        if pos < piles.size():
            piles.get(pos).add(x);
            lastElements.set(pos, x);
        else:
            newPile = new ArrayList<>();
            newPile.add(x);
            piles.add(newPile);
            lastElements.add(x);
    return piles;
def mergePiles(piles):
    pq = new PriorityQueue<>();
    for pile in piles:
        pq.add(new PileNode(pile.remove(pile.size() - 1), pile));
    return pq;
def extractPiles(array, pq):
    index = 0;
    while not pq.isEmpty():
        node = pq.poll();
        array[index++] = node.value;
        if not node.pile.isEmpty():
            pq.add(new PileNode(node.pile.remove(node.pile.size() - 1), node.pile));
class PileNode(Comparable):
    def __init__(self, value, pile):
        self.value = value;
        self.pile = pile;
    def compareTo(self, other):
        return self.value.compareTo(other.value);
