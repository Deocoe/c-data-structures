# C Data Structures Lab 🚀

<p align="left">
  <b>🇧🇷 Leia em Português</b> |
  <a href="./README.md">🇺🇸 Read in English</a>
</p>

---

Este repositório contém uma coleção de estruturas de dados clássicas implementadas em **C11**, desenvolvidas com foco em gerenciamento manual de memória, performance e princípios de *Clean Code*.

O objetivo deste projeto é servir como uma biblioteca de referência de alta qualidade e demonstrar conceitos fundamentais de Ciência da Computação aplicados em baixo nível.

## 📦 Estruturas Implementadas

### 1. Vetor Dinâmico (Dynamic Vector)
Uma implementação de array redimensionável que gerencia automaticamente sua própria capacidade.

**Principais Funcionalidades:**
* **Fator de Crescimento de 1.5x:** Estratégia otimizada para equilibrar a fragmentação de memória e o custo de realocação.
* **Gerenciamento Inteligente de Memória:** Inclui a função `vector_fit_memory` para reduzir a capacidade ao tamanho exato dos dados, eliminando desperdícios de memória.
* **Segurança (Range Checking):** Validação rigorosa de limites em todas as operações de acesso, atualização e remoção para prevenir corrupção de memória.
* **Lógica de Deslocamento (Shifting):** Implementação robusta de deslocamento de elementos para inserções e remoções em qualquer índice.



---

## 🛠️ Decisões Técnicas e Clean Code

* **Encapsulamento:** Uso de funções `static` para lógica interna, mantendo a API pública limpa e protegida.
* **Tipagem Moderna:** Utilização de `stdbool.h` para retornos lógicos e `size_t` para garantir portabilidade entre arquiteturas de 32 e 64 bits.
* **Tratamento de Erros:** Mensagens de erro descritivas via `stderr` e programação defensiva para prevenir *Segmentation Faults*.
* **Performance:** Oferece complexidade de tempo O(1) para operações de acesso e atualização.

---

## 🏗️ Compilação e Execução

Este projeto utiliza o **CMake** para o gerenciamento da compilação.

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/Deocoe/c-data-structures.git](https://github.com/Deocoe/c-data-structures.git)
   cd c-data-structures