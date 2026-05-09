# Astronautas 

Repositório contendo arquivos da primeira atividade avaliativa da disciplina Linguagem de Programação I.

## Estrutura do Repositório

O repositório apresenta a seguinte estrutura: 
- `include/`: contém os arquivos de cabeçalho do projeto;
- `src/`: contém a implementação das funções declaradas nos arquivos de cabeçalho; 
- arquivo `main.cpp`: arquivo principal. 
- arquivo `arquivo.txt`: contém um exemplo de entrada para testes.  
Além dos arquivos `.gitignore` e `README.md`.
  
## Como compilar    

### No Windows, utilizando o PowerShell

`g++ src\*.cpp -Iinclude -o sistema.exe`  

Executar:  

`Get-Content .\arquivo.txt | .\sistema.exe`    

Mas você pode substituir `arquivo.txt` pelo nome do seu arquivo de testes.  

### No Linux

`g++ src\*.cpp -Iinclude -o sistema`  

Executar:  

`./sistema < arquivo.txt`


## Requisitos 

- g++ 

--- 

> Lorenna Mirely de Sousa Silva 
