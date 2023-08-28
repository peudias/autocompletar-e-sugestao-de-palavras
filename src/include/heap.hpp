#ifndef HEAP_HPP
#define HEAP_HPP
#include "util.hpp"

struct HeapNode{
    string word;
    int count;

    HeapNode(const string &w, int c) : word(w), count(c){}
};

class MinHeapComparator{
public:
    bool operator()(const HeapNode &a, const HeapNode &b) const{
        return a.count > b.count;
    }
};

void insertToMinHeap(priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, const HeapNode &node, int k);
void printMinHeap(const priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap);
void processHash(const unordered_map<string, int> &frequencyMap, int k);

#endif