#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

/* Binary tree */
typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
} node;

/* queue node */
typedef struct node {
    const void*  ptr;
    struct node* next;
} node_t;

/* queue */
typedef struct {
    node_t* head;
    node_t* tail;
} queue_t;

/* Procedures for queue */
void  queue_init(queue_t* q){
    q->head =NULL;
    q->tail = NULL;
}
int queue_push(queue_t* q, const void* ptr){
    node_t* p = (node_t*)malloc(sizeof(node_t));
    if(p != NULL){
        p->ptr  = ptr;
        p->next = NULL;
        if(q->head == NULL)
            q->head = q->tail = p;
        else {
            q->tail->next = p;
            q->tail = p;
        }
    }
    return (p != NULL);
}
void queue_pop(queue_t* q){
    node_t* t;
    if(q->head != NULL){
        t       = q->head;
        q->head = q->head->next;
        free(t);
        if(q->head == NULL)
            q->tail = NULL;
    }
}
const void* queue_front(queue_t* q) {
    return q->head->ptr;
}
int queue_empty(queue_t* q) {
    return (q->head == NULL);
}

/* Create new node in binary tree */
node *newNode(int data)
{
    node* newNode = malloc(sizeof(node));

    newNode->key   = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Wide out for the binary tree */
void tree_out_width(const node* tr){
    const node* p;
    queue_t q;
    queue_init(&q);
    int count = 0;

    queue_push(&q, tr);
    while(! queue_empty(&q)){
        p = (const node*)queue_front(&q);
        queue_pop(&q);

        if (p->left != NULL && p->right != NULL)
            count++;

        if(p->left != NULL)
            queue_push(&q, p->left);
        if(p->right != NULL)
            queue_push(&q, p->right);
    }

    printf("2 children has %d nodes\n", count);
}

/* Help procedure for printing binary tree */
void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root -> right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root -> key);

    // Process left child
    print2DUtil(root -> left, space);
}

/* Print binary tree */
void print2D(struct Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void main ()
{
    /* first level */
    node *root  = newNode(1);

    /* Second level */
    root->left  = newNode(2);
    root->right = newNode(3);

    /* Third level */
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    /* Fourth level */
    root->left->left->left       = newNode(8);
    root->left->left->right      = newNode(9);
    root->left->right->left      = newNode(10);
    root->left->right->right     = newNode(11);
    root->right->left->left      = newNode(12);
    root->right->left->right     = newNode(13);
    root->right->right->left     = newNode(14);
    root->right->right->right    = newNode(15);

    /* Fifth level */
    root->left->left->left->left = newNode(16);

    /* Wide out for the tree */
    tree_out_width(root);

    /* Print binary tree */
    print2D(root);

    /* Waiting */
    getchar();
}
