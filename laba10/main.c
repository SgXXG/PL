#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "string.h"
#include "time.h"
#define ll long long
#define MAX_N 1024
#define COUNT 5
#define SURNAME_LEN 10
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int pr[256];
struct Node {
    struct Node* l ;
    struct Node* r ;
    char val;
};

typedef struct Node Node;

char isOperation(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*'
            || c == '/' || c == '^');
}

void solve(char* s, int len, Node* v) {
    if (v) {
        v->l = NULL;
        v->r = NULL;
        v->val = '!';
    }
    if (len == 0)
        return;
    if (s[0] == '(' && s[len - 1] == ')') {
        s[len - 1] = '\0';
        return solve(s + 1, len - 2, v);
    }
    if (len == 1) {
        v->val = s[0];
        return;
    }
    int pos = -1;
    int mP = INT_MAX;
    int rank = 0;
    for (int i = len - 1; i >= 0; i--) {
        char ch = s[i];
        if (ch == '(')
            rank++;
        if (ch == ')')
            rank--;
        if (isOperation(ch) && pr[ch] < mP && rank == 0) {
            mP = pr[ch];
            pos = i;
        }
    }
    v->val = s[pos];
    s[pos] = 0;

    char lS[MAX_N];
    strcpy(lS, s + pos + 1);
    int lLen = strlen(lS);

    char rS[MAX_N];
    strcpy(rS, s);
    int rLen = strlen(rS);

    if (lLen != 0) {
        v->l = (Node*)malloc(sizeof(Node));
        solve(lS, lLen, v->l);
    }
    if (rLen != 0) {
        v->r = (Node*)malloc(sizeof(Node));
        solve(rS, rLen, v->r);
    }
}

void output(Node* v) {
    if (!v)
        return;
    if (v->r)
        output(v->r);
    if (v->l)
        output(v->l);
    printf("%c", v->val);
}

void printTree(Node* node, int tab) {
    if (node == NULL) return;
    else {
        printTree(node->l, ++tab);
        for (int i = 0; i < tab; i++) printf("    ");
        printf("%c\n", node->val);
        tab--;
    }
    printTree(node->r, ++tab);
}

void printTree1(Node* treePtr, int p)
{
    int i;
    if (treePtr != NULL)
    {
        printTree(treePtr->r, p + 3);
        for (i = 0; i < p; i++)
        {
            printf(" ");
        }
        printf("%c\n", treePtr->val);
        printTree(treePtr->l, p + 3);
    }
}

/* Help procedure for printing binary tree */
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root -> l, space);

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root -> val);

    // Process left child
    print2DUtil(root -> r, space);
}

/* Print binary tree */
void print2D(struct Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 1);
}


int main() {
    pr['+'] = pr['-'] = 1;
    pr['*'] = pr['/'] = 2;
    pr['^'] = 3;
    srand(time(NULL));

    char inp[MAX_N] = "f*(d+g*h)/c-t-j";

    Node* tr = (Node*)malloc(sizeof(Node));
    solve(inp, strlen(inp), tr);
    output(tr);
    printf("\n\n");
    print2D(tr);
    //printTree(tr, 10);

    getchar();
    return 0;
}