# Backpack Royale – Sistema de Mochila do Jogador em C
*(Projeto acadêmico – ADS, inspirado em Free Fire)*

## 📌 Sobre o projeto
O **Backpack Royale** é um projeto desenvolvido em linguagem C como atividade da faculdade de **Análise e Desenvolvimento de Sistemas (ADS)**.  
O objetivo é aplicar, na prática, conceitos fundamentais de **estruturas de dados e algoritmos**, simulando o sistema de inventário (“mochila”) de um jogador e, na etapa final, a gestão de componentes críticos de uma torre de resgate.

O projeto foi construído de forma **progressiva em três partes**, permitindo comparar abordagens, estruturas e algoritmos conforme a complexidade do sistema aumenta.

---

## 🧩 Estrutura do projeto

### 🔹 Parte 1 – Fundamentos e Vetores
Implementação inicial do sistema de mochila utilizando **vetores estáticos**.

**Funcionalidades:**
- Cadastro de itens  
- Remoção de itens  
- Listagem de itens  
- Busca sequencial por nome  

**Conceitos aplicados:**
- `struct`  
- Arrays estáticos  
- Funções  
- Entrada e saída de dados no terminal  

---

### 🔹 Parte 2 – Estruturas de Dados e Buscas
Expansão do sistema para permitir comparação entre **vetor** e **lista encadeada**.

**Funcionalidades:**
- CRUD de itens em vetor  
- CRUD de itens em lista encadeada  
- Busca sequencial (vetor e lista)  
- Busca binária (vetor ordenado)  
- Ordenação por nome  
- Contagem de comparações  

**Conceitos aplicados:**
- Listas encadeadas  
- Alocação dinâmica (`malloc` e `free`)  
- Comparação de estruturas de dados  
- Análise prática de custo de busca  

---

### 🔹 Parte 3 – Algoritmos de Ordenação e Performance
Simulação de um “desafio final” com gerenciamento de componentes da torre de resgate.

**Funcionalidades:**
- Ordenação por nome (Bubble Sort)  
- Ordenação por tipo (Insertion Sort)  
- Ordenação por prioridade (Selection Sort)  
- Medição de tempo de execução  
- Busca binária por nome  

**Conceitos aplicados:**
- Algoritmos de ordenação  
- Medição de performance (`clock()`)  
- Comparação prática entre algoritmos  
- Organização e evolução de código  

---

## 📊 Objetivo técnico do projeto
Mais do que implementar funcionalidades, o foco do projeto foi **avaliar decisões técnicas e impacto em performance**, comparando:

- Vetor vs. lista encadeada  
- Busca sequencial vs. busca binária  
- Diferença de comportamento entre algoritmos de ordenação  
- Impacto da ordenação prévia na eficiência das buscas  

A evolução entre as versões representa a transição de um código funcional para um código mais **estruturado, eficiente e sustentável**.
