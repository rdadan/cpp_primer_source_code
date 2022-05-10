#include "../../head.h"

class myString
{
public:
    
    myString();
    myString(const char * str);
    myString(const myString &str);
    ~myString();


    // 输入输出
    friend istream &operator>>(istream &is, myString &str);
    friend ostream &operator<<(ostream &os, const myString &str);
    // 获取长度
    int getLen();
    // 拼接
    myString operator+(myString str);
    myString operator+(const char * str);

    // 赋值
    myString &operator=(myString str);
    myString &operator=(const char *str);

    // 比较
    bool operator==(myString str);
    bool operator==(const char *str);

    // []
    char & operator[](int idx);
private:
    int mLen;
    char * mStr;
};

myString::myString()
{
    mLen=0;
    mStr=NULL;
}
myString::myString(const char *str)
{
    mStr = new char[strlen(str)+1];
    strcpy(mStr, str);
    mLen = strlen(mStr);
}
myString::myString(const myString &str)
{
    if (&str != this)
    {
        mStr = new char[strlen(str.mStr) + 1];
        strcpy(mStr, str.mStr);
        mLen = strlen(mStr);
    }
        
}
myString::~myString()
{
    if(mStr != NULL)
    {
        delete [] mStr;
        mStr = NULL;
    }
}

int myString::getLen()
{
    return mLen;
}
istream &operator>>(istream & is, myString &str)
{
    if(str.mStr != NULL)
    {
        delete [] str.mStr;
        str.mStr = NULL;
    }
    char buf[1024];
    cin >> buf;
    str.mStr = new char[strlen(buf)+1];
    strcpy(str.mStr, buf);
    str.mLen = strlen(str.mStr);
    return is;
}

ostream &operator<<(ostream & os, const myString &str)
{
    os << "str:" << str.mStr << " len:" << str.mLen << endl;
    return os;
}

// 拼接
myString myString::operator+(myString str)
{
    int len = mLen +str.mLen + 1;
    char *temp = new char[len]();
    strcat(temp, mStr);
    strcat(temp, str.mStr);

    myString newStr(temp);
    delete [] temp;
    return newStr;
}
myString myString::operator+(const char *str)
{
    int len = mLen + strlen(str) + 1;
    char *temp = new char[len]();
    strcat(temp, mStr);
    strcat(temp, str);

    myString newStr(temp);
    delete[] temp;
    return newStr;
}

// 赋值
myString &myString::operator=(myString str)
{
    if(this == &str)
        return *this;

    if(mStr != NULL)
    {
        delete [] mStr;
        mStr = NULL;
    }
    mStr = new char[str.mLen+1];
    strcpy(mStr, str.mStr);
    mLen=strlen(mStr);
    return *this;
}
myString &myString::operator=(const char *str)
{
    if (mStr != NULL)
    {
        delete[] mStr;
        mStr = NULL;
    }
    mStr = new char[strlen(str) + 1];
    strcpy(mStr, str);
    mLen = strlen(mStr);
    return *this;
}

// 比较
bool myString::operator==(myString str)
{
    return (strcmp(mStr, str.mStr) == 0 && mLen == str.mLen);
}
bool myString::operator==(const char *str)
{
    return strcmp(mStr, str)==0 && mLen == strlen(str);
}

//[]
char &myString::operator[](int idx)
{
    if(idx > mLen-1 || idx < 0)
        return mStr[0];
    return mStr[idx];
}


void test()
{
    myString str("hello");
    cout << str << endl;
    str = str+" world";
    cout << str << endl;

    myString str2 = str;
    cout << str2 << endl;
    cout << (str2 == str) << endl;

    str2 = "ww";
    cout << str2 << endl;
    cout << (str2 == str) << endl;
    
    cout << "--" << endl;
    str2 = str2;
    cout << str2 << endl;

    str2 = str2+str2+" " +str;
    cout << str2 << endl;

    cout << str2[13] << endl;
}
int main()
{
    test();
    return 0;
}