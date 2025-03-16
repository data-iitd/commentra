import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Main:
    # Represents a node in the trie
    class Node:
        # Map to store child nodes
        child = {}
        # Suffix link for the node
        suffixLink = None
        # Output link for the node
        outputLink = None
        # Index to indicate which pattern the node represents
        patternInd = -1

        # Constructor to initialize the node
        def __init__(self):
            self.suffixLink = None
            self.outputLink = None
            self.patternInd = -1

    # Trie class to represent the trie data structure
    class Trie:
        # Root of the trie
        root = Node()
        # Array to store the patterns
        patterns = []

        # Constructor to initialize the trie with patterns
        def __init__(self, patterns):
            self.patterns = patterns
            # Build the trie
            self.buildTrie()
            # Build suffix and output links
            self.buildSuffixAndOutputLinks()

        # Method to build the trie by adding each pattern
        def buildTrie(self):
            for i in range(len(self.patterns)):
                curr = self.root
                for c in self.patterns[i]:
                    curr = curr.child.setdefault(c, Node())
                curr.patternInd = i

        # Method to build suffix and output links for each node
        def buildSuffixAndOutputLinks(self):
            self.root.suffixLink = self.root
            queue = Queue()
            for child in self.root.child.values():
                child.suffixLink = self.root
                queue.add(child)
            while not queue.isEmpty():
                current = queue.poll()
                for entry in current.child.items():
                    ch = entry[0]
                    child = entry[1]
                    suffix = current.suffixLink
                    while suffix!= self.root and not suffix.child.has_key(ch):
                        suffix = suffix.suffixLink
                    if suffix.child.has_key(ch):
                        suffix = suffix.child[ch]
                    child.suffixLink = suffix
                    if suffix.patternInd!= -1:
                        child.outputLink = suffix
                    else:
                        child.outputLink = suffix.outputLink
                    queue.add(child)

        # Method to search for all occurrences of patterns in the given text
        def search(self, text):
            matches = {}
            for pattern in self.patterns:
                matches[pattern] = []
            current = self.root
            for i in range(len(text)):
                ch = text[i]
                while current!= self.root and not current.child.has_key(ch):
                    current = current.suffixLink
                if current.child.has_key(ch):
                    current = current.child[ch]
                temp = current
                while temp!= None:
                    if temp.patternInd!= -1:
                        matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                    temp = temp.outputLink
            return matches

    # Main method to read input, construct the trie, and print matches
    def main(self):
        scanner = Scanner(System.in)
        text = scanner.nextLine()
        patternCount = scanner.nextInt()
        scanner.nextLine() 
        patterns = []
        for i in range(patternCount):
            patterns.append(scanner.nextLine())
        trie = Trie(patterns)
        result = trie.search(text)
        print("Pattern matches:")
        for pattern in patterns:
            print(pattern + ": " + result.get(pattern))
        scanner.close()

# 