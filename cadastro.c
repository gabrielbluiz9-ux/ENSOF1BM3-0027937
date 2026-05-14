#include <stdio.h>
#include <string.h>

#define MAX 100

/// Estrutura do cliente
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
        printf("4 - Deletar cliente\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
        
        printf("Entrada invalida!\n");

        while (getchar() != '\n');

        continue;
}

        while (getchar() != '\n');

        // CADASTRAR CLIENTE
        if (opcao == 1) {
            if (total < MAX) {
                clientes[total].id = total + 1;

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
        }

        // LISTAR CLIENTES
        else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum cliente cadastrado.\n");
            } else {
                printf("\n===== LISTA DE CLIENTES =====\n");
                for (int i = 0; i < total; i++) {
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    printf("-----------------------------\n");
                }
            }
        }

        // BUSCAR CLIENTE
        else if (opcao == 3) {
            char nomeBuscar[50];
            int encontrado = 0;

            printf("Digite o nome do cliente: ");
            fgets(nomeBuscar, 50, stdin);
            nomeBuscar[strcspn(nomeBuscar, "\n")] = '\0';

            for (int i = 0; i < total; i++) {
                if (strcmp(clientes[i].nome, nomeBuscar) == 0) {
                    printf("\nCliente encontrado!\n");
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    encontrado = 1;
                }
            }

            if (!encontrado) {
                printf("Cliente nao encontrado!\n");
            }
        }

        // DELETAR CLIENTE
        else if (opcao == 4) {
           char nomeExcluir[50];
           int encontrado = -1;

        printf("Digite o nome do cliente para deletar: ");
        fgets(nomeExcluir, 50, stdin);
        nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0';

        // procura cliente
        for (int i = 0; i < total; i++) {
         if (strcmp(clientes[i].nome, nomeExcluir) == 0) {
            encontrado = i;
            break;
        }
    }

    // se encontrou
    if (encontrado != -1) {

        // move os elementos
        for (int i = encontrado; i < total - 1; i++) {
            clientes[i] = clientes[i + 1];
        }

        total--;

        // reorganiza IDs
        for (int i = 0; i < total; i++) {
            clientes[i].id = i + 1;
        }

        printf("Cliente deletado com sucesso!\n");

    } else {
        printf("Cliente nao encontrado!\n");
    }
}

        // OPÇÃO INVÁLIDA
        else if (opcao != 5) {
            printf("Opcao invalida!\n");
        }
    }

    printf("Encerrando sistema...\n");

    return 0;
}
