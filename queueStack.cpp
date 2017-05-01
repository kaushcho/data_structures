#include "queueStack.hpp"

Queue::Queue()
{
    data = 0;
    prev = NULL;
    next = NULL;
    std::cout << "In Queue's constructor" << std::endl; 
}

void Queue::enqueue(container *elem)
{
}

int main()
{
    std::cout << "In main" << std::endl;
    Queue newQueue;
    
    container newContainer;
    return 0;
}
