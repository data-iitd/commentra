
import collections
import sys

# Define a private inner class Node for the Trie data structure
class Node:
    # Initialize an empty dictionary for child nodes
    def __init__(self):
        self.child = collections.defaultdict(Node)
        
        # Initialize a null suffixLink and outputLink
        self.suffixLink = None
        self.outputLink = None
        
        # Initialize a -1 for pattern index
        self.patternInd = -1

# Define a public class Trie {
    # Initialize the root Node
    def __init__(self, patterns):
        self.root = Node()
        
        # Initialize the patterns array
        self.patterns = patterns
        
        # Build the Trie data structure
        self.buildTrie()
        
        # Build suffix and output links
        self.buildSuffixAndOutputLinks()
    
    # Method to build the Trie data structure
    def buildTrie(self):
        for i in range(len(self.patterns)):
            curr = self.root # Initialize current Node as root
            for c in self.patterns[i]: # Iterate through each character in the pattern
                curr = curr.child[c] # If child Node doesn't exist, create a new one
            curr.patternInd = i # Set the pattern index when reaching the end of the pattern
    
    # Method to build suffix and output links
    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root # Initialize the suffixLink of the root Node as itself
        queue = collections.deque() # Initialize a Queue for BFS traversal
        for child in self.root.child.values(): # Add all children to the Queue
            child.suffixLink = self.root # Initialize the suffixLink of each child as the root
            queue.append(child)
        while queue: # Perform BFS traversal
            current = queue.popleft() # Dequeue a Node
            for ch, child in current.child.items(): # Iterate through each child
                suffix = current.suffixLink # Initialize suffix as the suffixLink of the current Node
                while suffix!= self.root and ch not in suffix.child: # Find the common suffixNode
                    suffix = suffix.suffixLink
                if ch in suffix.child: # If a suffixNode is found
                    suffix = suffix.child[ch] # Update suffix to the found suffixNode
                child.suffixLink = suffix # Set the suffixLink of the current child Node
                if suffix.patternInd!= -1: # If the suffixNode has a pattern index
                    child.outputLink = suffix # Set the outputLink of the current child Node to the suffixNode
                else: # Otherwise, set the outputLink to the outputLink of the suffixNode
                    child.outputLink = suffix.outputLink
                queue.append(child) # Add the current child Node to the Queue for further traversal
    
    # Method to search for pattern matches in a given text
    def search(self, text):
        matches = collections.defaultdict(list) # Initialize an empty dictionary to store the results
        for pattern in self.patterns: # Iterate through each pattern
            matches[pattern] = [] # Initialize an empty list to store the matches for the current pattern
        current = self.root # Initialize the current Node as the root
        for i in range(len(text)): # Iterate through each character in the text
            ch = text[i] # Get the current character
            while current!= self.root and ch not in current.child: # Find the common prefixNode
                current = current.suffixLink
            if ch in current.child: # If a child Node is found
                current = current.child[ch] # Update the current Node to the found child Node
            temp = current # Initialize a temporary Node to traverse the output links
            while temp!= None: # Traverse the output links
                if temp.patternInd!= -1: # If a pattern Node is found
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1) # Add the match index to the list for the current pattern
                temp = temp.outputLink # Update the temporary Node to the next outputNode
        return matches # Return the dictionary containing the pattern matches

# Main method to read input and call the Trie search method
if __name__ == "__main__":
    text = sys.stdin.readline().strip() # Read the text from input
    patternCount = int(sys.stdin.readline().strip()) # Read the number of patterns from input
    patterns = []
    for i in range(patternCount): # Read each pattern from input and store it in the list
        patterns.append(sys.stdin.readline().strip())
    trie = Trie(patterns) # Create a new Trie object with the given patterns
    result = trie.search(text) # Call the search method to find the pattern matches in the text
    print("Pattern matches:") # Print the header for the output
    for pattern in patterns: # Iterate through each pattern
        print(pattern + ": " + str(result[pattern])) # Print the pattern and its matches

# 