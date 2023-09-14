#include "include/util.hpp"
#include "include/file.hpp"
#include "include/heap.hpp"
#include "include/tree.hpp"
#define k 10

int main() {
    string textInput = "./dataset/input";
    string userInput = "./dataset/wordInput";

    vector<string> filePaths = processDirectory(textInput);

    for(const string &filePath : filePaths){
        ifstream inputFile;
        unordered_map<string, int> frequencyMap;
        unordered_set<string> stopwords = readStopwords("./dataset/stopwords.txt");
        readTextFile(filePath, inputFile, frequencyMap, stopwords);
        processText(inputFile, frequencyMap, stopwords);
        processHash(frequencyMap, k, filePath);
        inputFile.close();
    }

    return 0;
}