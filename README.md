# 3 - Threads e Multithread

"Thread" é um fluxo de sequência único dentro de um processo. Como os encadeamentos têm algumas das propriedades dos processos, às vezes eles são chamados de processos leves.

## Exercício

"Escreva um programa com múltiplos threads que calcule diversos valores estatísticos para uma lista de números. Esse programa receberá uma série de números na linha de comando e, então, criará três threads de trabalho separados. Um dos threads determinará a média dos números, o segundo thread determinará o valor máximo, e o terceiro determinará o valor mínimo."

## Como usar
* Pré-Requisitos
  * editor de codigo
  * C (linguagem)
  * SO Linux
  * makefile

Compilando no terminal (sem usar o makefile) 

```bash

1. gcc "nome do arq".c -o "nome do executavel"

```
```bash

2. ./"nome do executavel"

```

Compilando no terminal (com o makefile)

```bash

1. make 
   - executa o - gcc "nome do arq".c -o "nome do executavel"

```
```bash

2. make run
   - executa o - ./"nome do executavel"

```
```bash

3. make clean
   - executa o -  rm 'nome do executável'
