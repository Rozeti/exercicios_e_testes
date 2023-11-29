#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Pessoa{
    int id;
    char nome[40];
    int idade;
    struct Pessoa *prox;
}Pessoa;

Pessoa* criarListaVazia(){
    return NULL;
}

Pessoa* criarNovaPessoa(){
    Pessoa *novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (novaPessoa == NULL){
        printf("Nao foi possivel alocar memoria");
        exit(EXIT_FAILURE);
    }
    novaPessoa->prox = NULL;
    return novaPessoa;
}

Pessoa* cadastrar(Pessoa *lista){
    Pessoa *novaPessoa = criarNovaPessoa();
    srand(time(NULL));
    novaPessoa->id = rand() % 100;
    printf("\n\nDigite o nome: ");
    fflush(stdin);
    fgets(novaPessoa->nome, sizeof(novaPessoa->nome), stdin);
    fflush(stdin);
    printf("\nDigite a idade: ");
    scanf("%d", &novaPessoa->idade);

    if (lista == NULL){
        lista = novaPessoa;
    }else{
        Pessoa *atual = lista;
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novaPessoa; 
    }
    return lista;
}

void mostrar(Pessoa *lista){
    Pessoa *atual;
    atual = lista;
    if (atual == NULL){
        printf("\n\nLista nula!!\n\n");
        return;
    } else{
        while (atual != NULL){
            printf("\nNome: %s", atual->nome);
            printf("Idade: %d", atual->idade);
            printf("\nID: %d\n\n", atual->id);
            atual = atual->prox;
        }
    }
}

Pessoa* buscar(Pessoa *lista, int idBusca){
    Pessoa *atual = lista;
    if (atual == NULL){
         printf("\n\nLista nula!!\n\n");
        return;
    } else{
        while (atual != NULL){
            if (atual->id == idBusca){
                printf("\nNome: %s", atual->nome);
                printf("Idade: %d", atual->idade);
                printf("\nID: %d\n\n", atual->id);
                return atual;
            }  
            atual = atual->prox;
        }
        printf("\nPessoa nao encontrada!\n");
        return NULL;
    }
}

void alterar(Pessoa *encontrada){
    printf("\nAlterar o nome: ");
    fgets(encontrada->nome, sizeof(encontrada->nome), stdin);
    fflush(stdin);

    printf("Alterar a Idade: ");
    scanf("%d", &encontrada->idade);
    fflush(stdin);
}

Pessoa* excluir(Pessoa *lista, int idBusca){
    Pessoa *anterior = NULL;
    Pessoa *atual = lista;
    while (atual != NULL && atual->id != idBusca){
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL){
        if (anterior != NULL){
        //excluir alguem depois do primeiro
        anterior->prox = atual->prox;
        }else {
        //excluir o primeiro
        lista = atual->prox;
        }
        free(atual);
        printf("\nPessoa excluida com sucesso\n");
    }else{
        printf("\nPessoa nao encontrada\n");
    }
    return lista;
}

void liberarLista(Pessoa *lista){
    Pessoa *atual = lista;
    Pessoa *proximaPessoa;
    while (atual != NULL){
        proximaPessoa = atual->prox;
        free(atual);
        atual = proximaPessoa;
    }
}

main(){
    Pessoa *lista = criarListaVazia();
    Pessoa *encontrada;
    int opcao, idBusca;

    do{
        printf("\nDigite 1 - Cadastrar");
        printf("\nDigite 2 - Mostrar todas as pessoas cadastradas");
        printf("\nDigite 3 - Buscar um pessoa");
        printf("\nDigite 4 - Alterar uma pessoa");
        printf("\nDigite 5 - excluir uma pessoa");
        printf("\nDigite 0 - Sair\n");
        printf("\n\n--> Sua opcao eh: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            lista = cadastrar(lista);
            break;

        case 2:
            mostrar(lista);
            break;

        case 3:
            fflush(stdin);
            printf("\n-> Digite o id para busca: ");
            scanf("%d", &idBusca);
            fflush(stdin);
            encontrada = buscar(lista, idBusca);
            break;

        case 4:
            fflush(stdin);
            printf("\n-> Digite o id para alterar: ");
            scanf("%d", &idBusca);
            fflush(stdin);
            encontrada = buscar(lista, idBusca);
            if (encontrada != NULL){
                alterar(encontrada);
            }
            break;

        case 5:
            fflush(stdin);
            printf("\n-> Digite o id para alterar: ");
            scanf("%d", &idBusca);
            fflush(stdin);
            lista = excluir(lista, idBusca);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    
    liberarLista(lista);
}
