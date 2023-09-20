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

vector<pair<string, int>> printMinHeap(const string &fileName, priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> &minHeap, ostream &outputStream, const unordered_map<string, int> &wordToCheck, const unordered_map<string, int> &frequencyMap, int k) {
    outputStream << endl << "Palavras mais relevantes: ";

    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeapCopy = minHeap;
    bool found = false;

    vector<pair<string, int>> topKWords;

    if(!found){
        vector<pair<string, int>> newWords;

        for(const auto &entry : frequencyMap){
            auto it = wordToCheck.find(entry.first);
            if (it == wordToCheck.end()){
                newWords.push_back(entry);
            }
        }

        sort(newWords.begin(), newWords.end(), [](const pair<string, int> &a, const pair<string, int> &b){
            return a.second > b.second;
        });

        priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> newHeap;
        for(const auto &wordPair : newWords){
            HeapNode node(wordPair.first, wordPair.second);
            newHeap.push(node);
        }

        while(newHeap.size() > k){
            newHeap.pop();
        }

        minHeap = newHeap;


        while(!newHeap.empty()){
            HeapNode newNode = newHeap.top();
            newHeap.pop();
            outputStream << newNode.word << " (" << newNode.count << "), ";
            topKWords.emplace_back(newNode.word, newNode.count);
        }
    }

    outputStream << endl;

    return topKWords;
}

priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> processHash(const unordered_map<string, int> &frequencyMap, int k, const string &fileName){
    //ofstream outFile("./dataset/outputs/output.data", ios::app);
    
    priority_queue<HeapNode, vector<HeapNode>, MinHeapComparator> minHeap;

    for(const auto &entry : frequencyMap){
        HeapNode node(entry.first, entry.second);
        insertToMinHeap(minHeap, node, k);
    }

    return minHeap;
}

void printWordFrequency(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch, const string &filePath, ostream &outputStream){
    outputStream << endl << "----------------------------------------------------" << endl;
    outputStream << "Arquivo: " << filePath << endl << endl;
    int wordCount = countWords(frequencyMap, wordsToSearch);
    outputStream << "Quantidade de palavras analisadas: " << wordCount << endl;
    for(const auto &word : frequencyMap){
        if(wordsToSearch.find(word.first) != wordsToSearch.end()){
            outputStream << "> Palavra pesquisada: '" << word.first << "' | " << "Frequência da palavra pesquisada: '" << word.second << "'" << endl;
        }
    }
}

int countWords(const unordered_map<string, int> &frequencyMap, const unordered_map<string, int> &wordsToSearch){
    int wordCount = 0; 
    for(const auto &word : frequencyMap){
        if (wordsToSearch.find(word.first) != wordsToSearch.end()){
            wordCount++;
        }
    }
    return wordCount;
}