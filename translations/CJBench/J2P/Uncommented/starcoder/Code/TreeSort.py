import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
class BST(object):
    def __init__(self):
        self.root = None
    def add(self, data):
        self.root = self.addRecursive(self.root, data)
    def addRecursive(self, node, data):
        if node == None:
            return Node(data)
        if data < node.data:
            node.left = self.addRecursive(node.left, data)
        else:
            node.right = self.addRecursive(node.right, data)
        return node
    def inOrderTraversal(self):
        result = []
        self.inOrderTraversal(self.root, result)
        return result
    def inOrderTraversal(self, node, result):
        if node!= None:
            self.inOrderTraversal(node.left, result)
            result.append(node.data)
            self.inOrderTraversal(node.right, result)
class Main(object):
    def sort(self, unsortedArray):
        tree = BST()
        for element in unsortedArray:
            tree.add(element)
        sortedList = tree.inOrderTraversal()
        return sortedList
    def sort(self, unsortedList):
        tree = BST()
        for element in unsortedList:
            tree.add(element)
        return tree.inOrderTraversal()
    def main(self):
        scanner = Scanner(System.in)
        treeSort = Main()
        type = scanner.nextInt()
        scanner.nextLine()
        n = scanner.nextInt()
        scanner.nextLine()
        if type == 1:
            array = [0] * n
            for i in range(n):
                array[i] = scanner.nextInt()
            array = treeSort.sort(array)
            System.out.println("Sorted Array:")
            for num in array:
                System.out.print(num + " ")
        elif type == 2:
            array = [0] * n
            for i in range(n):
                array[i] = scanner.nextLine()
            array = treeSort.sort(array)
            System.out.println("Sorted Array:")
            for str in array:
                System.out.print(str + " ")
        else:
            System.out.println("Invalid type entered.")
        scanner.close()
if __name__ == "__main__":
    Main().main()
