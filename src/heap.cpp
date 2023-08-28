#include "include/heap.hpp"

void insertToMinHeap(priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, const HeapNode &node, int k){
    if(minHeap.size() < k){
        minHeap.push(node);
    }else if(node.count > minHeap.top().count){
        minHeap.pop();
        minHeap.push(node);
    }
}

void printMinHeap(const priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap){
    cout << MAGENTA << "|===== Top-K-Elementos =====|" << RESET << endl;
    cout << MAGENTA << "|== " << VERMELHO << "Palavra" << AMARELO << " vs." << VERDE << "Frequência" << MAGENTA << " ==|" << endl;

    int counter = 1;
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeapCopy = minHeap;

    while (!minHeapCopy.empty()){
        const HeapNode &node = minHeapCopy.top();
        cout << MAGENTA << "| " << RESET;
        if(counter < 10 && counter > 0){
            cout << "0";
        }
        cout << counter << ". " << VERMELHO << node.word << AMARELO << " vs. " << VERDE << node.count << RESET << endl;
        minHeapCopy.pop();
        counter++;
    }
    cout << MAGENTA << "|===========================|" << RESET << endl << endl;
}

void processHash(const unordered_map<string, int> &frequencyMap, int k){
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap;

    for(const auto &entry : frequencyMap){
        HeapNode node(entry.first, entry.second);
        insertToMinHeap(minHeap, node, k);
    }

    printMinHeap(minHeap);
}