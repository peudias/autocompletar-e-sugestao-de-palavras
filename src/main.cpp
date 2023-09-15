#include "include/util.hpp"
#include "include/file.hpp"
#include "include/heap.hpp"
#include "include/tree.hpp"
#define k 10

int main() {
    string textInput = "./dataset/input";
    string userInput = "./dataset/wordToSearch";

    vector<string> filePaths = processDirectory(textInput);

    for(const string &filePath : filePaths){
        ifstream inputFile;
        unordered_map<string, int> frequencyMap;
        unordered_set<string> stopwords = readStopwords("./dataset/stopwords/stopwords.txt");
        openTextFile(filePath, inputFile);
        processText(inputFile, frequencyMap, stopwords);
        processHash(frequencyMap, k, filePath);
        inputFile.close();
    }

    return 0;
}