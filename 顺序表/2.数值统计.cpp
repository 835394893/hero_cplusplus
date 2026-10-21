#include <iostream>
#include <stdexcept>
using namespace std;
#define eleType double
struct SequentialList
{
    eleType *elements;
    int size;
    int capacity;
};

//初始化顺序表
void initializeList(SequentialList *list,int capacity)
{
    list->elements = new eleType[capacity];
    list->size = 0;
    list->capacity = capacity;
}

//释放顺序表
void destroyList(SequentialList *list)
{
    delete [] list->elements;
}

//获取顺序表大小
int size(SequentialList *list)
{
    return list->size;
}

//判断顺序表是否为空
bool isEmpty(SequentialList *list)
{
    return list->size == 0;
}

void insert(SequentialList *list,int index,eleType element)
{
    if (index < 0 || index > list->size)
    {
        throw std::invalid_argument("Invalid index");
    }
    //扩容
    if (list->size == list->capacity)
    {
        int newCapacity = list->capacity * 2;
        eleType *newElements = new eleType[newCapacity];
        for (int i = 0;i < list->size; ++i)
        {
            newElements[i] =list->elements[i];
        }
        delete[] list->elements;
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    for(int i = list->size;i > index;--i)
    {
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = element;
    list->size++;
}

//删除顺序表
void deleteElement(SequentialList *list,int index)
{
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }
    for(int i = index; i < list->size - 1;++i)
    {
        list->elements[i] = list->elements[i+1];
    }
    list->size--;
}

//查找
int findElement(SequentialList *list,eleType element)
{
    for(int i = 0;i < list->size;++i)
    {
        if(list->elements[i] == element)
        {
            return i;
        }
    }       
    return -1;
}

//元素索引
eleType getElement(SequentialList *list,int index)
{
    //判断下标是否合法
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }
    return list->elements[index];
}

//修改元素
void updataElement(SequentialList *list,int index,eleType value)
{
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }        
    list->elements[index] = value;
}

int main()
{
    int n; 
    while(cin >> n && n)
    {
        SequentialList s;
        initializeList(&s,1);
        for(int i = 0;i < n;++i)
        {
            eleType x;
            cin >> x;
            insert(&s,i,x);
        }
        int pcnt = 0,zcnt = 0,ncnt = 0;
        for(int i = 0;i < size(&s);++i)
        {
            eleType ele = getElement(&s,i);
            if(ele > 1e-8)
            {
                ++pcnt;
            }
            else if (ele < -1e-8)
            {
                /* code */
                ++ncnt;
            }
            else{
                ++zcnt;
            }
        }
        cout << ncnt << ' ' << zcnt << ' ' << pcnt<< endl;
        destroyList(&s);
    }
    return 0;
}