#include "include/util.hpp"
#include "include/file.hpp"
#include "include/heap.hpp"
#include "include/tree.hpp"
#define k 5

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
        userFile.close();
    }

    ofstream outFile("./dataset/outputs/output.data", ios::app);

    for(const string &filePath : filePaths){
        ifstream inputFile;
        unordered_map<string, int> frequencyMap;
        unordered_set<string> stopwords = readStopwords("./dataset/stopwords/stopwords.txt");
        openTextFile(filePath, inputFile);
        processText(inputFile, frequencyMap, stopwords);
        priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap = processHash(frequencyMap, k, filePath);
        printWordFrequency(frequencyMap, wordsToSearch, filePath, outFile);
        vector<pair<string, int>> topKWords = printMinHeap(filePath, minHeap, outFile, wordsToSearch, frequencyMap, k);
        inputFile.close();
    }

    return 0;
}