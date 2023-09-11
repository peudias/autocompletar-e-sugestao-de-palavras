#include "include/file.hpp"
#include "include/heap.hpp"

vector<string> readUserFile(const string &filename){
    vector<string> userWords;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << VERMELHO << "Erro ao abrir o arquivo de inserção do usuário: " << filename << RESET << endl;
        return userWords;
    }

    string word;
    while (inputFile >> word) {
        userWords.push_back(word);
    }

    inputFile.close();

    cout << VERDE << "Palavras coletadas do arquivo '" << filename << "':" << RESET << endl;
    for (const string &w : userWords) {
        cout << AZUL << w << RESET << endl;
    }

    return userWords;
}

unordered_set<string> readStopwords(const string &filename){
    unordered_set<string> stopwords;
    ifstream stopwordFile(filename);

    if(stopwordFile.is_open()){
        string stopword;
        while(getline(stopwordFile, stopword)){
            stopwords.insert(stopword);
        }
        stopwordFile.close();
    } else{
        cout << VERMELHO << "Erro ao abrir o arquivo de stopwords!" << RESET << endl;
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

void readTextFile(const string &filePath){
    ifstream inputFile(filePath);

    if(!inputFile.is_open()){
        cout << VERMELHO << "Erro ao abrir o arquivo de texto: " << filePath << RESET << endl;
        return;
    }

    unordered_map<string, int> frequencyMap;
    unordered_set<string> stopwords = readStopwords("./dataset/stopwords.txt");

    processText(inputFile, frequencyMap, stopwords);
    int k = 3;
    processHash(frequencyMap, k);
    
    inputFile.close();
}

void searchWords(const string &palavra, const string &arquivo) {
    ifstream arquivoTexto(arquivo);
    if (!arquivoTexto.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << arquivo << endl;
        return;
    }

    string linha;
    int numeroLinha = 0;
    while (getline(arquivoTexto, linha)) {
        numeroLinha++;
        if (linha.find(palavra) != string::npos) {
            cout << VERDE << "Palavra encontrada em " << arquivo << " (linha " << numeroLinha << "): "  << endl;
            // << RESET << linha << endl;
        }
    }

    arquivoTexto.close();
}