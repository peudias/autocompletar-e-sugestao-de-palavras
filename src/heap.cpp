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
    outputStream << "|======== Top-K-Elementos ========|" << endl;
    outputStream << "|===== Palavra vs. Frequência ====|" << endl;
    
    outputStream << "| Arquivo: " << fileName << "|" << endl;

    int counter = 1;
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeapCopy = minHeap;

    while (!minHeapCopy.empty()){
        const HeapNode &node = minHeapCopy.top();
        outputStream << "| ";
        if(counter < 10 && counter > 0){
            outputStream << "0";
        }
        outputStream << counter << ". " << node.word << " vs. " << node.count << endl;
        minHeapCopy.pop();
        counter++;
    }
    outputStream << "|=================================|" << endl << endl;
}

void processHash(const unordered_map<string, int> &frequencyMap, int k, const string &fileName){
    ofstream outFile("./dataset/outputs/minHeap.txt", ios::app);
    
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap;

    for(const auto &entry : frequencyMap){
        HeapNode node(entry.first, entry.second);
        insertToMinHeap(minHeap, node, k);
    }

    printMinHeap(fileName, minHeap, outFile);
}

void printWordFrequency(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch, const string &filePath, ostream &outputStream){
    outputStream << "----------------------------------------------------" << endl;
    outputStream << "Arquivo: " << filePath << endl << endl;
    for (const auto &word : frequencyMap) {
        if (wordsToSearch.find(word.first) != wordsToSearch.end()) {
            outputStream << "Palavra pesquisada: '" << word.first << "' | " << "Frequência da palavra pesquisada: '" << word.second << "'" << endl;
        }
    }
}