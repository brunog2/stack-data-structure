#include <stdio.h>
#include <string.h>

// 1) Um mercadinho tem uma pilha de cubas de ovos, cada uma contendo 12, 24 e 36 ovos. 
// Inicialmente, a pilha está vazia. Durante os próximos N minutos, pode ocorrer uma das situações:
// a cuba de ovos no topo da pilha é vendida ou uma nova cuba de ovos é colocada no topo da pilha.
// Determine o número de ovos vendidos após esto tempo de N minutos.

#define MAX_SIZE 100

void push(int valor, int *pilha, int *topo) {
    (*topo)++;
    pilha[*topo] = valor;
}

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

void printStack(int stack[MAX_SIZE][3], int top, int big_stack_top, int medium_stack_top, int small_stack_top) {
    if (top > 0) {
        for (int x = big_stack_top; x > 0; x--) {
            printf("%d ", stack[0][x]);            
        }
        printf("\n");        
    }
    
    if (top > 1) {
        for (int y = medium_stack_top; y > 0; y--) {
            printf("%d ", stack[1][y]);            
        }
        printf("\n");
    }

    if (top > 2) {
        for (int z = medium_stack_top; z > 0; z--) {
            printf("%d ", stack[2][z]);            
        }
        printf("\n");
    }
}

int main() {
    // Inicializando variável de iteração, pilha geral
    // e uma pilha para cada cuba de ovos
    // A ideia é fazer uma pilha de pilhas
    // big_stack element max size = 32
    // medium_stack element max size = 24
    // small_stack element max size = 12
    int n = 0;
    int stack[MAX_SIZE][3]; 
    int big_stack[MAX_SIZE]; 
    int medium_stack[MAX_SIZE]; 
    int small_stack[MAX_SIZE];
    int stack_top = -1;
    int big_stack_top = -1;
    int medium_stack_top = -1;
    int small_stack_top = -1;

    printf("Informe o tempo em minutos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Pilha atual: \n");
        printStack(stack, stack_top, big_stack_top, medium_stack_top, small_stack_top);
        
        printf("Escolha uma opção: \n");
        printf("1 - Adicionar bandeja\n");
        printf("2 - Remover bandeja\n");
        
        printf("Sua escolha: ");
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int* general_stack_top = stack[stack_top];
            if (memcmp(general_stack_top, big_stack, sizeof(general_stack_top))) {
                
            } 
            else if (memcmp(general_stack_top, medium_stack, sizeof(general_stack_top))) {

            } 
            else if (memcmp(general_stack_top, small_stack, sizeof(general_stack_top))) {
            
            }
        } else {

        }
    
    }

    return 0;
}