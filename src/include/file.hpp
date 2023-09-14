#ifndef FILE_HPP
#define FILE_HPP
#include "util.hpp"

unordered_set<string> readStopwords(const string &filename);
void processText(istream &inputStream, unordered_map<string, int> &frequencyMap, const unordered_set<string> &stopwords);
void readTextFile(const string &filePath, ifstream &inputFile, unordered_map<string, int> &frequencyMap, unordered_set<string> &stopwords);
vector<string> processDirectory(const string &directoryPath);

#endif