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

void printMinHeap(const priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, ostream &outputStream){
    outputStream << "|===== Top-K-Elementos =====|" << endl;
    outputStream << "|== " << "Palavra" << " vs." << "Frequência" << " ==|" << endl;

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
    outputStream << "|===========================|" << endl << endl;
}

void processHash(const unordered_map<string, int> &frequencyMap, int k){
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap;

    ofstream outFile("./dataset/outputs/output.txt", ios::app);

    for(const auto &entry : frequencyMap){
        HeapNode node(entry.first, entry.second);
        insertToMinHeap(minHeap, node, k);
    }

    printMinHeap(minHeap, outFile);
}