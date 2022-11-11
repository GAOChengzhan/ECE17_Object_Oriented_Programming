//
//  stack.hpp
//  Assignment4
//


#ifndef stack_h
#define stack_h

namespace ECE17 {
    template<typename T>
    class Stack {
    public:
        Stack(){}
        Stack(const Stack &aStack){
            items=aStack.items;
        }
        ~Stack(){
        }
        Stack &push(const T &anItem) {
            items.append(anItem);
            return *this;
        }

        T &peek() {
            if (items.size()==0){
                throw std::out_of_range ("Out of Range!");
            }
            else{
                return items.last()->value;
            }
        }

        void pop() {
            if (items.size()==0){
                throw std::out_of_range ("Out of Range!");
            }
            T last=items.last()->value;
            items.remove(last);
        }

    private:
        LinkedList <T> items;
    };
}
#endif /* stack_h */