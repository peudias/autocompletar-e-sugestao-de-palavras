#include "include/util.hpp"
#include "include/file.hpp"
#include "include/heap.hpp"
#include "include/tree.hpp"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){
    clearConsole();
    string textInput = "./dataset/input";

    for(const auto &entry : fs::directory_iterator(textInput)){
        if(entry.is_regular_file() && entry.path().extension() == ".txt"){
            cout <<  "Arquivo: "<< AZUL << entry.path() << RESET << endl;
            readTextFile(entry.path());
        }
    }

    string userWordInput = "./dataset/input.data";
    vector<string> userWords = readUserFile(userWordInput);

    vector<string> arquivosDeTexto = {"./dataset/input/filosofia.txt"};

    for (const string &palavra : userWords) {
        for (const string &arquivo : arquivosDeTexto) {
            searchWords(palavra, arquivo);
        }
    }

    // TreeNode* root = nullptr;

    // for(const string& word : userWords) {
    //     insert(root, word);
    // }

    // printInOrder(root);

    return 0;
}