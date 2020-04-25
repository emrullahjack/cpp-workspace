#include <iostream>

using namespace std;

struct QNode {
	int data;
	QNode* next;
	
	QNode(int d) {
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue() {
		front = rear = NULL;
	}
	
	void enQueue(int x) {
		// Build a new LL node 
		QNode* temp = new QNode(x);
		
		// If queue is empty, then
		// new node is both front and rear
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		
		// add the new node at the
		// end of the queue and change rear
		rear->next = temp;
		rear = temp;
	}
	
	// Function to remove a key
	// from given queue q
	void deQueue() {
		// if queue is empty, return null
		if (front == NULL)
			return;
		
		// Store previous front and 
		// move front one node ahead
		QNode* temp = front;
		front = front->next;
		
		// If front becomes null,
		// then change rear also as null
		if (front == NULL)
			rear = NULL;
		
		delete(temp);
	}
};

// Driver program
int main() {
	Queue q; 
	    q.enQueue(10); 
	    q.enQueue(20); 
	    q.deQueue(); 
	    q.deQueue(); 
	    q.enQueue(30); 
	    q.enQueue(40); 
	    q.enQueue(50); 
	    cout << "Queue Front : " << (q.front)->data << endl; 
	    cout << "Queue Rear : " << (q.rear)->data << endl;
}