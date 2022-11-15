#include <map>
# define kslots
# define ksignals public
# define kemit

class KObject;
struct MetaObject
{
    static void active(KObject * sender, int idx);
};
struct Connection
{
    KObject * receiver;
    int sltID;
};
typedef std::map<int, Connection> ConnectionMap;
class KObject
{
    friend class MetaObject;
    static MetaObject meta;

public:
    KObject();
    virtual ~KObject();
    static void kconnect(KObject*, int, KObject*, int);

protected:
    virtual void metacall(int sltID) = 0;
ksignals:
    //void sigtest();
public kslots:
    //void slottest();
private:
    ConnectionMap connections;
};

class TestClassA : public KObject
{
public:
    TestClassA();

protected:
    void metacall(int sltID);

ksignals:
    typedef enum{
        SIG_HELLOWORLD,
    }SIG_ID;

    void sigTestA(int sigID);
};


class TestClassB : public KObject
{
public:
    TestClassB();

    void metacall(int sltID);

public kslots:

    typedef enum{
        SLT_HELLOWORLD = 2,
    }SLT_ID;

    void slotTestB();
};