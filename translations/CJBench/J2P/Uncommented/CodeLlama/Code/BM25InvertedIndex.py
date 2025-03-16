import math
class Movie:
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content
    def getWords(self):
        return (self.name + " " + self.content).lower().split()
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
        terms = movie.getWords()
        docLength = len(terms)
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments
        for term in terms:
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
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (Main.K + 1)
        denominator = termFrequency + Main.K * (1 - Main.B + Main.B * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)
class SearchResult:
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore
    def __str__(self):
        return "Doc ID: " + str(self.docId) + ", Score: " + str(self.relevanceScore)
if __name__ == "__main__":
    scanner = input()
    movieCount = int(scanner)
    index = Main()
    for i in range(movieCount):
        scanner = input()
        docId = int(scanner)
        scanner = input()
        name = scanner
        scanner = input()
        imdbRating = float(scanner)
        scanner = input()
        releaseYear = int(scanner)
        scanner = input()
        content = scanner
        index.addMovie(docId, name, imdbRating, releaseYear, content)
    scanner = input()
    queryCount = int(scanner)
    for i in range(queryCount):
        scanner = input()
        query = scanner
        results = index.search(query)
        print("Search results for: " + query)
        for result in results:
            print(result)
    