#include <iostream>
using namespace std;

struct Process
{
    int pid;

    int arrivalTime, burstTime, priority;

    int remainingTime;
    bool started;

    int waitingTime, turnaroundTime, completionTime, responseTime;

    Process* next;
};


class LinkedList
{
private:
    Process *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int id, int at, int bt, int pr)
    {
        Process* newNode = new Process();

        newNode->pid = id;
        newNode->arrivalTime = at;
        newNode->burstTime = bt;
        newNode->priority = pr;

        newNode->remainingTime = bt;
        newNode->started = false;

        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Process* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    Process* getHead()
    {
        return head;
    }
};


class Queue
{
private:
    Process *front;
    Process *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(Process *p)
    {
        p->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }

    Process* dequeue()
    {
        if (front == nullptr)
            return nullptr;

        Process* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        return temp;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};


class Stack
{
private:
    Process *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(Process *p)
    {
        p->next = top;
        top = p;
    }

    Process* pop()
    {
        if (top == nullptr)
            return nullptr;

        Process* temp = top;
        top = top->next;
        return temp;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};


struct Gantt
{
    int pid;
    int startTime;
    int endTime;
};

class CPU
{
public:
    int currentTime;
    Process *runningProcess;

    CPU()
    {
        currentTime = 0;
        runningProcess = NULL;
    }
};


// SCHEDULER BASE

class Scheduler
{
protected:
    LinkedList *processList;
    Queue readyQueue;
    Stack completedStack;
    CPU cpu;

    float totalWaitingTime;
    float totalTurnaroundTime;

public:
    Scheduler(LinkedList *list)
    {
        processList = list;
        totalWaitingTime = 0;
        totalTurnaroundTime = 0;
    }

    virtual void schedule() = 0;
};

class FCFS : public Scheduler
{
public:
    FCFS(LinkedList *list) : Scheduler(list) {}

    void schedule() override
    {
    
    }
};

class SJF : public Scheduler
{
public:
    SJF(LinkedList *list) : Scheduler(list) {}

    void schedule() override
    {
        
    }
};

class RoundRobin : public Scheduler
{
private:
    int timeQuantum;

public:
    RoundRobin(LinkedList* list, int tq) : Scheduler(list)
    {
        timeQuantum = tq;
    }

    void schedule() override
    {

    }
};

int main()
{
    LinkedList processList;

    processList.insert(1, 0, 5, 2);
    processList.insert(2, 1, 3, 1);
    processList.insert(3, 2, 8, 3);

    FCFS scheduler(&processList);
    scheduler.schedule();

    return 0;
}