#pragma once
#include "../head.h"
template <class T1, class T2>
class PersonT
{
public:
    PersonT(T1 name, T2 age);
    void ShowPerson();

private:
    T1 mName;
    T2 mAge;
};
template <class T1, class T2>
PersonT<T1, T2>::PersonT(T1 name, T2 age)
{
    this->mName = name;
    this->mAge = age;
}

template <class T1, class T2>
void PersonT<T1, T2>::ShowPerson()
{
    cout << "Name:" << this->mName << " Age:" << this->mAge << endl;
}