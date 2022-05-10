#include "../../head.h"
class Point
{
private:
    int mX;
    int mY;

public:
    Point() {}
    Point(int x, int y)
    {
        mX = x;
        mY = y;
    }
    ~Point() {}
    void print() { cout << "x:" << mX << " y:" << mY << endl; }

    // 重载输入
    friend istream &operator>>(istream &is, Point &p);
   
    // 重载输出
    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << "(x:" << p.mX << ", y:" << p.mY << ")" << endl;
        return os;
    }
};
// 重载输入
istream &operator>>(istream &is, Point &p)
{
    is >> p.mX;
    is >> p.mY;

    return is;
}
// 重载输出


void test()
{
    Point p(1, 2);
    cout << p << endl;

    // cin >> p;
    // cout << p << endl;
    // system("pause");
}

class Mail;
class Sender
{
public:
    Sender(string address)
        : mAddress(address)
    {
    }

    Sender &operator<<(const Mail &mail);

private:
    string mAddress;
};

class Mail
{
public:
    Mail() {}
    Mail(string title, string content)
        : mTitle(title), mContent(content)
    {
    }

    // 将Sender的重载操作符声明为自己的友元
    friend Sender &Sender::operator<<(const Mail &mail);

private:
    string mTitle;
    string mContent;
};

Sender &Sender::operator<<(const Mail &mail)
{
    cout << "address:" << mAddress << endl;
    cout << "title:" << mail.mTitle << endl;
    cout << "content:" << mail.mContent << endl;
    return *this;
}

void testMail()
{
    Sender sender("aa@163.com");
    Mail mail1("say hello", "hello!");
    Mail mail2("say hi", "hi!");
    sender << mail1 << mail2;
}
int main()
{
    test();
    return 0;
}
