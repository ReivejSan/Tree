#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nil NULL

typedef int infotype;
typedef struct node *address;
typedef struct node{
    infotype info;
    address left;
    address right;
}node;

typedef address BinTree;

#define info(P) (P)->info
#define left(P) (P)->left
#define right(P) (P)->right

bool IsOneElmt(BinTree T);
bool IsUnerRight(BinTree T);
bool IsHaveRight(BinTree T);
bool IsLeft(BinTree T);

///membuat tree kosong
void createTree(BinTree *T);

///cek tree
bool IsTreeEmpty(BinTree T);
bool Search(BinTree T, infotype X);
int LevelTapiTanpaX(BinTree P);
int LevelLeft(BinTree P);

///manajemen memori
address Alokasi(infotype X);

///data
void InserNode(BinTree *T,infotype X);

///cetak
void PrintPreOrder(BinTree T);
void PrintInOrder(BinTree T);
void PrintPostOrder(BinTree T);

///Tugas Pak Moses
void PrintPreOrderGanjil(BinTree T);
void PrintPostOrderKanan(BinTree T);
int TinggiSubPohonKiri(BinTree T, infotype X);
void InserNodeKiri(BinTree *T, infotype X);
void DelTerkanan(BinTree *T);
void Dealokasi(BinTree *T);

#endif // HEAD_H_INCLUDED
