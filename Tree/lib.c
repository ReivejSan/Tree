#include "head.h"

void createTree(BinTree *T){
    *T = nil;
}

bool IsUnerLeft(BinTree T){
    return (right(T)==nil && left(T)!=nil);
}

bool IsUnerRight(BinTree T){
    return (right(T)!=nil && left(T)==nil);
}

bool IsOneElmt(BinTree T){
    return (!(IsTreeEmpty(T)) && (right(T)==nil && left(T)==nil));
}

bool Search(BinTree T, infotype X){
    if(IsTreeEmpty(T))
        return false;
    else {
        if(info(T)==X)
            return true;
        else
            return (Search(left(T),X));
    }
}

bool IsTreeEmpty(BinTree T){
    return T == nil;
}

address Alokasi(infotype X){
    address P;
    P=(address)malloc(sizeof(node));
    if(P!=nil){
        info(P) = X;
        left(P) = nil;
        right(P) = nil;
    }
    return P;
}

void Dealokasi(BinTree *P){
    free(*P);
}

void InserNode(BinTree *T,infotype X){
    if(IsTreeEmpty(*T)){
        *T = Alokasi(X);
    }
    else{
        if(X <= info(*T)){
            InserNode(&left(*T),X);
        }
        else{
            InserNode(&right(*T),X);
        }
    }
}

void PrintPreOrder(BinTree T){
    if(IsTreeEmpty(T)){
        return;
    }
    else{
        printf("| %d ",info(T));
        PrintPreOrder(left(T));
        PrintPreOrder(right(T));
    }
}
void PrintInOrder(BinTree T){
    if(IsTreeEmpty(T)){
        return;
    }
    else{
        PrintInOrder(left(T));
        printf("| %d ",info(T));
        PrintInOrder(right(T));
    }
}
void PrintPostOrder(BinTree T){
    if(IsTreeEmpty(T)){
        return;
    }
    else{
        PrintPostOrder(left(T));
        PrintPostOrder(right(T));
        printf("| %d ",info(T));
    }
}

void PrintPreOrderGanjil(BinTree T){
    if(IsTreeEmpty(T)){
        return;
    }
    else{
        if(info(T)%2!=0){
            printf("| %d ",info(T));
        }
        PrintPreOrderGanjil(left(T));
        PrintPreOrderGanjil(right(T));
    }
}

void PrintPostOrderKanan(BinTree T){
    if(IsTreeEmpty(T)){
        return;
    }
    else{
        PrintPostOrderKanan(left(T));
        PrintPostOrderKanan(right(T));
        if(right(T)!=nil){
            if(!IsOneElmt(T)){
                printf("| %d ",info(T));
            }
        }
    }
}

int LevelLeft(BinTree P)
{
    return LevelTapiTanpaX(left(P));
}

int LevelTapiTanpaX(BinTree P)
{
   if (IsOneElmt(P)){
       return 1;
   }
   else if(IsTreeEmpty(P)){
        return;
   }
   else{
       int lDepth = LevelTapiTanpaX(left(P));
       int rDepth = LevelTapiTanpaX(right(P));

       if(lDepth > rDepth){
           return(lDepth+1);
       }
       else{
            return(rDepth+1);
       }
   }
}

void InsertNodeKiri(BinTree *T, infotype *X){
    if(IsTreeEmpty(*T)){
        *T = Alokasi(*X);
    }
    else if(IsOneElmt(*T)){
        *X = info(*T);
        InsertNodeKiri(&left(*T), X);
    }
    else{
        if(IsUnerLeft(*T)){
            InsertNodeKiri(&left(*T), X);
        }
        else if(IsUnerRight(*T)){
            InsertNodeKiri(&left(*T), X);
        }
        else{
            InsertNodeKiri(&left(*T), X);
            InsertNodeKiri(&right(*T), X);
        }
    }
}

void DelTerkanan(BinTree *T){
    if(IsOneElmt(*T) ||  IsUnerLeft(*T)){
        Dealokasi(&(*T));
        *T = nil;
    }
    else{
        DelTerkanan(&(right(*T)));
    }
}

