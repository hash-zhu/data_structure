//
// Created by 少年与梦 on 2021-05-09.
//

#ifndef DATA_STRUCTURE_BINARYSORTTREE_H
#define DATA_STRUCTURE_BINARYSORTTREE_H
typedef int KeyType;
typedef char InfoType;
typedef struct {
    KeyType key;//关键字项
    InfoType otherinfo;//其他数据域
} ElemType;
typedef struct BSTNode{
    ElemType data;//数据域
    struct BSTNode *lchild, *rchild;//左右孩子指针
} BSTNode, *BSTree;//Binary Search Tree
//递归查找--//SearchBST
BSTree SearchBST(BSTree T, KeyType key);

//递归插入BST--//SearchBST
void InsertBST(BSTree &T, KeyType key);

//递归中序便利
void ConvenienceBST(BSTree T);

//对当前节点的操作
void visit(BSTree T);
//初始化
void InitBST(BSTree &T);
void visit(BSTree T) {
    printf("%d ", T->data.key);
}

void ConvenienceBST(BSTree T) {
    if (T == NULL)
        return;
    ConvenienceBST(T->lchild);//往左子树上递归遍历
    visit(T);//访问当前节点
    ConvenienceBST(T->rchild);//往右子树上递归遍历
}

void InsertBST(BSTree &T, KeyType key) {
    if (T == NULL) {
        T = (BSTNode *) malloc(sizeof(BSTNode));
        T->data.key = key;
        T->lchild = T->rchild = NULL;
        return;
    }
    if (T->data.key > key) {
        InsertBST(T->lchild, key);
    } else {
        InsertBST(T->rchild, key);
    }
}

BSTree SearchBST(BSTree T, KeyType key) {
    if (T == NULL || key == T->data.key)
        return T;
    else if (key < T->data.key)
        return SearchBST(T->lchild, key);//在左子树中继续查找
    else return SearchBST(T->rchild, key);//在右子树中继续查找
}//SearchBST
void InitBST(BSTree &T){
    T=NULL;
}
#endif //DATA_STRUCTURE_BINARYSORTTREE_H
