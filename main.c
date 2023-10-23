#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 // Defina o número máximo de tarefas

// Estrutura para representar uma tarefa
struct Task {
    char description[100];
    int completed;
    char dueDate[20]; // Adicionar uma data de vencimento para a tarefa (formato de string)
    int priority;    // Adicionar um campo de prioridade para a tarefa
    double estimatedTime; // Adicionar o tempo estimado necessário para concluir a tarefa (em horas)
    char assignee[50];    // Adicionar um campo para o nome da pessoa responsável pela tarefa
};

// Função para adicionar uma nova tarefa à lista
void addTask(struct Task tasks[], int *taskCount, char description[], char dueDate[], int priority, double estimatedTime, char assignee[]) {
    if (*taskCount < MAX_TASKS) {
        struct Task newTask;
        strcpy(newTask.description, description);
        newTask.completed = 0; // Inicialmente, a tarefa não está completa
        strcpy(newTask.dueDate, dueDate);
        newTask.priority = priority;
        newTask.estimatedTime = estimatedTime;
        strcpy(newTask.assignee, assignee);
        tasks[*taskCount] = newTask;
        (*taskCount)++;
        printf("Tarefa adicionada com sucesso.\n");
    } else {
        printf("A lista de tarefas está cheia.\n");
    }
}

// Função para listar todas as tarefas
void listTasks(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("A lista de tarefas está vazia.\n");
    } else {
        printf("Lista de tarefas:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s %s\n", i + 1, tasks[i].description, tasks[i].completed ? "(Concluída)" : "");
        }
    }
}

// Função para visualizar uma tarefa específica
void viewTask(struct Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskCount) {
        struct Task task = tasks[taskIndex];
        printf("Detalhes da Tarefa %d:\n", taskIndex + 1);
        printf("Descrição: %s\n", task.description);
        printf("Data de Vencimento: %s\n", task.dueDate);
        printf("Prioridade: %d\n", task.priority);
        printf("Tempo Estimado (horas): %.2lf\n", task.estimatedTime);
        printf("Responsável: %s\n", task.assignee);
    } else {
        printf("Índice de tarefa inválido.\n");
    }
}

// Função para editar uma tarefa existente
void editTask(struct Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskCount) {
        struct Task *task = &tasks[taskIndex];
        printf("Editando Tarefa %d:\n", taskIndex + 1);
        printf("Nova descrição: ");
        scanf(" %[^\n]", task->description);
        printf("Nova data de vencimento (dd/mm/aaaa): ");
        scanf(" %[^\n]", task->dueDate);
        printf("Nova prioridade (1 - baixa, 2 - média, 3 - alta): ");
        scanf("%d", &task->priority);
        printf("Novo tempo estimado (em horas): ");
        scanf("%lf", &task->estimatedTime);
        printf("Novo responsável: ");
        scanf(" %[^\n]", task->assignee);
        printf("Tarefa editada com sucesso.\n");
    } else {
        printf("Índice de tarefa inválido.\n");
    }
}

// Função para marcar uma tarefa como concluída
void completeTask(struct Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskCount) {
        tasks[taskIndex].completed = 1;
        printf("Tarefa marcada como concluída.\n");
    } else {
        printf("Índice de tarefa inválido.\n");
    }
}

// Função para apagar todas as tarefas da lista
void clearTasks(struct Task tasks[], int *taskCount) {
    *taskCount = 0;
    printf("Todas as tarefas foram apagadas.\n");
}

// Função para apagar uma tarefa da lista
void deleteTask(struct Task tasks[], int *taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < *taskCount) {
        for (int i = taskIndex; i < *taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        (*taskCount)--;
        printf("Tarefa apagada com sucesso.\n");
    } else {
        printf("Índice de tarefa inválido.\n");
    }
}

// Função principal
int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;

    int choice;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Marcar tarefa como concluída\n");
        printf("4. Visualizar tarefa\n");
        printf("5. Editar tarefa\n");
        printf("6. Apagar uma tarefa\n");
        printf("7. Apagar todas as tarefas\n");
        printf("8. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a descrição da tarefa: ");
                char description[100];
                scanf(" %[^\n]", description);
                printf("Digite a data de vencimento da tarefa (dd/mm/aaaa): ");
                char dueDate[20];
                scanf(" %[^\n]", dueDate);
                printf("Digite a prioridade da tarefa (1 - baixa, 2 - média, 3 - alta): ");
                int priority;
                scanf("%d", &priority);
                printf("Digite o tempo estimado necessário para concluir a tarefa (em horas): ");
                double estimatedTime;
                scanf("%lf", &estimatedTime);
                printf("Digite o nome do responsável pela tarefa: ");
                char assignee[50];
                scanf(" %[^\n]", assignee);
                addTask(tasks, &taskCount, description, dueDate, priority, estimatedTime, assignee);
                break;
            case 2:
                listTasks(tasks, taskCount);
                break;
            case 3:
                printf("Digite o índice da tarefa a ser marcada como concluída: ");
                int taskIndex;
                scanf("%d", &taskIndex);
                completeTask(tasks, taskCount, taskIndex - 1);
                break;
            case 4:
                printf("Digite o índice da tarefa a ser visualizada: ");
                int viewIndex;
                scanf("%d", &viewIndex);
                viewTask(tasks, taskCount, viewIndex - 1);
                break;
            case 5:
                printf("Digite o índice da tarefa a ser editada: ");
                int editIndex;
                scanf("%d", &editIndex);
                editTask(tasks, taskCount, editIndex - 1);
                break;
            case 6:
                printf("Digite o índice da tarefa a ser apagada: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                deleteTask(tasks, &taskCount, deleteIndex - 1);
                break;
            case 7:
                clearTasks(tasks, &taskCount);
                break;
            case 8:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (choice != 8);

    return 0;
}
