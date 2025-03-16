
import re

class Main:
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.totalDocuments = 0
        self.avgDocumentLength = 0.0
    
    def addMovie(self, docId, name, imdbRating, releaseYear, content):
        movie = Movie(docId, name, imdbRating, releaseYear, content)
        self.movies[docId] = movie
        self.totalDocuments += 1
        docLength = len(movie.getWords())
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments
        for term in movie.getWords():
            self.index.setdefault(term, {})
            docList = self.index[term]
            docList[docId] = docList.get(docId, 0) + 1
    
    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []
        termDocs = self.index[term]
        results = []
        idf = self.computeIDF(len(termDocs))
        for docId, termFrequency in termDocs.items():
            movie = self.movies[docId]
            docLength = len(movie.getWords())
            score = self.computeBM25Score(termFrequency, docLength, idf)
            results.append(SearchResult(docId, score))
        results.sort(key=lambda r: r.relevanceScore, reverse=True)
        return results
    
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)
    
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (1.5 + 1)
        denominator = termFrequency + 1.5 * (1 - 0.75 + 0.75 * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

class Movie:
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content
    
    def getWords(self):
        return (self.name + " " + self.content).lower().split(r"\W+")

class SearchResult:
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore
    
    def getDocId(self):
        return self.docId
    
    def getRelevanceScore(self):
        return self.relevanceScore

if __name__ == "__main__":
    scanner = Scanner(sys.stdin)
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

