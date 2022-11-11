//
//  queue.hpp
//  Assignment4
//

#ifndef queue_h
#define queue_h

namespace ECE17 {
    template<typename T>
    class Queue{
    public:
        Queue(){}
        Queue(const Queue &aQueue){
            items=aQueue.items;
        }
        ~Queue(){}
        Queue &push(const T &aValue){
            items.append(aValue);
            return *this;
        }

        T &front(){
            if (items.size()==0){
                throw std::out_of_range ("Out of Range!");
            }
            return items.first()->value;
        }

        T &back(){
            if (items.size()==0){
                throw std::out_of_range ("Out of Range!");
            }
            return items.last()->value;
        }

        void pop(){
            if (items.size()==0){
                throw std::out_of_range ("Out of Range!");
            }
            T first=items.first()->value;
            items.remove(first);
        }
    private:
        LinkedList<T> items;
    };

}

#endif /* queue_h */

