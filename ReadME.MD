Este projeto é um sistema simples de controle de produtos feito em C para a disciplina.
O objetivo é treinar o uso de structs, vetores, strings, funções e leitura de arquivos.

O programa lê os produtos do arquivo produtos.txt no início da execução.
Cada produto tem código, nome, preço e quantidade.
Depois disso, o usuário pode usar um menu para visualizar e manipular os dados.

Como compilar

Depois de instalar o GCC (MinGW/MSYS2), basta abrir o terminal dentro da pasta do projeto e usar:

gcc main.c -o sistema

Isso gera o executável sistema.exe.

Como executar

No terminal:

./sistema


O menu aparece e as opções são:

-. → adicionar produto

/. → buscar produto por código

0 → imprimir todos os produtos

1 → ordenar por preço

3 → sair

Também é possível digitar apenas os números das opções.

Arquivo produtos.txt

O arquivo precisa estar na mesma pasta do código.
Cada linha tem o formato:

codigo nome preco quantidade


Exemplo:

101 Arroz 5.49 20


O arquivo usado no trabalho tem 20 produtos.

Sobre o projeto

O programa não escreve de volta no arquivo.
As alterações valem somente enquanto o programa está aberto.
A estrutura foi feita de forma simples, usando funções separadas para facilitar a leitura e a explicação em sala.