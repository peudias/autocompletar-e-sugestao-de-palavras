#include "include/util.hpp"
#include "include/file.hpp"
#include "include/heap.hpp"
#include "include/tree.hpp"
#define k 10

int main() {
    string textInput = "./dataset/input";
    string userInput = "./dataset/wordToSearch";

    vector<string> filePaths = processDirectory(textInput);
    vector<string> filePathsUser = processDirectory(userInput);

    unordered_map<string, int> wordsToSearch;

    for(const string &filePath : filePathsUser){
        ifstream userFile;
        unordered_set<string> stopwords = readStopwords("./dataset/stopwords/stopwords.txt");
        openTextFile(filePath, userFile);
        processText(userFile, wordsToSearch, stopwords);
        processHash(wordsToSearch, k, filePath);
        userFile.close();
    }

    ofstream outFile("./dataset/outputs/output.txt", ios::app);

    for(const string &filePath : filePaths){
        ifstream inputFile;
        unordered_map<string, int> frequencyMap;
        unordered_set<string> stopwords = readStopwords("./dataset/stopwords/stopwords.txt");
        openTextFile(filePath, inputFile);
        processText(inputFile, frequencyMap, stopwords);
        processHash(frequencyMap, k, filePath);
        inputFile.close();

        printWordFrequency(frequencyMap, wordsToSearch, filePath, outFile);
    }

    return 0;
}