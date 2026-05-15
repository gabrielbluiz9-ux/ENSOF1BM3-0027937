// Projeto feito por Gabriel 

#include <stdio.h>
#include <string.h>

#define MAX 100

// ESTRUTURA DO CLIENTE
struct Cliente {
    int id;
    char nome[50];
    char telefone[20];
};

int main() {
    struct Cliente clientes[MAX];
    int total = 0;
    int opcao = 0;

    while (opcao != 5) {
        printf("\n===== SISTEMA DE CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Remover cliente\n");
        printf("5 - Sair\n");
        printf("\n---------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        // CADASTRAR
        if (opcao == 1) {
            if (total < MAX) {
                clientes[total].id = total + 1;

                printf("\n--- CADASTRO ---\n");
                printf("Nome: ");
                fgets(clientes[total].nome, 50, stdin);
                clientes[total].nome[strcspn(clientes[total].nome, "\n")] = '\0';

                printf("Telefone: ");
                fgets(clientes[total].telefone, 20, stdin);
                clientes[total].telefone[strcspn(clientes[total].telefone, "\n")] = '\0';

                total++;
                printf("Cliente cadastrado com sucesso!\n");
            } else {
                printf("Limite de clientes atingido!\n");
            }
            printf("\n---------------------\n");
        }

        // LISTAR
        else if (opcao ==2){
            if (total == 0){
                printf("Nenhum cliente cadastrado.\n");
            } else {
                printf("\n--- LISTA DE CLIENTES ---\n");
                for (int i = 0; i < total; i++){
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                }
            }
            printf("\n---------------------\n");
        }

        // BUSCAR
        else if (opcao == 3) {
            char nomeBusca[50];
            int encontrado = 0;
            printf("\n--- BUSCA DE CLIENTE ---\n");
            printf("Digite o nome do cliente para buscar: ");
            fgets(nomeBusca, 50, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

            for (int i = 0; i < total; i++) {
                if (strcmp(clientes[i].nome, nomeBusca) == 0) {
                    printf("Cliente Encontrado!\n");
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Cliente não encontrado\n");
            }
            printf("\n---------------------\n");
        }

        // DELETAR CLIENTE
        else if (opcao == 4) {
            int idEx;
            int enc = 0;
            printf("\n--- REMOÇÃO DE CLIENTE ---\n");
            printf("Digite o ID do cliente que será removido: ");
            scanf("%d", &idEx);
            getchar();
            
            for (int i = 0; i < total; i++) {
                if (clientes[i].id == idEx) {
                    enc = 1;
                    for (int s = i; s < total - 1; s++) {
                        clientes[s] = clientes[s + 1];
                    }
                    total--;
                    for (int u = 0; u < total; u++) {
                        clientes[u].id = u + 1;
                    }
                    printf("Cliente removido!\n");
                    break;
                }
            }
            if (!enc) {
                printf("Cliente não encontrado!\n");
            }
            printf("\n---------------------\n");
        }

        // OPÇÃO INVÁLIDA
        else if (opcao != 5) {
            printf("Opcao invalida!\n");
        }
    }
    printf("\n---------------------\n");
    printf("Encerrando sistema...\n");
    return 0;
}
