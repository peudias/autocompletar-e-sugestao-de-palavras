#include "include/huffmantree.hpp"

/**
 * @brief insercao na fila de prioridade
 *
 * como a insercao sera feita a partir da ordem central de uma arvore
 * binaria de busca, a insercao sera feita de forma ordenada
 *
 * @param no
 */
void HuffmanTree::insere(huffmanNode* no) {
	this->filaPrioridade_.push_back(no);
}

/**
 * @brief constroi a arvore de huffman a partir da fila de prioridade
 *
 * a fila de prioridade deve estar ordenada de forma crescente
 * para que a arvore seja construida corretamente, pois ira pegar
 * os dois primeiros elementos da fila e criar um novo no com a soma
 */
void HuffmanTree::constroi(const vector<pair<string, int>>& topKWords) {
	for (auto& [word, count] : topKWords) {
        insere(new huffmanNode(word, count));
    }
	while (this->filaPrioridade_.size() > 1) {
		huffmanNode* x = this->filaPrioridade_[0];
		huffmanNode* y = this->filaPrioridade_[1];

		huffmanNode* z = new huffmanNode("#", x->getFrequencia() + y->getFrequencia());

		z->setEsquerda(x);
		z->setDireita(y);

		this->filaPrioridade_.erase(this->filaPrioridade_.begin());
		this->filaPrioridade_.erase(this->filaPrioridade_.begin());

		this->insere(z);

		sort(this->filaPrioridade_.begin(), this->filaPrioridade_.end(), huffmanNode::compara);
	}
	this->raiz_ = this->filaPrioridade_[0];
}

void HuffmanTree::preOrdem(huffmanNode* no, ofstream& outputFile) {
	if (no != nullptr) {
		if (no->getPalavra() != "#") {
			outputFile << no->getPalavra() << " ";
			outputFile << "(" << no->getFrequencia() << "); ";
		}
		this->preOrdem(no->getEsquerda(), outputFile);
		this->preOrdem(no->getDireita(), outputFile);
	}
}

void HuffmanTree::printInOrderToFile(const string& fileName){
	ofstream outputFile(fileName, ios::app);
	outputFile << endl << "Árvore Huffman em ordem:" << endl;
    preOrdem(raiz_, outputFile);
}