import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // A map to store terms and their occurrences in documents
    private Map<String, Map<Integer, Integer>> index;
    // A map to store document IDs and their corresponding Movie objects
    private Map<Integer, Movie> movies;
    // Counter for the total number of documents
    private int totalDocuments;
    // Variable to store the average document length
    private double avgDocumentLength;
    // Constants for BM25 formula
    private static final double K = 1.5;
    private static final double B = 0.75;

    // Constructor to initialize the index, movies, and counters
    public Main() {
        index = new HashMap<>();
        movies = new HashMap<>();
        totalDocuments = 0;
        avgDocumentLength = 0.0;
    }

    // Method to add a movie to the index
    public void addMovie(int docId, String name, double imdbRating, int releaseYear, String content) {
        // Create a new Movie object and add it to the movies map
        Movie movie = new Movie(docId, name, imdbRating, releaseYear, content);
        movies.put(docId, movie);
        totalDocuments++;

        // Update the average document length
        String[] terms = movie.getWords();
        int docLength = terms.length;
        avgDocumentLength = ((avgDocumentLength * (totalDocuments - 1)) + docLength) / totalDocuments;

        // Update the index with the terms in the movie's content
        for (String term : terms) {
            index.putIfAbsent(term, new HashMap<>());
            Map<Integer, Integer> docList = index.get(term);
            docList.put(docId, docList.getOrDefault(docId, 0) + 1);
        }
    }

    // Method to search for movies based on a term
    public List<SearchResult> search(String term) {
        // Convert the search term to lowercase
        term = term.toLowerCase();

        // Return an empty list if the term is not in the index
        if (!index.containsKey(term)) {
            return new ArrayList<>();
        }

        // Get the documents containing the term and compute the IDF
        Map<Integer, Integer> termDocs = index.get(term);
        List<SearchResult> results = new ArrayList<>();
        double idf = computeIDF(termDocs.size());

        // Compute the BM25 score for each document and add to the results list
        for (Map.Entry<Integer, Integer> entry : termDocs.entrySet()) {
            int docId = entry.getKey();
            int termFrequency = entry.getValue();
            Movie movie = movies.get(docId);
            double docLength = movie.getWords().length;
            double score = computeBM25Score(termFrequency, docLength, idf);
            results.add(new SearchResult(docId, score));
        }

        // Sort the results by relevance score in descending order
        results.sort((r1, r2) -> Double.compare(r2.getRelevanceScore(), r1.getRelevanceScore()));
        return results;
    }

    // Method to compute the BM25 score for a term in a document
    private double computeBM25Score(int termFrequency, double docLength, double idf) {
        double numerator = termFrequency * (K + 1);
        double denominator = termFrequency + K * (1 - B + B * (docLength / avgDocumentLength));
        return idf * (numerator / denominator);
    }

    // Method to compute the inverse document frequency (IDF)
    private double computeIDF(int docFrequency) {
        return Math.log((totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1);
    }

    // Main method to read input, add movies, and process search queries
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int movieCount = Integer.parseInt(scanner.nextLine().trim());
        Main index = new Main();
        for (int i = 0; i < movieCount; i++) {
            int docId = Integer.parseInt(scanner.nextLine().trim());
            String name = scanner.nextLine().trim();
            double imdbRating = Double.parseDouble(scanner.nextLine().trim());
            int releaseYear = Integer.parseInt(scanner.nextLine().trim());
            String content = scanner.nextLine().trim();
            index.addMovie(docId, name, imdbRating, releaseYear, content);
        }
        int queryCount = Integer.parseInt(scanner.nextLine().trim());
        for (int i = 0; i < queryCount; i++) {
            String query = scanner.nextLine().trim();
            List<SearchResult> results = index.search(query);
            System.out.println("Search results for: " + query);
            for (SearchResult result : results) {
                System.out.println("Doc ID: " + result.getDocId() + ", Score: " + result.getRelevanceScore());
            }
        }
        scanner.close();
    }
}

// Class to represent a movie
class Movie {
    int docId;
    String name;
    double imdbRating;
    int releaseYear;
    String content;

    // Constructor for the Movie class
    public Movie(int docId, String name, double imdbRating, int releaseYear, String content) {
        this.docId = docId;
        this.name = name;
        this.imdbRating = imdbRating;
        this.releaseYear = releaseYear;
        this.content = content;
    }

    // Method to split the movie's name and content into words
    public String[] getWords() {
        return (name + " " + content).toLowerCase().split("\\W+");
    }
}

// Class to represent the result of a search
class SearchResult {
    private final int docId;
    private final double relevanceScore;

    // Constructor for the SearchResult class
    public SearchResult(int docId, double relevanceScore) {
        this.docId = docId;
        this.relevanceScore = relevanceScore;
    }

    // Getter method for the document ID
    public int getDocId() {
        return docId;
    }

    // Getter method for the relevance score
    public double getRelevanceScore() {
        return relevanceScore;
    }
}
