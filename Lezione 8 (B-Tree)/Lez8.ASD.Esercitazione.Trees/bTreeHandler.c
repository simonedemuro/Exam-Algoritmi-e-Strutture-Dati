//
// Created by SimonD on 5/8/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTreeHandler.h"


/* -------------------------------
 Funzioni gia' implementate (NON MODIFICARE):
 ------------------------------- */
Birra acquisisci_birra()
{
    Birra b;
    getchar();

    printf("nome: ");
    scanf("%[^\n]s", b.nome);
    getchar();

    printf("gradi: ");
    scanf("%f", &b.gradi);

    printf("bottiglie: ");
    scanf("%d", &b.bottiglie);

    return b;
}

void stampa_birra(Birra b)
{
    printf("--------------------- \n");
    printf("nome:  %s \n", b.nome);
    printf("gradi: %.1f \n", b.gradi);
    printf("bottiglie: %d \n", b.bottiglie);
    printf("--------------------- \n");
}

Nodo* crea_nodo(Birra b)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node != NULL)
    {
        new_node->key = b;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

Nodo* carica_test()
{
    Nodo *root = NULL;
    int i;
    Birra elenco[NUM_TEST] = {{"Ichnusa", 4.7, 3}, {"Founders", 5.7, 15}, {"Peroni", 4.7, 2},
                              {"San Miguel", 3.2, 4}, {"Miller", 4.7, 7}, {"Guinnes", 4.2, 1},
                              {"Best Brau", 4.7, 12}, {"Barley", 5.0, 7}, {"Chouffe", 8.0, 12},
                              {"Franziskaner", 5, 10}, {"Heineken", 5.0, 7}, {"Kwak", 8.0, 14},
                              {"Paulaner", 5.5, 10}, {"Rubiu", 4.5, 10}, {"Tuborg", 5.0, 3}};


    for(i = 0; i < NUM_TEST; i++)
    {
        Nodo *new_birra = crea_nodo(elenco[i]);
        root = insert_nodo(root, new_birra);
    }

    return root;
}


/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node)
{
    Nodo* y = NULL;
    Nodo* x = root;

    // Searching for a path, from the root until a leaf.
    while(x != NULL){
        y = x;
        if(strcmp(new_node->key.nome, x->key.nome) < 0){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    if(y==NULL){
        root = new_node;
    } else if (strcmp(new_node->key.nome,y->key.nome)<0){
        y->left = new_node;
        new_node->parent = y;
    } else{
        y->right = new_node;
        new_node->parent = y;
    }
    return root;
}

void inorder(Nodo* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    stampa_birra(root->key);
    inorder(root->right);
}

void preorder(Nodo* root)
{
    if (root == NULL)
        return;
    stampa_birra(root->key);

    preorder(root->left);
    preorder(root->right);
}

void postorder(Nodo* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);

    stampa_birra(root->key);
}

int profondita(Nodo* root)
{
    if(root == NULL)
        return 0;
    int sx = profondita(root->left);
    int dx = profondita(root->right);

    return 1 + max(sx,dx);
}

int max(int v1, int v2)
{
    return (v1 > v2)? v1:v2;
}

Nodo* ricerca(Nodo* root, char* nome_birra)
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->key.nome, nome_birra) == 0)
        return root;
    if(strcmp(nome_birra, root->key.nome)<0)
        ricerca(root->left, nome_birra);
    ricerca(root->right, nome_birra);
}

Nodo* abr_min(Nodo* root)
{
    Nodo* tmp = root;
    while(tmp->left != NULL)
        tmp = tmp->left;
    
    return tmp;
}

Nodo* abr_max(Nodo* root)
{
    Nodo* tmp = root;
    while (tmp->right != NULL)
        tmp = tmp->right;

    return tmp;
}


Nodo* abr_pred(Nodo* x)
{
    if (x->left!= NULL)
        return abr_max(x->left);
    Nodo* y = x->parent;
    
    while(y != NULL && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

Nodo* abr_succ(Nodo* x)
{
    if(x->right != NULL)
        return abr_min(x->right);
    Nodo* y = x->parent;
    
    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

Nodo* delete_node(Nodo* root, Nodo* nodo)
{
    Nodo* y = NULL;
    Nodo* x = NULL;
    if(nodo->right == NULL || nodo->left == NULL)
        y = nodo;
    else
        y = abr_succ(nodo);

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y->left == y)
        y->parent->left = x;
    else
        y->right = x;

    if(y != nodo)
        nodo->key = y->key;

    free(y);
    return root;

}