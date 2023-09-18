#include "include/heap.hpp"
#include "include/tree.hpp"

void insertToMinHeap(priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, const HeapNode &node, int k){
    if(minHeap.size() < k){
        minHeap.push(node);
    }else if(node.count > minHeap.top().count){
        minHeap.pop();
        minHeap.push(node);
    }
}

void printMinHeap(const string &fileName, const priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, ostream &outputStream){
    outputStream << endl << "Palavras mais relevantes: " ;

    int counter = 1;
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeapCopy = minHeap;

    while (!minHeapCopy.empty()){
        const HeapNode &node = minHeapCopy.top();
        outputStream << node.word << " (" << node.count << ")" << ", ";
        minHeapCopy.pop();
        counter++;
    }
}

priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> processHash(const unordered_map<string, int> &frequencyMap, int k, const string &fileName){
    ofstream outFile("./dataset/outputs/output.txt", ios::app);
    
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap;

    for(const auto &entry : frequencyMap){
        HeapNode node(entry.first, entry.second);
        insertToMinHeap(minHeap, node, k);
    }

    // printMinHeap(fileName, minHeap, outFile);
    return minHeap;
}

void printWordFrequency(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch, const string &filePath, ostream &outputStream){
    outputStream << endl << "----------------------------------------------------" << endl;
    outputStream << "Arquivo: " << filePath << endl << endl;
    for (const auto &word : frequencyMap) {
        if (wordsToSearch.find(word.first) != wordsToSearch.end()) {
            outputStream << "> Palavra pesquisada: '" << word.first << "' | " << "Frequência da palavra pesquisada: '" << word.second << "'" << endl;
        }
    }
}