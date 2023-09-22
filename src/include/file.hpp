#ifndef FILE_HPP
#define FILE_HPP
#include "util.hpp"

vector<string> processDirectory(const string &directoryPath);
unordered_set<string> readStopwords(const string &filename);
void processText(istream &inputStream, unordered_map<string, int> &frequencyMap, const unordered_set<string> &stopwords);
void openTextFile(const string &filePath, ifstream &inputFile);

#endif