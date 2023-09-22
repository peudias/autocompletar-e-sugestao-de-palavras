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
vector<pair<string, int>> printMinHeap(const string &fileName, priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, ostream &outputStream, const unordered_map<string, int> &wordToCheck, const unordered_map<string, int> &frequencyMap, int k);
priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> processHash(const unordered_map<string, int> &frequencyMap, int k, const string &fileName);
void printWordFrequency(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch, const string &filePath, ostream &outputStream);
int countWords(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch);

#endif