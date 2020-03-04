#include "head.h"

int main()
{
 BinTree T;
 int X;

 createTree(&T);
 InserNode(&T,5);
 InserNode(&T,5);
 InserNode(&T,5);
 InserNode(&T,2);
 InserNode(&T,7);
 InserNode(&T,1);
 InserNode(&T,1);
 InserNode(&T,3);
 InserNode(&T,3);
 InserNode(&T,3);
 InserNode(&T,6);
 InserNode(&T,6);
 InserNode(&T,6);

 printf("Pre Order Ganjil : ");
 PrintPreOrderGanjil(T);
 printf("\n\n");

 printf("Post Order Anak Kanan : ");
 PrintPostOrderKanan(T);
 printf("\n\n");

 printf("Pre Order : ");
 PrintPreOrder(T);
 puts("");
 printf("Tinggi Sub Pohon Kiri : ");
 printf("%d", LevelLeft(T));
 printf("\n\n");

 printf("Insert Kiri Sama : \n");
 InsertNodeKiri(&T, &X);
 printf("Post Order : ");
 PrintPostOrder(T);
 printf("\n\n");

 printf("Delete Terkanan : ");
 DelTerkanan(&T);
 puts("");
 printf("Post Order : ");
 PrintPostOrder(T);
 printf("\n\n");

    return 0;
}
