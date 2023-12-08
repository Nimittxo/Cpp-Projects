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
    std::string paragraph1 = R"(Imagine a world where every flight is seamlessly tracked, and data transforms into insights that revolutionize air travel. That's the world I'm dedicated to creating at Flightradar24.

My journey is rooted in a profound passion for aviation, merged with a technical prowess in [specific area, e.g., software development, data analysis, etc.]. What sets me apart is not just my skill set, but my unwavering dedication to harnessing technology for the betterment of air travel.

I've honed my skills at [mention relevant experiences or projects], where I've navigated [specific challenges or accomplishments]. From [highlight a standout achievement] to [mention another significant accomplishment], I've consistently leveraged my expertise to drive innovation and solve complex problems.

What truly excites me about Flightradar24 is the opportunity to be at the forefront of the aviation industry's evolution. My blend of technical proficiency, a deep-rooted passion for aviation, and a track record of [mention relevant achievements or skills] positions me perfectly to contribute to Flightradar24's mission of revolutionizing flight tracking.

I'm not just seeking a job; I'm seeking a chance to make an impact. I'm ready to bring my unique blend of skills, passion, and innovation to the team at Flightradar24, helping redefine how we experience and understand air travel.)";

    std::string paragraph2 = R"(Greetings!

At 18, my love affair with aviation began, and it's been fueled by a dream that resonates closely with Flightradar24's mission—to track flights and transform that data into valuable, accessible information. This dream wasn't just a passing interest; it led me to dive headfirst into creating a project similar to Flightradar24.

While most teens were exploring other hobbies, I was captivated by the idea of real-time flight tracking. My passion for aviation coupled with an insatiable curiosity about technology led me to embark on a project aimed at tracking and displaying flight information—an endeavor inspired by the vision Flightradar24 embodies.

Developing this project wasn't just a technical exercise; it was a labor of love. It involved endless hours of coding, experimenting with data sources, and visualizing information in a user-friendly way. Through this, I encountered challenges, learned invaluable lessons, and developed a profound appreciation for the complexities of flight data.

What excites me about Flightradar24 is the chance to elevate this passion project into a profession. My age may belie my enthusiasm and dedication, but my commitment to this field is unwavering. My experience with my project has provided me with a firsthand understanding of the intricacies involved in real-time flight tracking, and I am eager to bring this knowledge to the innovative team at Flightradar24.

I'm not just an aviation enthusiast; I'm someone who has already taken tangible steps toward the vision that Flightradar24 embodies. Joining your team isn't just an opportunity—it's the culmination of a dream and a chance to contribute to a cause I deeply believe in.

Thank you for considering how my passion, commitment, and hands-on experience can be an asset to Flightradar24.)";

    checkSimilarity(paragraph1, paragraph2);

    return 0;
}
