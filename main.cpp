#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue {
public:
    Queue(int size);
    ~Queue();

    bool IsEmpty();
    bool IsFull();
    void Enqueue(T value);
    T Dequeue();
    T GetFront();
    T GetRear();
    void Print();
    int Capacity();
    int Size();

private:
    int front, rear, length;
    T *items;
};

template <class T>
Queue<T>::Queue(int size) : front(-1), rear(-1), length(size) {
    items = new T[length];
}

template <class T>
Queue<T>::~Queue() {
    delete[] items;
    items = nullptr;
}

template <class T>
bool Queue<T>::IsEmpty() {
    return front == -1;
}

template <class T>
bool Queue<T>::IsFull() {
    return rear == length - 1;
}

template <class T>
void Queue<T>::Enqueue(T value) {
    if (IsFull()) {
        cout << "Queue is overflow" << endl;
        return;
    }
    if (IsEmpty())
        front++;
    else
        rear++;

    items[rear] = value;
}

template <class T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is underflow" << endl;
        exit(-1);
    }

    T var = items[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return var;
}

template <class T>
T Queue<T>::GetFront() {
    if (IsEmpty()) {
        cout << "Queue is underflow" << endl;
        exit(-1);
    }

    return items[front];
}

template <class T>
T Queue<T>::GetRear() {
    if (IsEmpty()) {
        cout << "Queue is underflow" << endl;
        exit(-1);
    }

    return items[rear];
}

template <class T>
void Queue<T>::Print() {
    if (IsEmpty()) {
        cout << "Queue is underflow" << endl;
        return;
    }

    for (int i = front; i <= rear; ++i) {
        cout << items[i] << " ";
    }

    cout << endl;
}

template <class T>
int Queue<T>::Capacity() {
    return length;
}

template <class T>
int Queue<T>::Size() {
    return (rear - front + 1);
}

int main() {
    Queue<char> Q1(10);
    cout << Q1.Capacity() << '\n';
    Q1.Enqueue('Y');
    Q1.Enqueue('O');
    Q1.Enqueue('U');
    Q1.Enqueue('S');
    Q1.Enqueue('S');
    Q1.Enqueue('E');
    Q1.Enqueue('F');
    cout << Q1.Size()<<'\n';
    Q1.Print();
    return 0;
}