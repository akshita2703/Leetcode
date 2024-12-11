#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

std::vector<std::string> spamOrNotSpam(std::vector<std::string>& sentences, std::vector<std::string>& spamwords) {
    std::vector<std::string> result;

    if (sentences.empty() || spamwords.empty()) {
        result.push_back("not_spam");
        return result;
    }

    std::unordered_map<std::string, int> wordCount;
    int flag = 0;

    for (const auto& sentence : sentences) {
        std::vector<std::string> words;
        std::string word;

        // Extract words from the sentence
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word += tolower(c); // Convert to lowercase
            }
        }
        words.push_back(word); // Adding the last word

        // Count occurrences of spam words in the sentence
        for (const auto& spamWord : spamwords) {
            auto it = std::find(words.begin(), words.end(), spamWord);
            if (it != words.end()) {
                wordCount[*it]++;
            }
        }

        // Check if any word occurs more than twice
        for (const auto& pair : wordCount) {
            if (pair.second >= 2) {
                flag = 1;
                break;
            }
        }

        // Determine if the sentence is spam or not_spam
        if (flag == 1) {
            result.push_back("spam");
        } else {
            result.push_back("not_spam");
        }

        flag = 0;
        wordCount.clear();
    }
    return result;
}

int main() {
    std::vector<std::string> sentences = {"to summertime is coming to do to", "Pay him the money"};
    std::vector<std::string> spamwords = {"to", "the", "him"};

    std::vector<std::string> result = spamOrNotSpam(sentences, spamwords);

    for (const auto& res : result) {
        std::cout << res << std::endl;
    }

    return 0;
}
