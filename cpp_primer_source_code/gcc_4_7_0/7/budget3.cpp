#include "budget3.h"
// Definition of static member.
double Budget::corpBudget = 0;
void Budget::mainOffice(double budReq)
{
    corpBudget += budReq;
}