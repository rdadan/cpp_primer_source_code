#include "../head.h"

//在尾端插入和删除元素效率较高，在指定位置插入，势必会引起数据元素移动，效率较低。
void printVec(const vector<int> &vec)
{
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
}
void test01()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    printVec(vec);
}
// vector常用赋值操作
void test02()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec;
    vec.assign(arr, arr + 5);
    printVec(vec);
}
// vector大小操作
void test03()
{
    int arr[] = {1, 2, 3};
    vector<int> vec;
    vec.assign(arr, arr + 3);

    cout << "size: " << vec.size() << endl; // 3
    cout << "empty?: " << vec.empty() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    vec.resize(1); // resize 讲大小改变为10
    cout << "resize size: " << vec.size() << endl;
    printVec(vec); // resize 超出大小的空间会填充, 小于原理的size，后面的会自动丢弃

    vec.reserve(20); // reserve 容器空间，预留位置不初始化，元素不可访问。
    cout << "reserve size: " << vec.size() << endl;
    printVec(vec);

    //  问：reserv和resize的区别?
    //  答: reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，不能引用容器内的元素.
    //      resize是改变容器的大小，且在创建对象，因此，调用这个函数之后，就可以引用容器内的对象了.
    //  巧用reserve增加程序效率：
    // 当我们知道我们存储的元素大概有多少的时候,我们就可以使用reserve方法，来减少vector重新申请内存-拷贝数据-释放旧空间的次数。
}

// vector数据存取操作
void test04()
{
    int arr[] = {1, 3, 5, 7, 9};
    vector<int> vec(arr, arr + 5);
    cout << "vec.at():" << vec.at(1) << endl;
    cout << "vec.front() :" << vec.front() << endl;
    cout << "vec.back():" << vec.back() << endl;
}

// vector插入和删除操作
void test05()
{
    int arr[] = {1, 3, 5, 7, 9};
    vector<int> vec(arr, arr + 5);

    vec.insert(vec.begin(), -1);   //在第一个位置插入-1
    vec.insert(vec.begin(), 3, 0); //在第一个位置插入3个0
    printVec(vec);

    vec.insert(vec.end(), 3, 0); // end()返回的是最后元素的下个位置。在最后位置下个位置插入
    printVec(vec);

    vec.push_back(100); //在最后位置插入100
    printVec(vec);
    cout << "size: " << vec.size() << endl;
    vec.pop_back(); //删除最后位置元素
    printVec(vec);
    cout << "size: " << vec.size() << endl;

    vec.erase(vec.begin()); //删除迭代器位置元素
    printVec(vec);

    vec.erase(vec.end() - 3, vec.end()); //删除迭代器从start到end之间的元素

    cout << "size: " << vec.size() << endl;         // 8
    cout << "capacity: " << vec.capacity() << endl; // 18

    vec.clear();                                    //清空元素， 但是没有回收内存
    cout << "size: " << vec.size() << endl;         // 0
    cout << "capacity: " << vec.capacity() << endl; // 18

    vector<int>().swap(vec);                        // 回收内存
    cout << "capacity: " << vec.capacity() << endl; // 0
}
void test06()
{
    string str(5, '*');
    vector<string> vec(5, str);
    cout << vec[0][0] << endl;
    for (auto v : vec)
    {
        cout << v << endl;
    }
}

vector<vector<int>> sets;
void backtrack(vector<int> &nums, vector<int> &vec, int size, int start)
{
    cout << "size " << size << " vec.size:" << vec.size() << endl;

    if (size == vec.size())
    {
        sets.push_back(vec);
        return;
    }

    // for (int i = start; i < numsSet.size(); i++)
    for (int it = start; it < nums.size(); ++it)
    {
        vec.push_back(nums[it]);

        backtrack(nums, vec, size, it + 1);
        vec.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<int> numsSet(nums.begin(), nums.end()); //去除重复元素
    nums.assign(numsSet.begin(), numsSet.end());
    for (int size = 0; size <= nums.size(); size++)
    {
        vector<int> vec;
        backtrack(nums, vec, size, 0);
    }
    return sets;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    vector<vector<int>> sets = subsetsWithDup(nums);
    for (auto T : sets)
    {
        for (auto t : T)
            cout << t;
        cout << endl;
    }
    return 0;
}