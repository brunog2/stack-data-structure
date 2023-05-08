#include <stdio.h>
#include <string.h>

// 1) Um mercadinho tem uma pilha de cubas de ovos, cada uma contendo 12, 24 e 36 ovos. 
// Inicialmente, a pilha está vazia. Durante os próximos N minutos, pode ocorrer uma das situações:
// a cuba de ovos no topo da pilha é vendida ou uma nova cuba de ovos é colocada no topo da pilha.
// Determine o número de ovos vendidos após esto tempo de N minutos.

#define MAX_SIZE 100

int pop(int *pilha, int *topo) {
    int valor = pilha[*topo];
    (*topo)--;
    return valor;
}

int top(int *pilha, int topo) {
    return pilha[topo];
}

int isEmpty(int topo) {
    return topo == -1;
}

int isFull(int topo, int tamanho) {
    return topo == tamanho - 1;
}

int total_value(int pilha[], int topo) {
    int total = 0;
    for (int x = 0; x <= topo; x++) {
        total += pilha[x];
    }
    return total;
}

void print_stack(int *pilha, int topo) {
    if (topo == -1) {
        // printf("Pilha vazia.\n");
        return;
    }
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

void push(int valor, int *pilha, int *topo) {
    (*topo)++;
    pilha[*topo] = valor;
}

int main() {
    // Inicializando variável de iteração, pilha geral
    // e uma pilha para cada cuba de ovos
    // A ideia é fazer uma pilha de pilhas
    // big_stack element max size = 32
    // medium_stack element max size = 24
    // small_stack element max size = 12
    int n = 0;
    int big_stack[MAX_SIZE] = {}; 
    int medium_stack[MAX_SIZE] = {}; 
    int small_stack[MAX_SIZE] = {};
    int big_stack_top = -1;
    int medium_stack_top = -1;
    int small_stack_top = -1;
    int vendidos = 0;

    printf("Informe o tempo em minutos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEscolha uma opcao: \n");
        printf("1 - Adicionar bandeja\n");
        printf("2 - Vender ovos\n");
        
        printf("Sua escolha: ");
        int op;
        scanf("%d", &op);
        
        int top_stack;
        if (op == 1) {
            printf("Escolha o tamanho da bandeja: \n");
            
            if (small_stack_top >= 0) {
                push(12, small_stack, &small_stack_top);
                printf("Bandeja pequena adicionada\n");
            }

            else if (medium_stack_top >= 0) {
                printf("1 - Bandeja media\n");
                printf("2 - Bandeja pequena\n");
                scanf("%d", &top_stack);

                while (top_stack != 1 && top_stack != 2) {
                    printf("Opcao invalida. Por favor, escolha novamente: \n");
                    
                    printf("1 - Bandeja media\n");
                    printf("2 - Bandeja pequena\n");
                    scanf("%d", &top_stack);
                }

                if (top_stack == 1) {
                    push(24, medium_stack, &medium_stack_top);
                    printf("Opcao %d escolhida. Bandeja media adicionada\n", top_stack);
                } else {
                    push(12, small_stack, &small_stack_top);
                    printf("Opcao %d escolhida. Bandeja pequena adicionada\n", top_stack);
                }
            } 

            else {
                printf("1 - Bandeja grande\n");
                printf("2 - Bandeja media\n");
                printf("3 - Bandeja pequena\n");
                scanf("%d", &top_stack);

                while (top_stack != 1 && top_stack != 2 && top_stack != 3) {
                    printf("Opcao invalida. Por favor, escolha novamente: \n");
                    
                    printf("1 - Bandeja grande\n");
                    printf("2 - Bandeja media\n");
                    printf("3 - Bandeja pequena\n");
                    scanf("%d", &top_stack);
                }

                if (top_stack == 1) {
                    push(36, big_stack, &big_stack_top);
                    printf("Opcao %d escolhida. Bandeja grande adicionada\n", top_stack);
                } else if (top_stack == 2) {
                    push(24, medium_stack, &medium_stack_top);
                    printf("Opcao %d escolhida. Bandeja media adicionada\n", top_stack);
                } else {
                    push(12, small_stack, &small_stack_top);
                    printf("Opcao %d escolhida. Bandeja pequena adicionada\n", top_stack);
                }
            } 
            
        } else {
            int qt;
            printf("Informe a quantidade de ovos a serem vendidos: ");
            scanf("%d", &qt);
            int small_stack_total = total_value(small_stack, small_stack_top);
            int medium_stack_total = total_value(medium_stack, medium_stack_top);
            int big_stack_total = total_value(big_stack, big_stack_top);
            int total_quantity = small_stack_total + medium_stack_total + big_stack_total;

            if (qt > total_quantity) {
                printf("A quantidade de ovos a serem vendidos e maior que a quantidade de ovos disponíveis.\n");
            }
            else {
                if (small_stack_top >= 0 && qt > 0) {
                    printf("Tirando da bandeja pequena \n");
                    for (int x = small_stack_top; x >= 0; x--) {
                        if (qt > small_stack[x]) {
                            qt -= small_stack[x];
                            vendidos += small_stack[x];
                            small_stack[x] = 0;
                        } else {
                            vendidos += qt;
                            small_stack[x] -= qt;
                            break;
                        }
                    }
                }

                if (medium_stack_top >= 0 && qt > 0) {
                    printf("Tirando da bandeja media \n");
                    for (int x = medium_stack_top; x >= 0; x--) {
                        if (qt > medium_stack[x]) {
                            qt -= medium_stack[x];
                            vendidos += small_stack[x];
                            medium_stack[x] = 0;
                        } else {
                            vendidos += qt;
                            medium_stack[x] -= qt;
                            break;
                        }
                    }
                }

                if (big_stack_top >= 0 && qt > 0) {
                    printf("\nTirando da bandeja grande \n");
                    for (int x = big_stack_top; x >= 0; x--) {
                        if (qt >= big_stack[x]) {
                            printf("Primeiro if \n");
                            qt -= big_stack[x];
                            vendidos += small_stack[x];
                            big_stack[x] = 0;
                        } else {
                            printf("else \n");
                            vendidos += qt;
                            big_stack[x] -= qt;
                            break;
                        }
                    }
                }

                if (qt <= 0) {
                    printf("Nenhum ovo vendido\n");
                }
            }
        }
    
        printf("\nBandejas grandes: \n");
        print_stack(big_stack, big_stack_top);
        printf("Bandejas medias: \n");
        print_stack(medium_stack, medium_stack_top);
        printf("Bandejas pequenas: \n");
        print_stack(small_stack, small_stack_top);
    }

    printf("\nBandejas vendidas %d\n", vendidos);

    return 0;
}