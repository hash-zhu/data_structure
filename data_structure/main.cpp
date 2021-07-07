/*
#include <iostream>
//#include "SqStack.h"
//#include "SqList.h"
//#include "BinarySortTree.h"
#include "SequetailList.h"

int main() {
*/
/*
SqStack stack;
    InitStack(stack);
    printf("\n入栈前：%d\n stack.top: %d\n", StackEmpty(stack), stack.top);
    for (int i = 0; i < 10; ++i) {
        Push(stack, i );
    }
    printf("\n入栈后：%d\n stack.top: %d\n", StackEmpty(stack), stack.top);
    int data;

    while (stack.top!=-1){
        Pop(stack, data);
        printf(" pop :%d ", data);
    }


    printf("\n出栈后：%d\n stack.top: %d\n", StackEmpty(stack), stack.top);

SqList list;
    InitSqList(list);
    foreach(list);
    for (int i = 0; i < 9; ++i) {
        InsertSqList(list,i);
    }
    foreach(list);
    ElemType x;
    x.key=422;
    InsertSList(list,x,1);
    foreach(list);



BSTree root;
    InitBST(root);
    KeyType arr[] = {45, 24, 53, 45, 12, 24, 90};
    for (int i : arr) {
        InsertBST(root, i);
    }
    ConvenienceBST(root);
*//*



    SqList list;
    InitSqList(list);
    foreach(list);
    KeyType arr[] = {45, 24, 53, 47, 12, 26, 90, 80, 56, 36};
    for (int i = 0; i < 11; ++i) {
        InsertSqList(list, arr[i]);
    }
    foreach(list);
//    InsertSort(list);
//    BinaryInsertSort(list);
//    foreach(list);

//ShellSort
int array[]={7,5,3,1};
    for (int i = 0; i < 4; ++i) {

        ShellInsertSort(list, array[i]);

    }

//冒泡排序
//    Bubble_sort(list);
//快速排序
//    QuickSort(list,1,list.length);
//简单选择排序--不稳定的排序
//    SelectSort(list);
//堆排序
    HeapSort(list);
    printf("\n数组里的元素有：[");
    for (int i = 1; i < list.length; ++i) {
        printf("%d ", list.r[i].key);
    }
    printf("]\n数组的长度为：%d", list.length);
    return 0;

}



*/
/*
#include <stdio.h>
void swap(int a[], int b, int c) {
    int tmp = a[b];
    a[b] = a[c];
    a[c] = tmp;
}
void heapify(int a[], int i, int n) {
    if (i >= n)
        return;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int min = i;
    if (c1 < n && a[c1] < a[min])
        min = c1;
    if (c2 < n && a[c2] < a[min])
        min = c2;
    if (min != i) // 如果min == i， 停止递归
    {
        swap(a, min, i);
        heapify(a, min, n);
    }
}

void heapSort(int a[], int n) {

    for (int j = (n - 1 ) / 2; j >= 0; j--) {//最后一个分支节点
        heapify(a, j, n);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(a, i, 0);
        printf("%d\n", a[i]);
        heapify(a, 0, i);
    }
}
int main() {
    int a[] = {45, 24, 53, 47, 12, 26, 90, 80, 56, 36};
    heapSort(a, 10);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int dataType;
typedef struct {
    dataType data[MaxSize];
    int len;
}SqList;
//初始化
SqList *Init_List(){
    SqList *L;
    L=(SqList*)malloc(sizeof (SqList));

    L->len=-1;
    return L;
}
//插入
int Insert_SqList(SqList *L,int i,dataType e){
    int j;
    if(L->len==(MaxSize-1)){//检查表是否已满
        printf("表满溢出");
        return -1;
    }
    if(i<1||i>L->len+2) return 0;//检查插入位置是否有效
    for (j = L->len;  j>=i-1 ; j--) {
        L->data[j+1]=L->data[j];//节点后移
    }
    L->len++;
    L->data[i-1]=e;

    return 1;

}
void foreach(SqList list) {
    printf("\n数组里的元素有：[");
    for (int i = 0; i < list.len; ++i) {
        printf("%d ", list.data[i]);
    }
    printf("]\n数组的长度为：%d", list.len);
}
//删除
int Delete_SqList(SqList *L,int i){
    int j;
    if(L->len==-1)return -1;
    if(i<1||i>L->len+1){
        return 0;
    }
    for (j = i;  j<=L->len ; j++) {
        L->data[j-1]=L->data[j];
    }
    L->len--;
    return 1;
}
 int main(){
    SqList *L =Init_List();
     for (int i = 0; i <= 10; ++i) {
         Insert_SqList(L,i+1,i);
     }
     foreach(*L);
     Delete_SqList(L,2);
     foreach(*L);
     Insert_SqList(L,2,45);
     foreach(*L);
 }