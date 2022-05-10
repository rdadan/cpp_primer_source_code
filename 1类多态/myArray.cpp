#include "../head.h"

class myArray
{
public:
    myArray();
    myArray(int capacity);
    ~myArray();
    bool setData(int pos, int val);
    int getData(int pos);
    int popData();
    int getSize();
    int getCapacity();
private:
    int mSize; //数组当前大小
    int mCapacity; // 数组容量
    int *mParr; // 指向数组最后元素的位置
};

//默认容量
myArray::myArray()
{
    mCapacity = 100;
    mSize = 0;
    mParr = new int[mCapacity];
}
//指定容量
myArray::myArray(int capacity)
{
    mCapacity=capacity;
    mSize=0;
    mParr = new int[mCapacity];
}
myArray::~myArray()
{
    if(mSize>0)
    {
        delete[] mParr;
        mParr = NULL;
    } 
}
// 获取元素
int myArray::getData(int pos)
{
    return mParr[pos];
}
// 添加元素
bool myArray::setData(int pos, int val)
{
    if(pos > mCapacity-1 || pos < -1 || pos > mSize)
        return false;
    mParr[pos] = val;
    mSize++;
    return true;
}
int myArray::popData()
{
    if(mSize>0)
    {
        mSize--;
        return mParr[mSize];
    }
    return -99999;
}

int myArray::getSize()
{ 
    return mSize; 
}
int myArray::getCapacity() 
{
    return mCapacity;
}

int main()
{
    myArray arr(30);
    cout << "www" << endl;
    cout << "size: " << arr.getSize() << endl;
    cout << "capacity: " << arr.getCapacity() << endl;

    arr.setData(1, 20);
    arr.setData(2, 20);
    cout << arr.getData(1) << endl;
   
    for (int i = 0; i < 30; i++)
    {
        arr.setData(i, i);
    }
    cout << "size: " << arr.getSize() << endl;

    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr.getData(i) << "-";
    }
    cout << endl;
    int arrSize = arr.getSize();
    while (arr.getSize())
    {
        cout << arr.popData() << "-";
    }

    return 0;
}
