#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


struct tree{
    Livro* l;
    Tree* right;
    Tree* left;
};

//O critério do livro será a nota

Tree* initTree(void){
    return NULL;
}

void printTree(Tree* tree){
    if(tree != NULL){
        printTree(tree->left);
        imprime_livro(tree->l);
        printTree(tree->right);
    }

}

//Se encontar retorna o nó que contém o livro, se não retornará null
Tree* search(Tree* tree, float nota){
    if(tree == NULL){
        return NULL; 
    }
    else if (nota < getNota(tree->l)){
        search(tree->left, nota);
    }
    else if(nota > getNota(tree->l ) ){
        search(tree->right, nota);
    }
    else{//O livro é o do meio
        return tree;
    }   
    
}

//inserindo um livro na árvore. A insersão é ordenada
Tree* insert(Tree* tree, Livro* livro){
    if(tree == NULL){
        tree = (Tree*) malloc (sizeof(Tree));
        tree->l = livro;
        tree->left = NULL;
        tree->right = NULL;
     
    }
   
    else if( getNota(livro) <  getNota(tree->l)){
        tree->left = insert(tree->left, livro); //árvore da esquerda "vira" a nova head
    }
    else {
        tree->right = insert(tree->right, livro); //árvore da direita "vira" a nova head
    }
    
    return tree;
}

Tree* remover(Tree* t, Livro* l){

    if(t == NULL){
        return NULL;
    }
    
    if( getNota(t->l) > getNota(l )){
        t->left = remover(t->left,l);
    }
    else if(getNota(t->l) <getNota(l) ){
        t->right = remover(t->right, l);
    }
    else{//Achou o nó que quer remover
        Tree* aux = t;
        if(t->left == NULL && t->right == NULL ){//nó sem filhos
            free(t);
            t = NULL;
            
        }
        else if (t->left == NULL ){//nó com um filho na direita
            Tree* aux = t;
            t = t->right;
            free(aux);
        }
        else if (t->right == NULL ){//nó com um filho na esquerda
            Tree* aux = t;
            t = t->left;
            free(aux);
        }

        else{//nó com dois filhos
            //Tem que buscar o nó mais a direita da subárvore esquerda
            Tree* aux2 = t->left;
            while(aux2->right != NULL){  //loopa até achar o nó folha
                aux2 = aux2->right;
            }
            //Terminou a busca, trocar as informações
        Livro* livro = t->l;
        t->l = aux2->l;
        aux2->l = livro;
        t->left= remover(t->left, l );

        }


    }
    return t;

}


Tree* libera(Tree* t){
    if(!voidTree(t)){
        libera(t->left);
        libera(t->right);
        free(t);
    }
    return NULL;
}

int voidTree(Tree* t){
    if(t == NULL){
        return 1;
    }
    return 0;
}   
