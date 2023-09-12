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
    string wordInput = "./dataset/wordInput";

    processDirectory(textInput);
    processDirectory(wordInput);

    return 0;
}