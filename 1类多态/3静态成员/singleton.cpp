#include "../../head.h"

// 懒汉版（Lazy Singleton）：单例实例在第一次被使用时才进行初始化，这叫做延迟初始化。
class LazySingleton
{
public:
    static LazySingleton *getInstance()
    {
        if (pSingle == NULL)
        {
            pSingle = new LazySingleton();
        }
        return pSingle;
    }
    // 打印实例地址
    void Print() { std::cout << "我的实例内存地址是:" << this << std::endl; }

private:
    // 禁止外部构造和析构
    LazySingleton();
    ~LazySingleton();
    // 禁止外部拷贝和赋值
    LazySingleton(const LazySingleton &);
    LazySingleton &operator=(const LazySingleton &);

private:
    static LazySingleton *pSingle;
};

// 线程不安全 一开始是空，用到是才会new。可能多个线程同时用到
LazySingleton *LazySingleton::pSingle = NULL;

// 饿汉版（Eager Singleton）：指单例实例在程序运行时被立即执行初始化
// 饿汉实现 /

class Singleton
{
public:
    // 获取单实例
    static Singleton *GetInstance() { return g_pSingleton; }

    // 释放单实例，进程退出时调用
    static void deleteInstance()
    {
        if (g_pSingleton)
        {
            delete g_pSingleton;
            g_pSingleton = NULL;
        }
    }

    // 打印实例地址
    void Print() { std::cout << "我的实例内存地址是:" << this << std::endl; }

private:
    // 将其构造和析构成为私有的, 禁止外部构造和析构
    Singleton() { std::cout << "构造函数" << std::endl; }
    ~Singleton() { std::cout << "析构函数" << std::endl; }

    // 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
    Singleton(const Singleton &signal);
    const Singleton &operator=(const Singleton &signal);

private:
    // 唯一单实例对象指针
    static Singleton *g_pSingleton;
};

// 代码一运行就初始化创建实例 ，本身就线程安全
Singleton *Singleton::g_pSingleton = new Singleton();
