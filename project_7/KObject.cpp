//
// Created by top on 2022-11-15.
//
#include <iostream>
#include "KObject.h"
using namespace std;
void MetaObject::active(KObject* sender, int sigID)
{
    Connection c = sender->connections[sigID];
    c.receiver->metacall(c.sltID);
}

KObject::KObject(){}

KObject::~KObject(){}

void KObject::kconnect(KObject* sender, int sigID, KObject* receiver, int sltID)
{
    Connection c = {receiver, sltID};
    sender->connections.insert(std::pair<int, Connection>(sigID, c));
}

TestClassA::TestClassA()
{
}

void TestClassA::metacall(int sltID)
{
}

void TestClassA::sigTestA(int sigID)
{
    MetaObject::active(this, sigID);
}

TestClassB::TestClassB()
{
}

void TestClassB::metacall(int sltID)
{
    switch (sltID) {
        case SLT_HELLOWORLD:
            slotTestB();
            break;
        default:
            break;
    };
}

void TestClassB::slotTestB()
{
    cout << "hello world TestB"<<endl;
}