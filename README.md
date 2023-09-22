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
6. A documentação apresenta uma discussão sobre o problema?
7. A documentação apresenta como foi pensado a resolução do problema?
8. A documentação apresenta pequenos exemplos para explicar o funcionamento?
9. A documentação apresenta conclusões sobre o trabalho?
10. A documentação detalha a forma como o código deve ser compilado? ✅

## Documentação ✅?
A documentação a ser produzida deve conter, pelo menos, as seguintes partes:
• Um detalhamento mínimo que explique as fases de especificação, projeto e implemen-
tação. Nessa etapa, deve-se incluir uma ampla discussão sobre as estruturas utilizadas
e o motivo de sua escolha para manter o desempenho da solução.

• Para os arquivos utilizados para teste, uma descrição da saída esperada.

• Uma parte do README.md contendo todas as instruções necessárias para a execução
de seu trabalho para arquivos de entrada diferentes dos adotados durante os testes.

• Um git contendo todo o projeto, bem como, toda descrição pertinente sobre sua execução,
projeto e implementação.

•  Neste documento (README.mb), espera-se observar uma discussão sobre as estruturas adotadas e o motivo de tal utilização.
Nesse último ponto, tente realizar um paralelo com outras estruturas para demonstrar de fato que as estruturas
adotadas são as melhores possíveis para o problema em questão.

1. Apresentando o problema ✅
2. Regras
3. Implementação do problema
4. Resolução do problema
5. Experimentação
6. Análise de Complexidade
7. Conclusão
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

Implementaremos uma árvore binária tradicional, selecionando as palavras mais relevantes e relacionadas à pesquisa em cada texto. A relevância de uma palavra será determinada por sua frequência e proximidade à palavra de pesquisa.

</div>

- **Etapa 2: Codificação de Huffman**

<div align="justify">

Exploraremos o uso do código de Huffman para otimizar a árvore binária padrão. Calcularemos códigos para cada palavra e reorganizaremos a estrutura da árvore com base nesses códigos. Avaliaremos se essa abordagem oferece vantagens em relação à anterior.

</div>

- **Etapa 3: Árvore AVL**

<div align="justify">

Implementaremos uma árvore AVL e repetiremos o processo de análise. Compararemos o tempo médio de processamento entre a construção da estrutura e a geração de saída em comparação com as abordagens anteriores.

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
- [✔️] Demonstrar as **palavras mais relevantes** de um conjunto de dados utilizando cada uma das estruturas acima, identificando a palavra e a frequência da palavra para cada arquivo de texto disponível.

## Experimentação 🔬

Ao concluir esta tarefa, teremos uma compreensão mais aprofundada das diferentes implementações das árvores binárias e sua influência no sistema de autocompletar e sugestões de
palavras. A análise comparativa nos permitirá avaliar a eficácia de cada abordagem em termos de desempenho e funcionalidade.

<div align="justify">
	
</div>

### Entradas de dados necessárias 🗂️

<div align="justify">

</div>

#### Diretório ./dataset/input 📂

<div align="justify">

</div>

#### Arquivo stopwords.txt 🛑

<div align="justify">

</div>

### Saídas obtidas

<div align="justify">

</div>

<div align="center">

</div>

## Análise de Complexidade 🔎

<div align="justify">
  
</div>

## Conclusão 🎯

<div align="justify">

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
| `make r`                                                                                                                                                | Realiza o `make clean`, `make` e `make run` juntos                                      |

## Comandos para Windows:

| <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/windows8/windows8-original.svg" alt="Windows Icon" width="30" height="30"> | Função                                                                                        |
| ---------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| `cmake -B ./build-debug`                                                                                                                             | Executa geração de arquivos e o resultado vai para a pasta build-debug                        |
| `cmake --build ./build-debug`                                                                                                                        | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build-debug |
| `./build-debug/app`                                                                                                                                  | Executa o programa da pasta build-debug após a realização da compilação                       |

# Contatos 📇

| Contato    | Telegram                                                                                                                                                                             | LinkedIn                                                                                                                                                                                           | GitHub                                                                                                                                                                                       |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Pedro Dias | <a href="https://t.me/phpdias"><img align="center" height="24px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> | <a href="https://linkedin.com/in/phpd"><img align="center" height="24px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/></div> | <a href="https://github.com/phpdias"><img align="center" height="24px" width="90px" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/></div> |

## Referências

[^1]: [GitHub](https://github.com/phpdias/labirinto-recorrente)
[^2]: [CppReference](https://en.cppreference.com/)
[^3]: [CPlusPlus](https://cplusplus.com/)
