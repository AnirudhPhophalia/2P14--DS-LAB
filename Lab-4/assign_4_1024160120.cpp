#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// // Develop a menu driven program demonstrating the following operations on simpleQueues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#define MAX 5
class SimpleQueue {
    int arr[MAX];
    int front, rear;
public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};
int main() {
    SimpleQueue q;
    int choice, val;
    do {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

// Develop a menu driven program demonstrating the following operations on Circular Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};
int main_circular() {
    CircularQueue q;
    int choice, val;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}


// Write a program interleave the first half of the queue with second half. Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
void interLeaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Cannot interleave, queue size is odd.\n";
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf, secondHalf;

    // Dequeue first half elements
    for(int i =0; i< halfSize; i++){
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    queue<int> result;
    while (!firstHalf.empty() && !secondHalf.empty()) {
        result.push(firstHalf.front());
        firstHalf.pop();
        result.push(secondHalf.front());
        secondHalf.pop();
    }

    q = result;
}
int main_interleave() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements (even): ";
    cin >> n;
    if (n % 2 != 0) {
        cout << "Number of elements must be even.\n";
        return 0;
    }
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    interLeaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}


// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a b c Sample O/P: a -1 b b
void firstNonRepeatingCharacter(const string& str) {
    unordered_map<char, int> charCount;
    queue<char> q;

    for (char ch : str) {
        charCount[ch]++;
        q.push(ch);

        // Find the first non-repeating character
        while (!q.empty()) {
            if (charCount[q.front()] == 1) {
                cout << q.front() << " ";
                break;
            }
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        }
    }
}
int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    firstNonRepeatingCharacter(input);
    return 0;
}

// Write a program to implement a stack using 
// Stack implementation using two queues
class StackUsingTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
        swap(q1, q2);
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
// Stack implementation using one queue
class StackUsingOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main() {
    StackUsingTwoQueues s1;
    StackUsingOneQueue s2;

    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push (Two Queues)\n2. Pop (Two Queues)\n3. Display (Two Queues)\n";
        cout << "4. Push (One Queue)\n5. Pop (One Queue)\n6. Display (One Queue)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                cout << "Enter value to push: ";
                cin >> value;
                s2.push(value);
                break;
            case 5:
                s2.pop();
                break;
            case 6:
                s2.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
