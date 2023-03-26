#include <iostream>
#include <Windows.h>
#include<stack>
using namespace std;

class CircularQ {
	int front;
	int rear;
	int size;
	int* arr;
public:
	CircularQ() {
		front = rear = -1;
		size = 10;
		arr = new int[size];
	}
	CircularQ(int x) {
		front = rear = -1;
		size = x;
		arr = new int[size];
	}
	bool isEmpty() {
		return -1==front && rear == -1;
	}
	bool isFull() {
		return (rear + 1) % size == front;
	}
	void enqueue(int x) {
		if (isFull()) {
			cout << "<< Maximum orders have been placed! >>" << endl;
			return;
		}
		if (isEmpty())
			front = rear = 0;
		else
			rear = (rear + 1) % size;
		arr[rear] = x;
		cout << "<< Order #" << x << " has been placed! >>" << endl;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "<< No Orders Found >>" << endl;
			return -1;
		}
		int x = arr[front];
		if (front == rear)
			front = rear = -1;
		else 
			front = (front + 1) % size;
		cout << "<< Order #" << x << " has been served! >>" << endl;
		return x;
	}
	void display() {
		if (isEmpty()) {
			cout << "<< No Pending Orders >>" << endl;
			return;
		}
		cout << "Orders: ";
		int i = front;
		while (i != rear) {
			cout << "#" << arr[i] << " ";
			i = (i + 1) % size;
		}
		cout << "#" << arr[rear] << " ";
		cout << endl;	
	}
};

struct Order {
	int order;
	int age;
};

class PriorityQ {
	Order* order;
	int size;
	int front;
	int rear;
public:
	PriorityQ() {
		size = 10;
		order = new Order[size];
		front = rear = -1;
	}
	PriorityQ(int x) {
		size = x;
		order = new Order[size];
		front = rear = -1;
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	bool isFull() {
		return size - 1 == rear;
	}
	void display() {
		if (isEmpty()) {
			cout << "<< No Pending Orders >>" << endl;
			return;
		}
		else {
			cout << "Orders: " << endl;
			for (int i = front; i <= rear; i++) {
				cout << " #" << order[i].order << " || age: " << order[i].age << endl;
			}
		}
	}
	void shiftRight(int i) {
		order[i + 1].order = order[i].order;
		order[i + 1].age = order[i].age;
	}
	void enqueue(int x, int a) {
		if (isFull()) {
			cout << "<< Maximum orders have been placed! >>" << endl;
			return;
		}
		else {
			if (isEmpty()) {
				front = rear = 0;
				order[rear].order = x;
				order[rear].age = a;
			}
			else {
				bool enq = false;	//check for if value was inserted or not
				for (int i = rear; i >= 0; i--) {
					if (a > order[i].age) {
						shiftRight(i);
					}
					else {
						order[i + 1].order = x;
						order[i + 1].age = a;
						enq = true;
						break;
					}
				}
				if (!enq) {
					order[0].order = x;
					order[0].age = a;
				}
				rear++;
			}
			cout << "<< Order #" << x << " has been placed! >>" << endl;
		}
	}
	void shiftLeft() {
		for (int i = front; i <= rear; i++) {
			order[i - 1].order = order[i].order;
			order[i - 1].age = order[i].age;
		}
		rear--;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "<< No Pending Orders >>" << endl;
			return -1;
		}
		else {
			int x = order[front].order;
			if (front == rear)
				front = rear = -1;
			else
				shiftLeft();
			cout << "<< Order #" << x << " has been served! >>" << endl;
			return x;
		}
	}
};

class Deque {
	int front, rear;
	int size;
	int* arr;
public:
	Deque() {
		size = 10;
		arr = new int[size];
		front = rear = -1;
	}
	Deque(int x) {
		size = x;
		arr = new int[size];
		front = rear = -1;
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	bool isFull() {
		return front == 0 && rear == size - 1;
	}
	void pushEnd(int x) {
		if (isFull()) {
			cout << "<< Maximum orders placed!" << endl;
			return;
		}
		if (isEmpty())
			front = rear = 0;
		else if (rear != size - 1)
			rear++;
		else
			shiftLeft();
		arr[rear] = x;
		cout << "<< Order #" << x << " has been placed!" << endl;
	}
	void pushStart(int x) {
		if (isFull()) {
			cout << "<< Maximum orders placed!" << endl;
			return;
		}
		if (isEmpty())
			front = rear = 0;
		else if (front == 0)
			shiftRight();
		else
			front--;
		arr[front] = x;
		cout << "<< Order #" << x << " has been placed!" << endl;
	}
	int popEnd() {
		if (isEmpty()) {
			cout << "<< No Pending Orders To Be Served >>" << endl;
			return -1;
		}
		int x;
		if (front == rear) {
			x = arr[front];
			front = rear = -1;
		}
		else {
			x = arr[rear];
			rear--;
		}
		cout << "<< Order #" << x << " has been served!" << endl;
		return x;
	}
	int popStart() {
		if (isEmpty()) {
			cout << "<< No Pending Orders To Be Served >>" << endl;
			return -1;
		}
		int x;
		if (front == rear) {
			x = arr[front];
			front = rear = -1;
		}
		else {
			x = arr[front];
			front++;
		}
		cout << "<< Order #" << x << " has been served!" << endl;
		return x;
	}
	void shiftLeft() {
		for (int i = front; i <= rear; i++)
			arr[i - 1] = arr[i];
		front--;
	}
	void shiftRight() {
		for (int i = rear; i >= front; i--)
			arr[i + 1] = arr[i];
		rear++;
	}
	void display() {
		if (isEmpty()) {
			cout << "<< No Pending Orders >>" << endl;
			return;
		}
		cout << "Orders: ";
		for (int i = front; i <= rear; i++)
			cout << "#"<<arr[i] << " ";
		cout << endl;
	}
};

int main() {
	stack <int> s1;
	system("Color 0E");
	int choice;

	CircularQ c1(15);
	do {
		cout << "\n------------------ PIZZA HUT ------------------ " << endl;
		cout << "1: Place Order\t\t\t2: Serve Order\n3: Display Pending Orders\t";
		//cout << "\n5: \t\t\t6:\n7:\t\t8: \n9: ";
		cout << "0: Exit\n";
		do {
			cout << "\nChoose an option (0-3): ";
			cin >> choice;
		} while (choice < 0 || choice > 3);

		switch (choice) {
		case 0:
			break;
		case 1: {
			int order;
			cout << "Enter order number: ";
			cin >> order;
			c1.enqueue(order);
			break;
		}
		case 2:
			c1.dequeue();
			break;
		case 3: 
			c1.display();
			break;
		}
	} while (choice != 0);

	PriorityQ p1(15);
	do {
		cout << "\n--------------- PIZZA HUT (AGEIST) --------------- " << endl;
		cout << "1: Place Order\t\t\t2: Serve Order\n3: Display Pending Orders\t";
		cout << "0: Exit\n";
		do {
			cout << "\nChoose an option (0-3): ";
			cin >> choice;
		} while (choice < 0 || choice > 3);

		switch (choice) {
		case 0:
			break;
		case 1: {
			int order,age;
			cout << "Enter order number: ";
			cin >> order;
			cout << "Enter age: ";
			cin >> age;
			p1.enqueue(order,age);
			break;
		}
		case 2:
			p1.dequeue();
			break;
		case 3:
			p1.display();
			break;
		}
	} while (choice != 0);

	Deque d1(15);
	do {
		cout << "\n------------------------- PIZZA HUT (NEW) ------------------------- " << endl;
		cout << "1: Place Order From Start\t\t2: Serve Order From Start\n3: Place Order From End\t\t\t4: Serve Order From End" << endl;
		cout << "5: Display Pending Orders\t\t0: Exit\n";
		do {
			cout << "\nChoose an option (0-5): ";
			cin >> choice;
		} while (choice < 0 || choice > 5);

		switch (choice) {
		case 0:
			break;
		case 1: {
			int order;
			cout << "Enter order number: ";
			cin >> order;
			d1.pushStart(order);
			break;
		}
		case 2:
			d1.popStart();
			break;
		case 3: {
			int order;
			cout << "Enter order number: ";
			cin >> order;
			d1.pushEnd(order);
			break;
		}
		case 4: 
			d1.popEnd();
			break;
		case 5: 
			d1.display();
			break;
		}
	} while (choice != 0);
}