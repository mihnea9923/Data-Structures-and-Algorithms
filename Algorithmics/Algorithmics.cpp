
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

int main()
{
    Queue q(100);
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

