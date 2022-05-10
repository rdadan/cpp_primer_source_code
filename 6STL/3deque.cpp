#include "../head.h"

// deque 则是一种双向开口的连续性空间，可以在头尾两端分别做元素的插入和删除操作
// deque没有容量的概念，因为它是动态的以分段的连续空间组合而成，随时可以增加一段新的空间并链接起来
// 不会像vector那样“因旧空间不足而重新分配一块更大的空间，然后再复制元素，释放空间” 。 没有deque.capacity()

// 	双端插入和删除元素效率较高.
// 	指定位置插入也会导致数据元素移动,降低效率.
// 	可随机存取,效率高.

void printDeq(const deque<int> &deq)
{
    for (auto v : deq)
        cout << v << " ";
    cout << endl;
}

// deque赋值操作
void test01()
{
    int arr[] = {1, 3, 5, 7, 9};

    deque<int> deq(arr, arr + 5);
    printDeq(deq);

    int arr2[] = {11, 13, 15, 17, 19};
    deq.assign(arr2, arr2 + 5);
    printDeq(deq);
}
// deque大小操作
void test02()
{
    int arr[] = {1, 3, 5, 7, 9};

    deque<int> deq(arr, arr + 5);
    printDeq(deq);

    //返回容器中元素的个数
    cout << "deq.size(): " << deq.size() << endl;
    //判断容器是否为空
    cout << "deq.empty(): " << deq.empty() << endl;
    //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
    deq.resize(10);
    //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
    deq.resize(15, -1);
    printDeq(deq);
}

// deque 双端插入和删除
void test03()
{
    int arr[] = {1, 5, 3, 7, 9};
    deque<int> deq(arr, arr + 5);

    deq.push_back(10);   //尾部插入
    deq.push_front(-10); //头部插入
    printDeq(deq);

    deq.pop_back();  //尾部删除
    deq.pop_front(); //头部删除
    printDeq(deq);
}

// deque 数据存取
void test04()
{
    int arr[] = {1, 3, 5, 7, 9};
    deque<int> deq(arr, arr + 5);

    cout << "deq.at(0): " << deq.at(0) << endl; //返回索引idx所指的数据，如果idx越界，抛出out_of_range。
    cout << "deq.front(): " << deq.front() << endl;
}
// deque 插入操作
void test05()
{
    int arr[] = {1, 3, 5, 7, 9};
    deque<int> deq(arr, arr + 5);

    deq.insert(deq.begin(), -1);
    deq.insert(deq.end(), -1);
    printDeq(deq);

    deq.insert(deq.end(), arr, arr + 5);

    printDeq(deq);
}
// 在需要对deque容器元素进行排序的时候，
// 建议先将deque容器中数据数据元素拷贝到vector容器中，
// 对vector进行排序，然后再将排序完成的数据拷贝回deque容器。

// deque 删除操作
void test06()
{
    int arr[] = {1, 3, 5, 7, 9};
    deque<int> deq(arr, arr + 5);
    printDeq(deq);

    // deq.erase(deq.begin());
    deq.erase(deq.begin(), deq.begin() + 2);
    printDeq(deq);

    cout << "size: " << deq.size() << endl;
    cout << "empty?: " << deq.empty() << endl;
    // cout << "capacity: " << deq.capacity() << endl; //没有capacity()
    deq.clear();
    cout << "size: " << deq.size() << endl; // 0
}
int main()
{
    test06();
    return 0;
}