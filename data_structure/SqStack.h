#define MaxSize 10 //定义栈中元素的最大个数
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];//静态数组存放在战中的元素
    int top;//栈顶指针
} SqStack;

//初始化栈顶
void InitStack(SqStack &S) {
    S.top = -1;//初始化栈顶指针

}

//入栈
bool Push(SqStack &S, ElemType x) {
    if (S.top == (MaxSize - 1))
        return false;//队满，入栈失败
    S.top++;//栈顶指针自增，因为栈顶指针初始化为-1;
    S.data[S.top] = x;//将x  存入数据域
    return true;
}

//出栈
bool Pop(SqStack &S, ElemType &data) {
    if (S.top == -1)
        return false;//队空，出栈失败
    data = S.data[S.top];//当前top指针指向的元素
    S.top--;//先取/当前top指针指向的元素，再将指针下移
    return true;
}
int GetStack(SqStack S){
    return S.data[S.top];
}
int StackSize(SqStack S){
    return S.top+1;
}
//判断栈空
bool StackEmpty(SqStack S) {
    return S.top==-1 ? true: false;//栈空



}