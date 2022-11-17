//
// Created by top on 2022-11-14.
//

#ifndef PROJECT_7_TANMETAOBJECT_H
#define PROJECT_7_TANMETAOBJECT_H


#include <vector>
#include <utility>

template<typename T, typename ...Args>
using signal_function = void(T::*)(Args...);

template <typename ...Args>
struct TanSlotBase
{
    virtual void run(Args...) = 0;
};

template<typename T, typename ...Args>
class TanSlot : public TanSlotBase<Args...>
{
public:
    TanSlot(T* class_ptr, signal_function<T, Args...> slot_func_ptr)
            : class_ptr(class_ptr), slot_func_ptr(slot_func_ptr){}

    bool operator==(T* ptr)
    {
        return class_ptr == ptr;
    }
    bool operator==(signal_function<T, Args...> func)
    {
        return slot_func_ptr == func;
    }
private:
    virtual void run(Args... args) final
    {
        (class_ptr->*slot_func_ptr)(args...);
    }

private:
    T* class_ptr;
    signal_function<T, Args...> slot_func_ptr;
};

template< typename...Args>
class TanSignal
{
public:
    using slot_func = void(*)(Args...);
public:
    std::vector<TanSlotBase<Args...>*> _slots;

    void emit(Args... args)
    {
        for(auto slot : _slots)
        {
            slot->run(args...);
        }
    }
    ~TanSignal(){
        for(auto slot : _slots)
        {
            delete slot;
        }
    }
};

template<typename SIGNAL, typename CONTEXT,typename ...Args>
void connect(SIGNAL* signal, CONTEXT* context, signal_function<CONTEXT, Args...> slot)
{
    signal->_slots.push_back(new TanSlot<CONTEXT, Args...>(context, slot));
}

template<typename SIGNAL, typename CONTEXT,typename ...Args>
void disconnect(SIGNAL* signal, CONTEXT* context, signal_function<CONTEXT, Args...> slot)
{
    for(auto iter = signal->_slots.begin(); iter != signal->_slots.end(); iter++)
    {
        TanSlot<CONTEXT, Args...>* p_slot = (TanSlot<CONTEXT, Args...>*)*iter;
        if(*p_slot == context && *p_slot == slot)
        {
            delete p_slot;
            signal->_slots.erase(iter);
            break;
        }
    }
}


#endif //PROJECT_7_TANMETAOBJECT_H
