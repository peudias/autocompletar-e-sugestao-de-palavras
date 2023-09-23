# Sistema de Autocompletar e Sugestões de Palavras

<div style="display: inline_block" align="left">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="Windows" src="https://img.shields.io/badge/Windows-FCC624?style=for-the-badge&logo=windows&logoColor=blue" />
  <img align="center" alt="CMake" src="https://img.shields.io/badge/CMake-FF5733?style=for-the-badge&logo=cmake&logoColor=white" />
  <img align="center" alt="Makefile" src="https://img.shields.io/badge/Makefile-FF5733?style=for-the-badge" />
</div>

<!--=====================================================================================================================
## Questionário: ✅?
1. O código pode ser baixado do git? ✅
4. O código está bem estruturado e organizado? ✅
5. O código bem como a entrada seguem os padrões de pasta e nomes definidos? ✅
............................................................................
6. A documentação apresenta uma discussão sobre o problema? ✅
7. A documentação apresenta como foi pensado a resolução do problema?
8. A documentação apresenta pequenos exemplos para explicar o funcionamento? ✅
9. A documentação apresenta conclusões sobre o trabalho?
10. A documentação detalha a forma como o código deve ser compilado? ✅

## Documentação ✅?
A documentação a ser produzida deve conter, pelo menos, as seguintes partes:
• Um detalhamento mínimo que explique as fases de especificação, projeto e implemen-
tação. Nessa etapa, deve-se incluir uma ampla discussão sobre as estruturas utilizadas
e o motivo de sua escolha para manter o desempenho da solução. ✅

• Para os arquivos utilizados para teste, uma descrição da saída esperada. ✅

• Uma parte do README.md contendo todas as instruções necessárias para a execução
de seu trabalho para arquivos de entrada diferentes dos adotados durante os testes. ✅

• Um git contendo todo o projeto, bem como, toda descrição pertinente sobre sua execução,
projeto e implementação. ✅

•  Neste documento (README.mb), espera-se observar uma discussão sobre as estruturas adotadas e o motivo de tal utilização.
Nesse último ponto, tente realizar um paralelo com outras estruturas para demonstrar de fato que as estruturas
adotadas são as melhores possíveis para o problema em questão. ✅

1. Apresentando o problema ✅
2. Regras ✅
3. Implementação do problema ✅
4. Resolução do problema ✅
5. Experimentação ✅
6. Análise de Complexidade
7. Conclusão ✅
8. Compilação e Execução ✅



==============================================================================================================================-->

<!-- ## Wiki do Projeto 📚

<div align="justify">

Para obter informações mais detalhadas sobre o projeto, acesse a [**Wiki**](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/wiki).

Na Wiki, você terá acesso à documentação completa, instruções de execução e análise detalhada sobre as estruturas de dados, algoritmos utilizados e outros aspectos relevantes do projeto.

</div> -->

## Apresentando o problema 📝

<div align="justify">

Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, adotaremos a estrutura da árvore binária como base. Além disso, exploraremos outras estruturas, incluindo as árvores AVL e Huffman.

</div>

## Regras 📜

No arquivo disponibilizado pelo professor da disciplina, houveram algumas regras explícitas para serem seguidas. Disponível a seguir:

**1º Passo: Coleta de Dados**

<div align="justify">

[✔️] Iniciamos solicitando ao usuário um arquivo denominado [`input.data`](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/dataset/wordToSearch/input.data), contendo uma lista de palavras. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema.

</div>

**2º Passo: Modelo de Dados - Árvores Binárias**

<div align="justify">

[✔️] Utilizaremos um conjunto de árvores binárias para construir nosso sistema. Essas árvores serão criadas a partir de [`textos previamente fornecidos`](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset/input). O objetivo é estabelecer uma relação entre as palavras dos textos e as palavras de pesquisa.

</div>

**3º Passo: Sugestões de Palavras Relevantes**

<div align="justify">

[✔️] Para cada palavra no arquivo input.data, percorreremos as árvores binárias para identificar as palavras mais relevantes e próximas à palavra de pesquisa. Priorizaremos palavras frequentes e associadas ao termo de pesquisa.

</div>

**4º Passo: Resultados e Análises**

<div align="justify">

[✔️] Os resultados da análise serão apresentados em um arquivo chamado [`output.data`](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/dataset/outputs/output.data). Esse arquivo conterá as relações entre as palavras pesquisadas e cada arquivo de texto. Além disso, a relevância de cada palavra será calculada com base em sua frequência nos textos. Para tal, foi utilizado o trabalho recentemente realizado, o [Top-K-Elementos](https://github.com/phpdias/top-k-elementos).

</div>

## Implementação do Problema 💡

<div align="justify">

A abordagem consistirá em três etapas diferentes:

</div>

- **Etapa 1: Árvore Binária Padrão**

<div align="justify">

Implementaremos uma [árvore binária tradicional](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/src/binarytree.cpp), selecionando as palavras mais relevantes e relacionadas à pesquisa em cada texto. A relevância de uma palavra será determinada por sua frequência e proximidade à palavra de pesquisa.

Essa implementação de uma Árvore Binária oferece um conjunto de funcionalidades essenciais. Inicialmente, o construtor da classe `BinaryTree` estabelece a árvore com uma raiz nula. O destrutor, por sua vez, utiliza a função `destroyTree` para efetuar a liberação de memória, garantindo a gestão adequada dos nós da árvore.

A inserção de pares (palavra, frequência) é suportada pela função `insert`, mantendo a árvore ordenada com base nas frequências das palavras. A impressão dos nós em ordem (in-order), incluindo palavras e frequências, é realizada pela função `printInOrderToFile`. Além disso, duas funções complementares, `fillBinaryTree` e `printBinaryTreeInOrderToFile`, permitem preencher a árvore com dados relevantes a partir de um vetor de pares e imprimir a representação da árvore ordenada em um arquivo, respectivamente.

> Tempo médio levando em consideração o conjunto de dados que será apresentado na experimentação: 0.021 milissegundos.

</div>

- **Etapa 2: Codificação de Huffman**

<div align="justify">

Exploraremos o uso do [código de Huffman](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/src/huffmantree.cpp) para otimizar a árvore binária padrão. Calcularemos códigos para cada palavra e reorganizaremos a estrutura da árvore com base nesses códigos. Avaliaremos se essa abordagem oferece vantagens em relação à anterior.

Essa implementação de uma Árvore de Huffman oferece um conjunto de funcionalidades fundamentais. Essas quatro funções compõem a sua implementação.

A primeira função, `HuffmanTree::insere`, é responsável por inserir nós na fila de prioridade da árvore. Essa fila mantém os nós ordenados de acordo com suas frequências, um elemento-chave na construção da Árvore de Huffman.

A segunda função, `HuffmanTree::constroi`, é crucial para a criação da própria árvore. Ela utiliza uma lista de palavras-chave e suas frequências para inicializar a fila de prioridade com nós individuais para cada palavra-chave. A partir daí, a função combina iterativamente esses nós para construir a árvore de Huffman. A ordenação crescente da fila de prioridade é essencial para garantir a correta construção da árvore.

A terceira função, `HuffmanTree::preOrdem`, realiza uma travessia pré-ordem na árvore já construída. Durante essa travessia, ela escreve as palavras e suas frequências em um arquivo de saída, o que é útil para representar a estrutura da árvore e suas frequências associadas.

Por fim, a quarta função, `HuffmanTree::printInOrderToFile`, abre um arquivo de saída e imprime a representação da árvore de Huffman em ordem pré-ordem nesse arquivo. Isso permite que a estrutura da árvore seja visualizada e utilizada posteriormente.

A implementação dessa estrutura é valiosa e oferece vantagens na compressão de dados, pois a Árvore de Huffman resultante permite representar palavras mais frequentes com códigos mais curtos, economizando espaço de armazenamento. As funções desempenham papéis específicos na criação e na representação dessa estrutura de dados fundamental para a compressão eficiente de informações.

> Tempo médio levando em consideração o conjunto de dados que será apresentado na experimentação: 0.064 milissegundos.

</div>

- **Etapa 3: Árvore AVL**

<div align="justify">

Implementaremos uma [árvore AVL](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/src/avltree.cpp) e repetiremos o processo de análise. Compararemos o tempo médio de processamento entre a construção da estrutura e a geração de saída em comparação com as abordagens anteriores.

A Árvore AVL é uma árvore de busca binária que mantém o equilíbrio, garantindo que a diferença de altura entre suas subárvores esquerda e direita seja no máximo uma unidade.

Essa implementação inclui funções para calcular a altura de um nó, o fator de balanceamento de um nó e atualizar a altura de um nó com base em suas subárvores. Também inclui rotações para manter o balanceamento e uma função de inserção que mantém a propriedade AVL após inserir um novo elemento.

Além disso, há funções para imprimir a árvore em ordem em um arquivo e preencher a árvore a partir de um vetor de entrada. Essa implementação é útil para operações eficientes de busca e inserção em conjuntos de dados ordenados.

> Tempo médio levando em consideração o conjunto de dados que será apresentado na experimentação: 0.09 milissegundos.

</div>

## Resolução do problema ✅

Após a conclusão do projeto, temos aqui um algoritmo capaz de:

- [✔️] Ler uma quantidade não determinada de textos onde serão pesquisadas as palavras do usuário;
- [✔️] Ler palavras de escolha do usuário para serem pesquisadas;
- [✔️] Processar esses textos tratando letras maiúsculas, minúsculas, espaços e pontuações;
- [✔️] Remoção de StopWords;
- [✔️] Utilização da estrutura de dados Hash;
- [✔️] Utilização da estrutura de dados MinHeap;
- [✔️] Utilização da estrutura de dados Árvore Binária;
- [✔️] Utilização da estrutura de dados Árvore AVL;
- [✔️] Utilização da estrutura de dados Árvore Huffman;
- [✔️] Demonstrar as **palavras mais relevantes** de um conjunto de dados utilizando cada uma das estruturas acima, identificando a palavra e a frequência da palavra para cada arquivo de texto, se assim disponível.

## Experimentação 🔬

<div align="justify">
  
</div>

### Entradas de dados necessárias 🗂️

<div align="justify">

Dentro do programa, encontra-se uma pasta denominada [dataset](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset), a qual abriga, em seu interior, outros 4 diretórios, nomeados como:

- [input](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset/input) que contém os textos a serem analisados;
- [outputs](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset/outputs) que contém o arquivo com os resultados;

- [stopwords](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset/stopwords) que contém palavras a serem desconsideradas dos textos originais;

- [wordToSearch](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/tree/main/dataset/wordToSearch) que contém as palavras inseridas pelo usuário para serem analisadas.

</div>

#### Diretório ./dataset/input 📂

<div align="justify">

Neste diretório se encontram os arquivos em texto que serão lidos análise.

O usuário é livre para definir se todos os arquivos dentro desse diretório sejam ou não do tipo `.txt`. Da mesma forma podem ser nomeados sem qualquer restrição.

**Obs:. Afim de garantir o correto funcionamento do algoritmo, recomenda-se utilizar arquivos '.txt' como padrão. Arquivos de outra natureza ficam por conta e risco do usuário.**

</div>

#### Arquivo stopwords.txt 🛑

<div align="justify">

Este arquivo foi retirado desse repositório git utilizado como referência: [Top-K-Elementos](https://github.com/phpdias/top-k-elementos) [^1]

Analogamente, também pode ser digitado manualmente pelo usuário, mas não é o intuito inicial a utilização dessa forma.

</div>

### Saídas obtidas

<div align="justify">

Após garantir a correta configuração dos arquivos acima, ao executar o programa, a seguinte saída será gerada em [`output.data`](https://github.com/phpdias/autocompletar-e-sugestao-de-palavras/blob/main/dataset/outputs/output.data).

Observe que existe um padrão nas impressões:

> Primeiro é identificado o arquivo analisado.

> Em seguida é mostrado a quantidade de palavras inseridas pelo usuário que foram analisadas naquele texto e a frequência dessas palavras no arquivo de texto em questão. Observe que existe uma nota pontuando que, caso alguma palavra inserida pelo usuário não esteja presente na contagem, significa que essa palavra em questão não está presente no texto desse arquivo.

> É demonstrado as palavras mais relevantes, separadas por: Top-K-Elementos utilizando MinHeap; Árvores Binária, AVL e Huffman utilizando como base o Top-K.

> Por último, mostra o tempo de execução daquela estrutura para aquele conjunto de dados.

> Esse processo ocorre a quantidade de vezes correspondente a quantidade de textos para serem analisados.

O resultado obtido está na imagem abaixo.

</div>

<div align="center">

![Alt text](image.png)

</div>

<!-- ## Análise de Complexidade 🔎

<div align="justify">

Ao concluir esta tarefa, teremos uma compreensão mais aprofundada das diferentes implementações das árvores binárias e sua influência no sistema de autocompletar e sugestões de palavras. A análise comparativa de complexidade nos permitirá avaliar a eficácia de cada abordagem em termos de desempenho e funcionalidade.

</div> -->

# Conclusão 🎯

<div align="justify">

Com este projeto é possível concluir que essas implementações apresentam um conjunto de funcionalidades relacionadas ao processamento de texto e estruturas de dados de árvore.

A primeira implementação lida com a manipulação de palavras, frequências e uma estrutura de árvore binária.
A segunda implementação abordou a construção de uma Árvore de Huffman a partir de uma fila de prioridade, que é frequentemente usada para compressão de dados.
A terceira implementação trata de uma Árvore AVL, que é uma árvore de busca binária equilibrada por altura, útil para armazenar e recuperar dados de maneira eficiente.

Essas implementações demonstram como as estruturas de dados de árvore podem ser aplicadas em tarefas de processamento de texto, análise de dados e organização de informações. As árvores de Huffman são usadas para representar códigos de compressão eficientes, enquanto as árvores binárias e AVLs são usadas para armazenar e consultar dados de maneira eficaz.

</div>

# Compilação e Execução 🔄

<div align="justify">

Este algoritmo possui um arquivo Makefile e um arquivo CMakeLists que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

</div>

## Comandos para Linux:

| <img align="center" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="30" height="30"/> | Função                                                                                  |
| ------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| `make clean`                                                                                                                                            | Apaga a última compilação realizada contida na pasta build                              |
| `make`                                                                                                                                                  | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
| `make run`                                                                                                                                              | Executa o programa da pasta build após a realização da compilação                       |
| `make r`                                                                                                                                                | Realiza o `make clean`, `make` e `make run` em sequência                                |

## Comandos para Windows:

| <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/windows8/windows8-original.svg" alt="Windows Icon" width="30" height="30"> | Função                                                                                        |
| ---------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| `cmake -B ./build-debug`                                                                                                                             | Executa geração de arquivos e o resultado vai para a pasta build-debug                        |
| `cmake --build ./build-debug`                                                                                                                        | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build-debug |
| `./build-debug/app`                                                                                                                                  | Executa o programa da pasta build-debug após a realização da compilação                       |

# Contatos 📇

| Contato    | Telegram                                                                                                                                                                             | LinkedIn                                                                                                                                                                                           | Email                                                                                                                                                                                                                                                                                   |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Pedro Dias | <a href="https://t.me/phpdias"><img align="center" height="24px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> | <a href="https://linkedin.com/in/phpd"><img align="center" height="24px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/></div> | <a href="mailto:phpdias@outlook.com?subject=[GitHub]%20Autocompletar%20E%20Sugestão%20De%20Palavras"><img align="center" height="25px" width="150px" src="https://img.shields.io/badge/phpdias@outlook.com-100000?style=for-the-badge&logo=phpdias@outlook.com&logoColor=white"/></div> |

## Referências

[^1]: [GitHub](https://github.com/phpdias/top-k-elementos)
[^2]: [CppReference](https://en.cppreference.com/)
[^3]: [CPlusPlus](https://cplusplus.com/)
