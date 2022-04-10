#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "livro.h"


typedef struct tree Tree;

Tree* initTree();

void printTree(Tree* tree);

Tree* insert(Tree* tree, Livro* livro);

Tree* remover(Tree* t, Livro* l);

Tree* search(Tree* tree, float nota);

Tree* libera(Tree* t);

int voidTree(Tree* t);


#endif /* TREE_H */