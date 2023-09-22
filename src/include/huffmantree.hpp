#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP
#include "util.hpp"

class huffmanNode {
private:
	string palavra_;
	size_t frequencia_;
	huffmanNode* esquerda_;
	huffmanNode* direita_;

public:
	huffmanNode() {}

	huffmanNode(string palavra, size_t frequencia)
		: palavra_(palavra), frequencia_(frequencia) {
		esquerda_ = nullptr;
		direita_ = nullptr;
	}
	~huffmanNode() {}

	static bool compara(huffmanNode* a, huffmanNode* b) {
		return a->getFrequencia() < b->getFrequencia();
	}

	void setEsquerda(huffmanNode* no) { esquerda_ = no; }
	void setDireita(huffmanNode* no) { direita_ = no; }

	size_t getFrequencia() { return frequencia_; }
	string getPalavra() { return palavra_; }

	huffmanNode* getEsquerda() { return esquerda_; }
	huffmanNode* getDireita() { return direita_; }
};

class HuffmanTree {
private:
	vector<huffmanNode*> filaPrioridade_;
	huffmanNode* raiz_;

	void preOrdem(huffmanNode* no, ofstream& outputFile);
public:
	HuffmanTree() {}
	~HuffmanTree() {}

	void insere(huffmanNode* no);
	void constroi(const vector<pair<string, int>>& topKWords);
	void printInOrderToFile(const string& fileName);
};

#endif