#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Nil NULL

typedef int infotype;
typedef struct node *address;
typedef struct node{
    infotype Info;
    address Left;
    address Right;
}node;

typedef address BinTree;

#define Info(P) (P)->Info
#define Left(P) (P)->Left
#define Right(P) (P)->Right

void createTree(BinTree *T);
bool isTreeEmpty(BinTree T);
address Alokasi(infotype X);
void insertNode(BinTree *T, infotype X);

void preOrder(BinTree T);
void inOrder(BinTree T);
void postOrder(BinTree T);

void insertLeft(BinTree *T, infotype X);
void insertRight(BinTree *T, infotype X);
#endif // HEADER_H_INCLUDED
