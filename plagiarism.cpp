#include <iostream>
#include <unordered_set>
#include <sstream>

// Function to split a string into words
std::unordered_set<std::string> splitIntoWords(const std::string& str) {
    std::unordered_set<std::string> words;
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        words.insert(word);
    }
    return words;
}

// Function to check similarity between two paragraphs
void checkSimilarity(const std::string& paragraph1, const std::string& paragraph2) {
    std::unordered_set<std::string> words1 = splitIntoWords(paragraph1);
    std::unordered_set<std::string> words2 = splitIntoWords(paragraph2);

    // Calculate the number of common words
    int commonWords = 0;
    for (const auto& word : words1) {
        if (words2.find(word) != words2.end()) {
            commonWords++;
        }
    }

    // Calculate similarity
    double similarity = static_cast<double>(commonWords) / std::min(words1.size(), words2.size()) * 100;

    std::cout << "Similarity between the paragraphs: " << similarity << "%" << std::endl;
}

int main() {
    // Representing paragraphs as strings
    std::string paragraph1 = R"(Enter Copied Sting Here !");

    std::string paragraph2 = R"(Enter The Original String)";

    checkSimilarity(paragraph1, paragraph2);

    return 0;
}
