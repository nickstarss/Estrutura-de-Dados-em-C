#include <stdio.h>  
#include <string.h> //para uso de strings em C, por ter particularidades
#include <stdlib.h> //para uso do system("cls") e system("pause")

#define MAX_TERRITORIOS 5

struct Territorio {
  char nome[30];
  char cor[10];
  int tropas;
};

void limparBufferEntrada() {
  int c;
  while((c= getchar()) != '\n' && c != EOF);
}

int main(){
  struct Territorio territorios[MAX_TERRITORIOS];
  int totalTerritorios = 0;
  int opcao;

  do{
    printf("-------------------------------------\n");
    printf("---------- JOGO DE WAR --------------\n");
    printf("-------------------------------------\n\n");
    printf("1. Cadastrar Territorios\n");
    printf("2. Exibir Territorios\n");
    printf("0. Sair do Sistema\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    limparBufferEntrada();

    //Processa a opcao inserida pelo usuario

    switch (opcao){
    case 1:
      printf("-------------------------------------\n");
      printf("---- Cadastrar um novo territorio ---\n");
      printf("-------------------------------------\n");

      if (totalTerritorios < MAX_TERRITORIOS)
      {
        printf("Nome do territorio: ");
        fgets(territorios[totalTerritorios].nome, 30, stdin);
        territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = 0;

        printf("Cor do territorio: ");
        fgets(territorios[totalTerritorios].cor, 10, stdin);
        territorios[totalTerritorios].cor[strcspn(territorios[totalTerritorios].cor, "\n")] = 0;

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[totalTerritorios].tropas);

        limparBufferEntrada();
        totalTerritorios++;

        printf("\n\n-------------------------------------\n");
        printf("Territorio cadastrado com sucesso!");
      } else {
        printf("Limite de territorios atingido. Nao e possivel cadastrar mais territorios.");
      }
      
      break;
    case 2:
      printf("-------------------------------------\n");
      printf("-------- Lista de territorios -------\n");
      printf("-------------------------------------\n");

      if (totalTerritorios == 0)
      {
        printf("Nenhum territorio cadastrado.\n");
      } else {
        for(int i = 0; i < totalTerritorios; i++) {
          printf("-------------------------\n");
          printf("Territorio %d:\n", i + 1);
          printf("Nome: %s\n", territorios[i].nome);
          printf("Cor: %s\n", territorios[i].cor);
          printf("Quantidade de tropas: %d\n", territorios[i].tropas);
          printf("-------------------------\n");
        }

        printf("Pressione Enter para continuar...");
        getchar();
      }
      break;
    
    case 0:
      printf("Saindo do sistema...\n");
      break;
      
    default:
        printf("Opcao invalida. Tente novamente.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        break;
    }
  } while(opcao != 0);

  return 0;
}