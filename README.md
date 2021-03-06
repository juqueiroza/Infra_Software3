# 3 - Threads e Multithread

"Thread" é um fluxo de sequência único dentro de um processo. Como os encadeamentos têm algumas das propriedades dos processos, às vezes eles são chamados de processos leves.

## Exercício

"Escreva um programa com múltiplos threads que calcule diversos valores estatísticos para uma lista de números. Esse programa receberá uma série de números na linha de comando e, então, criará três threads de trabalho separados. Um dos threads determinará a média dos números, o segundo thread determinará o valor máximo, e o terceiro determinará o valor mínimo."

## Como funciona 

```bash

Uma thread é criada na main
 -> usando pthread_create()
 
Essa thread recebe o tamanho do array & os números

Dentro dessa thread princípal mais 3 threads são criadas (th_max_num, th_min_num, th_avg_num)
   -> a th_max_num determina o maior numero do array
   -> a th_min_num determina o menor numero do array
   -> a th_avg_num determina a media dos numeros do array 
  
 No final a thread principal imprime os resultados 
    ex: "The average value is X"
        "The minimum value is Y"
        "The maximum value is Z"

```

## Como usar
** Pré-Requisitos
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
