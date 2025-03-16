import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
public class BM25InvertedIndex {
    private Map<String, Map<Integer, Integer>> index;
    private Map<Integer, Movie> movies;
    private int totalDocuments;
    private double avgDocumentLength;
    private static final double K = 1.5;
    private static final double B = 0.75;
    public BM25InvertedIndex() {
        index = new HashMap<>();
        movies = new HashMap<>();
        totalDocuments = 0;
        avgDocumentLength = 0.0;
    }
    public void addMovie(int docId, String name, double imdbRating, int releaseYear, String content) {
        Movie movie = new Movie(docId, name, imdbRating, releaseYear, content);
        movies.put(docId, movie);
        totalDocuments++;
        String[] terms = movie.getWords();
        int docLength = terms.length;
        avgDocumentLength = ((avgDocumentLength * (totalDocuments - 1)) + docLength) / totalDocuments;
        for (String term : terms) {
            index.putIfAbsent(term, new HashMap<>());
            Map<Integer, Integer> docList = index.get(term);
            docList.put(docId, docList.getOrDefault(docId, 0) + 1);
        }
    }
    public List<SearchResult> search(String term) {
        term = term.toLowerCase();
        if (!index.containsKey(term)) {
            return new ArrayList<>();
        }
        Map<Integer, Integer> termDocs = index.get(term);
        List<SearchResult> results = new ArrayList<>();
        double idf = computeIDF(termDocs.size());
        for (Map.Entry<Integer, Integer> entry : termDocs.entrySet()) {
            int docId = entry.getKey();
            int termFrequency = entry.getValue();
            Movie movie = movies.get(docId);
            double docLength = movie.getWords().length;
            double score = computeBM25Score(termFrequency, docLength, idf);
            results.add(new SearchResult(docId, score));
        }
        results.sort((r1, r2) -> Double.compare(r2.getRelevanceScore(), r1.getRelevanceScore()));
        return results;
    }
    private double computeBM25Score(int termFrequency, double docLength, double idf) {
        double numerator = termFrequency * (K + 1);
        double denominator = termFrequency + K * (1 - B + B * (docLength / avgDocumentLength));
        return idf * (numerator / denominator);
    }
    private double computeIDF(int docFrequency) {
        return Math.log((totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int movieCount = Integer.parseInt(scanner.nextLine().trim());
        BM25InvertedIndex index = new BM25InvertedIndex();
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
class Movie {
    int docId;
    String name;
    double imdbRating;
    int releaseYear;
    String content;
    public Movie(int docId, String name, double imdbRating, int releaseYear, String content) {
        this.docId = docId;
        this.name = name;
        this.imdbRating = imdbRating;
        this.releaseYear = releaseYear;
        this.content = content;
    }
    public String[] getWords() {
        return (name + " " + content).toLowerCase().split("\\W+");
    }
}
class SearchResult {
    private final int docId;
    private final double relevanceScore;
    public SearchResult(int docId, double relevanceScore) {
        this.docId = docId;
        this.relevanceScore = relevanceScore;
    }
    public int getDocId() {
        return docId;
    }
    public double getRelevanceScore() {
        return relevanceScore;
    }
}
