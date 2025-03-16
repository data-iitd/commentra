import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Main:
    # A map to store terms and their occurrences in documents
    index = {}
    # A map to store document IDs and their corresponding Movie objects
    movies = {}
    # Counter for the total number of documents
    totalDocuments = 0
    # Variable to store the average document length
    avgDocumentLength = 0.0
    # Constants for BM25 formula
    K = 1.5
    B = 0.75

    # Constructor to initialize the index, movies, and counters
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.totalDocuments = 0
        self.avgDocumentLength = 0.0

    # Method to add a movie to the index
    def addMovie(self, docId, name, imdbRating, releaseYear, content):
        # Create a new Movie object and add it to the movies map
        movie = Movie(docId, name, imdbRating, releaseYear, content)
        self.movies[docId] = movie
        self.totalDocuments += 1

        # Update the average document length
        terms = movie.getWords()
        docLength = len(terms)
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments

        # Update the index with the terms in the movie's content
        for term in terms:
            self.index.setdefault(term, {})
            docList = self.index.get(term)
            docList[docId] = docList.get(docId, 0) + 1

    # Method to search for movies based on a term
    def search(self, term):
        # Convert the search term to lowercase
        term = term.lower()

        # Return an empty list if the term is not in the index
        if term not in self.index:
            return []

        # Get the documents containing the term and compute the IDF
        termDocs = self.index.get(term)
        results = []
        idf = self.computeIDF(len(termDocs))

        # Compute the BM25 score for each document and add to the results list
        for docId, termFrequency in termDocs.items():
            movie = self.movies.get(docId)
            docLength = len(movie.getWords())
            score = self.computeBM25Score(termFrequency, docLength, idf)
            results.append(SearchResult(docId, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.getRelevanceScore(), reverse=True)
        return results

    # Method to compute the BM25 score for a term in a document
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (self.K + 1)
        denominator = termFrequency + self.K * (1 - self.B + self.B * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

    # Method to compute the inverse document frequency (IDF)
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)

    # Main method to read input, add movies, and process search queries
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        movieCount = int(scanner.nextLine().strip())
        index = Main()
        for i in range(movieCount):
            docId = int(scanner.nextLine().strip())
            name = scanner.nextLine().strip()
            imdbRating = float(scanner.nextLine().strip())
            releaseYear = int(scanner.nextLine().strip())
            content = scanner.nextLine().strip()
            index.addMovie(docId, name, imdbRating, releaseYear, content)
        queryCount = int(scanner.nextLine().strip())
        for i in range(queryCount):
            query = scanner.nextLine().strip()
            results = index.search(query)
            print("Search results for: " + query)
            for result in results:
                print("Doc ID: " + str(result.getDocId()) + ", Score: " + str(result.getRelevanceScore()))
        scanner.close()

class Movie:
    docId = 0
    name = ""
    imdbRating = 0.0
    releaseYear = 0
    content = ""

    # Constructor for the Movie class
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content

    # Method to split the movie's name and content into words
    def getWords(self):
        return (self.name + " " + self.content).lower().split("\\W+")

class SearchResult:
    docId = 0
    relevanceScore = 0.0

    # Constructor for the SearchResult class
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore

    # Getter method for the document ID
    def getDocId(self):
        return self.docId

    # Getter method for the relevance score
    def getRelevanceScore(self):
        return self.relevanceScore

