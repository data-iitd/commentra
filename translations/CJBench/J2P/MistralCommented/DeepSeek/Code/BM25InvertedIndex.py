import re
from collections import defaultdict, Counter
from math import log

class Movie:
    def __init__(self, doc_id, name, imdb_rating, release_year, content):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    def get_words(self):
        return re.findall(r'\w+', (self.name + " " + self.content).lower())

class SearchResult:
    def __init__(self, doc_id, relevance_score):
        self.doc_id = doc_id
        self.relevance_score = relevance_score

    def get_doc_id(self):
        return self.doc_id

    def get_relevance_score(self):
        return self.relevance_score

class Main:
    def __init__(self):
        self.index = defaultdict(dict)
        self.movies = {}
        self.total_documents = 0
        self.avg_document_length = 0.0
        self.K = 1.5
        self.B = 0.75

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
            if doc_id not in self.index[term]:
                self.index[term][doc_id] = 0
            self.index[term][doc_id] += 1

    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []
        term_docs = self.index[term]
        results = []
        idf = self.compute_idf(len(term_docs))
        for doc_id, term_frequency in term_docs.items():
            movie = self.movies[doc_id]
            doc_length = len(movie.get_words())
            score = self.compute_bm25_score(term_frequency, doc_length, idf)
            results.append(SearchResult(doc_id, score))
        results.sort(key=lambda x: x.get_relevance_score(), reverse=True)
        return results

    def compute_idf(self, doc_frequency):
        return log((self.total_documents - doc_frequency + 0.5) / (doc_frequency + 0.5) + 1)

    def compute_bm25_score(self, term_frequency, doc_length, idf):
        numerator = term_frequency * (self.K + 1)
        denominator = term_frequency + self.K * (1 - self.B + self.B * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    movie_count = int(data[0])
    index = Main()

    for i in range(1, movie_count + 1):
        doc_id = int(data[i])
        name = data[i + movie_count]
        imdb_rating = float(data[i + 2 * movie_count])
        release_year = int(data[i + 3 * movie_count])
        content = data[i + 4 * movie_count]
        index.add_movie(doc_id, name, imdb_rating, release_year, content)

    query_count = int(data[movie_count + 1])
    for i in range(movie_count + 2, movie_count + query_count + 2):
        query = data[i]
        results = index.search(query)
        print(f"Search results for: {query}")
        for result in results:
            print(f"Doc ID: {result.get_doc_id()}, Score: {result.get_relevance_score()}")
