#ifndef TREE_HPP
#define TREE_HPP
#include "util.hpp"

unordered_set<string> readStopwords(const string &filename);
void processText(istream &inputStream, unordered_map<string, int> &frequencyMap, const unordered_set<string> &stopwords);
void readFile(const string &filePath);

#endif