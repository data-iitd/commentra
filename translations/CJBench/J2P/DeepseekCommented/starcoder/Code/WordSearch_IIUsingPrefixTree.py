import java.util.*;
import java.util.HashMap;
class Main:
    class Trie:
        def __init__(self):
            self.value = None
            self.isKey = False
            self.children = {}
        
        # Checks if the current node has a child with the given character.
        def hasChild(self, ch):
            return ch in self.children
        
        # Adds a child node with the given character.
        def addChild(self, ch):
            self.children[ch] = Trie()
        
        # Returns the child node with the given character.
        def getChild(self, ch):
            return self.children[ch]
        
        # Inserts a word into the Trie.
        def insert(self, word):
            node = self
            for ch in word:
                if not node.hasChild(ch):
                    node.addChild(ch)
                node = node.getChild(ch)
            node.value = word
            node.isKey = True
    
    # This method takes a 2D character array (board) and an array of strings (words).
    # It finds all the words from the board that are in the given list of words.
    def findWords(self, board, words):
        uniqueWords = set(words)
        trie = Trie()
        for word in uniqueWords:
            trie.insert(word)
        result = set()
        m = len(board)
        n = len(board[0])
        
        # Iterate over each cell in the board and start a traversal from that cell.
        for i in range(m):
            for j in range(n):
                visited = [[False] * n for _ in range(m)]
                visited[i][j] = True
                self.traverse(board, i, j, trie, visited, result)
        return list(result)
    
    # For each cell, mark it as visited and start a recursive traversal from that cell.
    def traverse(self, board, i, j, trie, visited, result):
        ch = board[i][j]
        if trie.hasChild(ch):
            child = trie.getChild(ch)
            if child.isKey:
                result.add(child.value)
            self.checkNewPos(board, i - 1, j, child, visited, result)
            self.checkNewPos(board, i, j - 1, child, visited, result)
            self.checkNewPos(board, i + 1, j, child, visited, result)
            self.checkNewPos(board, i, j + 1, child, visited, result)
    
    # This helper method ensures that the traversal does not go out of bounds and that the cell has not been visited.
    def checkNewPos(self, board, i, j, trie, visited, result):
        m = len(board)
        n = len(board[0])
        if i < 0 or j < 0 or i >= m or j >= n:
            return
        if not visited[i][j]:
            visited[i][j] = True
            self.traverse(board, i, j, trie, visited, result)
            visited[i][j] = False

# This is the entry point of the program.
if __name__ == "__main__":
    scanner = Scanner(System.in)
    rows = scanner.nextInt()
    cols = scanner.nextInt()
    scanner.nextLine() 
    board = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        board[i] = scanner.nextLine().toCharArray()
    wordCount = scanner.nextInt()
    scanner.nextLine() 
    words = [0] * wordCount
    for i in range(wordCount):
        words[i] = scanner.nextLine()
    wordSearch = Main()
    result = wordSearch.findWords(board, words)
    for word in result:
        print(word)
    scanner.close()

