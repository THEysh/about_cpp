#include "TanMetaObject.h"
#include <iostream>
#include "KObject.h"
int main(void)
{
    TestClassA a;
    TestClassB b;
    KObject::kconnect(&a, TestClassA::SIG_HELLOWORLD, &b, TestClassB::SLT_HELLOWORLD);
    a.sigTestA(TestClassA::SIG_HELLOWORLD);

}
