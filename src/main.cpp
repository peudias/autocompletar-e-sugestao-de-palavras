#include "include/util.hpp"
#include "include/tree.hpp"
#include "include/heap.hpp"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){
    clearConsole();
    string fileLocal = "./dataset/input";

    for(const auto &entry : fs::directory_iterator(fileLocal)){
        if(entry.is_regular_file() && entry.path().extension() == ".txt"){
            cout <<  "Arquivo: "<< AZUL << entry.path() << RESET << endl;
            readFile(entry.path());
        }
    }

    return 0;
}