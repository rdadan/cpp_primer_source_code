#include "../head.h"

//函数模板就是一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表

//函数模板机制结论： 两次编译
// 编译器并不是把函数模板处理成能够处理任何类型的函数
// 函数模板通过具体类型产生不同的函数
// 编译器会对函数模板进行 两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。

template <typename T>
void templateSwap(T &a, T &b)
{
    // cout << "sizeof(T): " << sizeof(T) << endl;
    T t = a;
    a = b;
    b = t;
}
class Person
{
public:
    Person(int age, char *name)
    {
        mAge = age;
        mName = name;
    }
    ~Person()
    {
    }
    friend void templateSwap<Person>(Person &p1, Person &p2);
    // void templateSwapPer(Person &p1, Person &p2);

    void printPerson()
    {
        cout << "Name = " << mName << " Age = " << mAge << endl;
    }

private:
    int mAge;
    string mName;
    // char *mName;
};

// 模板函数的局限性
// template<class T>
// void f(T a, T b)
// { … }
// 如果代码实现时定义了赋值操作 a = b，但是T为数组，这种假设就不成立了
// 同样，如果里面的语句为判断语句 if(a>b),但T如果是结构体，该假设也不成立，
// 另外如果是传入的数组，数组名为地址，因此它比较的是地址，而这也不是我们所希望的操作。
// 为了解决这种问题，可以提供模板的重载，为这些特定的类型提供具体化的模板。

// templateSwap 模板重载
// template<>开头，并通过名称来指出类型
template <>
void templateSwap<Person>(Person &p1, Person &p2)
{
    string nameTemp;
    int ageTemp;

    nameTemp = p1.mName;
    p1.mName = p2.mName;
    p2.mName = nameTemp;

    ageTemp = p1.mAge;
    p1.mAge = p2.mAge;
    p2.mAge = ageTemp;
}
// void Person::templateSwapPer(Person &p1, Person &p2)
// {
//     string nameTemp;
//     int ageTemp;

//     nameTemp = p1.mName;
//     p1.mName = p2.mName;
//     p2.mName = nameTemp;

//     ageTemp = p1.mAge;
//     p1.mAge = p2.mAge;
//     p2.mAge = ageTemp;
// }

void test04()
{
    int ia = 1, ib = 2;
    // 函数模板可以自动推导参数的类型
    templateSwap(ia, ib);
    cout << "a: " << ia << " b:" << ib << endl;
    // 也可以显式指定类型
    templateSwap<int>(ia, ib);
    cout << "a: " << ia << " b:" << ib << endl;

    cout << "1----" << endl;
    char ca = 'a', cb = 'b';
    templateSwap(ca, cb);
    cout << "ca: " << ca << " cb:" << cb << endl;
    templateSwap<char>(ca, cb);
    cout << "ca: " << ca << " cb:" << cb << endl;

    cout << "2----" << endl;

    Person P1(10, "Tom");
    Person P2(20, "Jerry");

    P1.printPerson();
    P2.printPerson();
    templateSwap(P1, P2);
    P1.printPerson();
    P2.printPerson();
}

// 使用函数模板实现对char和int类型数组进行排序
template <class T>
void printArr(T arr[], int len)
{
    // cout << "sizeof(arr): " << sizeof(arr) << " sizeof(T): " << sizeof(T) << endl; // (arr是指针)8 指针大小, 4 int大小
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void printArr2(T *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

template <class T>
void printArr3(T (&arr)[6], int len)
{
    cout << "sizeof(arr): " << sizeof(arr) << " sizeof(T): " << sizeof(T) << endl; // 8 (arr是数组)数组大小, 4 int大小
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

template <class T>
void sortArr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        T min = arr[i];
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] <= min)
            {
                templateSwap(min, arr[j]);
            }
        }
        arr[i] = min;
    }
}

void test05()
{
    int arr[] = {1, 5, 3, 25, 6, 78, 9, 3, 1};
    int len = sizeof(arr) / sizeof(int);
    printArr<int>(arr, len);
    sortArr(arr, len);
    cout << "---" << endl;

    printArr(arr, len);
    cout << "---" << endl;
    char cArr[] = {'c', 'a', 'v', 'b', 'w', 't', 'w', 'q', 'b'};
    len = sizeof(cArr) / sizeof(char);
    printArr<char>(cArr, len);
    sortArr(cArr, len);
    cout << "---" << endl;

    printArr(cArr, len);
}

int main()
{
    test04();
    return 0;
}