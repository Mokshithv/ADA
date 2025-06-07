#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;
int vertices;

void push(int v) {
    if (top >= MAX - 1) {
        printf("Stack overflow! Too many vertices.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = v;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow! No more elements to pop.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(v);
}

void topologicalSort() {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    vertices = 6;

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort();

    return 0;
}
