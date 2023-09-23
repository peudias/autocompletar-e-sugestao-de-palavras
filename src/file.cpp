#include "include/file.hpp"
#include "include/heap.hpp"

unordered_set<string> readStopwords(const string &filename){
    unordered_set<string> stopwords;
    ifstream stopwordFile(filename);

    if(stopwordFile.is_open()){
        string stopword;
        while(getline(stopwordFile, stopword)){
            stopwords.insert(stopword);
        }
        stopwordFile.close();
    }else{
        cout << VERMELHO << "Erro ao abrir o arquivo de " << RESET << "STOPWORDS! " << AMARELO << "(" <<  filename << ")" << RESET << endl;
    }
    return stopwords;
}

void processText(istream &inputStream, unordered_map<string, int> &frequencyMap, const unordered_set<string> &stopwords){
    string line;

    while(getline(inputStream, line)){
        istringstream iss(line);
        string token;

        while(iss >> token){
            transform(token.begin(), token.end(), token.begin(), ::tolower);
            while(!token.empty() && ispunct(token.front())){
                token.erase(token.begin());
            }
            while(!token.empty() && ispunct(token.back())){
                token.pop_back();
            }

            if(stopwords.find(token) != stopwords.end()){
                continue;
            }

            size_t start = 0;
            while(start < token.length()){
                while(start < token.length() && (isspace(token[start]) || ispunct(token[start]))){
                    start++;
                }
                size_t end = token.find_first_of(".,;:'?!()[]{}—“”", start);
                if(end == string::npos){
                    end = token.length();
                }
                string word = token.substr(start, end - start);
                if(!word.empty() && stopwords.find(word) == stopwords.end()){
                    frequencyMap[word]++;
                }
                start = end + 1;
            }
        }
    }
}

void openTextFile(const string &filePath, ifstream &inputFile){
    inputFile.open(filePath);

    if(!inputFile.is_open()){
        cout << VERMELHO << "Erro ao abrir o arquivo de " << RESET << "TEXTO! " << MAGENTA << "(" <<  filePath << ")" << RESET << endl << endl;
        return;
    }
}

vector<string> processDirectory(const string &directoryPath){
    vector<string> filePaths;

    if(fs::is_directory(directoryPath)){
        for(const auto &entry : fs::directory_iterator(directoryPath)){
            if(entry.is_regular_file()){
                string filePath = entry.path();
                filePaths.push_back(filePath);
            }
        }
    }
    return filePaths;
}

void calcTime(double& timeBinaryTree, clock_t& endBinaryTree, clock_t& startBinaryTree, const string& fileName) {
    ofstream outputFile(fileName, ios::app);
    timeBinaryTree = (double)(endBinaryTree - startBinaryTree) * 1000 / CLOCKS_PER_SEC;
    outputFile << setw(4) << endl << "->" << "Tempo de execução para essa estrutura: " << timeBinaryTree << " milissegundos" << endl << endl;
}