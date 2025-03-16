import re
from collections import defaultdict, Counter
from typing import List, Dict, Tuple

class Movie:
    def __init__(self, doc_id: int, name: str, imdb_rating: float, release_year: int, content: str):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    def get_words(self) -> List[str]:
        return re.findall(r'\b\w+\b', self.name + " " + self.content, re.IGNORECASE)

class SearchResult:
    def __init__(self, doc_id: int, relevance_score: float):
        self.doc_id = doc_id
        self.relevance_score = relevance_score

    def get_doc_id(self) -> int:
        return self.doc_id

    def get_relevance_score(self) -> float:
        return self.relevance_score

class Main:
    def __init__(self):
        self.index: Dict[str, Dict[int, int]] = defaultdict(dict)
        self.movies: Dict[int, Movie] = {}
        self.total_documents = 0
        self.avg_document_length = 0.0
        self.K = 1.5
        self.B = 0.75

    def add_movie(self, doc_id: int, name: str, imdb_rating: float, release_year: int, content: str):
        movie = Movie(doc_id, name, imdb_rating, release_year, content)
        self.movies[doc_id] = movie
        self.total_documents += 1
        terms = movie.get_words()
        doc_length = len(terms)
        self.avg_document_length = ((self.avg_document_length * (self.total_documents - 1)) + doc_length) / self.total_documents
        for term in terms:
            if term not in self.index:
                self.index[term] = {}
            self.index[term][doc_id] = self.index[term].get(doc_id, 0) + 1

    def search(self, term: str) -> List[SearchResult]:
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
        results.sort(key=lambda r: r.get_relevance_score(), reverse=True)
        return results

    def compute_bm25_score(self, term_frequency: int, doc_length: float, idf: float) -> float:
        numerator = term_frequency * (self.K + 1)
        denominator = term_frequency + self.K * (1 - self.B + self.B * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

    def compute_idf(self, doc_frequency: int) -> float:
        return math.log((self.total_documents - doc_frequency + 0.5) / (doc_frequency + 0.5) + 1)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    movie_count = int(data[0])
    index = Main()
    movie_index = 1
    for _ in range(movie_count):
        doc_id = int(data[movie_index])
        name = data[movie_index + 1]
        imdb_rating = float(data[movie_index + 2])
        release_year = int(data[movie_index + 3])
        content = data[movie_index + 4]
        index.add_movie(doc_id, name, imdb_rating, release_year, content)
        movie_index += 5

    query_count = int(data[movie_index])
    for _ in range(query_count):
        query = data[movie_index + 1]
        results = index.search(query)
        print(f"Search results for: {query}")
        for result in results:
            print(f"Doc ID: {result.get_doc_id()}, Score: {result.get_relevance_score()}")
        movie_index += 2
