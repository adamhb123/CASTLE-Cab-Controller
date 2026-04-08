// Not currently used

#define MAX_QUEUE_SIZE 16

template <typename T>
struct RBQueue {
    T buffer[MAX_QUEUE_SIZE];
    int head = 0;
    int tail = 0;
};

template <typename T>
bool rbQueueIsEmpty(const RBQueue<T>& q) {
    return q.head == q.tail;
}

template <typename T>
bool enqueue(RBQueue<T>& q, const T& item) {
    int next = (q.tail + 1) % MAX_QUEUE_SIZE;

    if (next == q.head) {
        return false; // full
    }

    q.buffer[q.tail] = item;
    q.tail = next;
    return true;
}

template <typename T>
bool dequeue(RBQueue<T>& q, T& out) {
    if (q.head == q.tail) {
        return false; // empty
    }

    out = q.buffer[q.head];
    q.head = (q.head + 1) % MAX_QUEUE_SIZE;
    return true;
}