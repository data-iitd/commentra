
import math

class Main:
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.total_documents = 0
        self.avg_document_length = 0.0

    def add_movie(self, doc_id, name, imdb_rating, release_year, content):
        movie = Movie(doc_id, name, imdb_rating, release_year, content)
        self.movies[doc_id] = movie
        self.total_documents += 1
        terms = movie.get_words()
        doc_length = len(terms)
        self.avg_document_length = ((self.avg_document_length * (self.total_documents - 1)) + doc_length) / self.total_documents
        for term in terms:
            if term not in self.index:
                self.index[term] = {}
            term_docs = self.index[term]
            if doc_id not in term_docs:
                term_docs[doc_id] = 0
            term_docs[doc_id] += 1

    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []
        term_docs = self.index[term]
        results = []
        idf = self.compute_idf(len(term_docs))
        for doc_id, term_freq in term_docs.items():
            movie = self.movies[doc_id]
            doc_length = len(movie.get_words())
            score = self.compute_bm25_score(term_freq, doc_length, idf)
            results.append(SearchResult(doc_id, score))
        results.sort(key=lambda x: x.get_relevance_score(), reverse=True)
        return results

    def compute_bm25_score(self, term_freq, doc_length, idf):
        numerator = term_freq * (1.5 + 1)
        denominator = term_freq + (1.5 - 0) * (1 - 0.75 + 0.75 * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

    def compute_idf(self, doc_freq):
        return math.log((self.total_documents - doc_freq + 0.5) / (doc_freq + 0.5) + 1)

class Movie:
    def __init__(self, doc_id, name, imdb_rating, release_year, content):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    def get_words(self):
        return (self.name + " " + self.content).lower().split("\\W+")

class SearchResult:
    def __init__(self, doc_id, relevance_score):
        self.doc_id = doc_id
        self.relevance_score = relevance_score

    def get_doc_id(self):
        return self.doc_id

    def get_relevance_score(self):
        return self.relevance_score

if __name__ == "__main__":
    scanner = open("input.txt", "r")
    movie_count = int(scanner.readline().strip())
    index = Main()
    for i in range(movie_count):
        doc_id = int(scanner.readline().strip())
        name = scanner.readline().strip()
        imdb_rating = float(scanner.readline().strip())
        release_year = int(scanner.readline().strip())
        content = scanner.readline().strip()
        index.add_movie(doc_id, name, imdb_rating, release_year, content)
    query_count = int(scanner.readline().strip())
    for i in range(query_count):
        query = scanner.readline().strip()
        results = index.search(query)
        print("Search results for:", query)
        for result in results:
            print("Doc ID:", result.get_doc_id(), "Score:", result.get_relevance_score())
    scanner.close()

