#include "header.h"

void createTree(BinTree *T){
    *T = Nil;
}
bool isTreeEmpty(BinTree T){
    return T == Nil;
}
address Alokasi(infotype X){
    address P;
    P = (address)malloc(sizeof(node));
    if(P != Nil){
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}
void insertNode(BinTree *T, infotype X){
    if(isTreeEmpty(*T)){
        *T = Alokasi(X);
    }
    else{
        if(X <= Info(*T)){
            insertNode(&Left(*T), X);
        }
        else{
            insertNode(&Right(*T), X);
        }
    }
}

void preOrder(BinTree T){
    if(isTreeEmpty(T)){
        printf("| ");
    }
    else{
        printf("| %d ", Info(T));
        preOrder(Left(T));
        preOrder(Right(T));
    }
}
void inOrder(BinTree T){
    if(isTreeEmpty(T)){
        printf("| ");
    }
    else{
        inOrder(Left(T));
        printf("| %d ", Info(T));
        inOrder(Right(T));
    }
}
void postOrder(BinTree T){
    if(isTreeEmpty(T)){
        printf("| ");
    }
    else{
        inOrder(Left(T));
        inOrder(Right(T));
        printf("| %d ", Info(T));
    }
}
