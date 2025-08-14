//Sistema de Biblioteca - Parte 1
//Objetvo: Implementar o cadastro e a listagem de livros usando um array estático.
//Foco em structs, entrada/saída e manipulação básica de arrays.

#include <stdio.h>  
#include <string.h> //para uso de strings em C, por ter particularidades
#include <stdlib.h> //para uso do system("cls") e system("pause")

//Constantes Globais

#define MAX_LIVROS 100
#define TAM_STRING 100

struct Livro{
  char nome[TAM_STRING];
  char autor[TAM_STRING];
  char editora[TAM_STRING];
  int edicao;
};

void limparBufferEntrada() {
  int c;
  while((c= getchar()) != '\n' && c != EOF);
}

int main(){
  struct Livro biblioteca[MAX_LIVROS];
  int totalLivros = 0;
  int opcao;
  do {
    printf("Sistema de Biblioteca\n");
    printf("1. Cadastrar novo livro\n");
    printf("2. Listar Livros\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");

    //Le a opção do usuário
    scanf("%d", &opcao);
    limparBufferEntrada(); //Limpa o buffer de entrada por conta de possiveis erros

    //Processa a opção escolhida
    switch(opcao) {
      case 1:
        printf("Cadastrar novo livro\n\n");

        if(totalLivros < MAX_LIVROS){
          printf("Digite o nome do livro: ");
          fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
          
          biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = 0; // Remove a nova linha

          printf("Digite o autor do livro: ");
          fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

          biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0;

          printf("Digite a editora do livro: ");
          fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

          biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = 0;

          printf("Digite a edição do livro: ");
          scanf("%d", &biblioteca[totalLivros].edicao);

          limparBufferEntrada();
          totalLivros++;

          printf("Livro cadastrado com sucesso!\n");
        } else {
          printf("Limite de livros atingido. Não é possível cadastrar mais livros.\n");
        }
        break;
      case 2:
        printf("-------- Lista de Livros Cadastrados --------\n");

        if(totalLivros == 0) {
          printf("Nenhum livro cadastrado.\n");
          break;
        } else {
          for(int i = 0; i < totalLivros; i++) {
            printf("Livro %d:\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
            printf("-------------------------\n");
          }
        }

        printf("Pressione Enter para continuar...");
        getchar();
        break;

      case 0:
        printf("Saindo do sistema...\n");
        break;

      default:
        printf("Opção inválida. Tente novamente.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        break;
    }
  } while(opcao != 0);

  return 0;
}



