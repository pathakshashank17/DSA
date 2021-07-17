#include <bits/stdc++.h>

using namespace std;

struct MaxPriorityQueue {
    vector<int> arr;
    int len;
    MaxPriorityQueue(int n = 0) {
        arr = vector<int>(n + 1);
        len = n;
    }
    void maxHeapify(int index) {
        int left = 2 * index, right = 2 * index + 1;
        int largest = index;
        if (left <= len && arr[left] > arr[largest])
            largest = left;
        if (right <= len && arr[right] > arr[largest])
            largest = right;
        if (largest != index) {
            swap(arr[largest], arr[index]);
            maxHeapify(largest);
        }
    }
    int front() {
        if (len < 1)
            return -1;
        return arr[1];
    }
    int pop() {
        if (len == 0)
            return -1;
        int res = arr[1];
        swap(arr[1], arr[len--]);
        maxHeapify(1);
        return res;
    }
    bool upd(int index, int val) {
        if (val < arr[index])
            return false;
        arr[index] = val;
        while (index > 1 && arr[index] > arr[index / 2]) {
            swap(arr[index], arr[index / 2]);
            index /= 2;
        }
        return true;
    }
    void push(int val) {
        len++;
        arr[len] = INT_MIN;
        upd(len, val);
    }
};

int main() {
    int task;
    MaxPriorityQueue pq;
    while (1) {
        cin >> task;
        // front()
        if (task == 1) {
            cout << pq.front() << endl;
        }
        // pop()
        else if (task == 2) {
            cout << pq.pop() << endl;
        }
        // upd()
        else if (task == 3) {
            int index, val;
            cin >> index >> val;
            pq.upd(index, val);
        }
        // push()
        else if (task == 4) {
            int val;
            cin >> val;
            pq.push(val);
        }
        // invalid
        else
            break;
    }
    return 0;
}