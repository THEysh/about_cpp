#include <vector>
#include <utility>

template<typename T, typename ...Args>
using signal_function = void(T::*)(Args...); //定义槽函数
template <typename ...Args>
struct TanSlotBase
{
    virtual void run(Args...) = 0;
};

template<typename T, typename ...Args>

class TanSlot : public TanSlotBase<Args...>
{
public:
    TanSlot(T* class_ptr, signal_function<T, Args...> slot_func_ptr){
        this -> class_ptr = class_ptr;
        this -> slot_func_ptr = slot_func_ptr;
    }
private:
    T* class_ptr;
    signal_function<T, Args...> slot_func_ptr;
    void run(Args... args)
    {
        (class_ptr->*slot_func_ptr)(args...);
    }

};

template< typename...Args>
class TanSignal
{
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

