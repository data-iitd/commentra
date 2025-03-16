

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A structure to represent a node in a linked list
struct Node {
	int data;
	struct Node* next;
};

// A structure to represent a linked list
struct LinkedList {
	int size;
	struct Node* head;
	struct Node* tail;
};

// Creates a new linked list and returns a pointer to it
struct LinkedList* createList() {
	struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

// Inserts a new node at the end of the linked list
void insert(struct LinkedList* list, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	if (list->size == 0) {
		list->head = newNode;
	} else {
		list->tail->next = newNode;
	}
	list->tail = newNode;
	list->size++;
}

// Deletes a node from the linked list
void delete(struct LinkedList* list, int index) {
	if (index < 0 || index >= list->size) {
		return;
	}
	struct Node* temp = list->head;
	if (index == 0) {
		list->head = list->head->next;
	} else {
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
	list->size--;
}

// Returns the value of the node at the given index
int get(struct LinkedList* list, int index) {
	if (index < 0 || index >= list->size) {
		return -1;
	}
	struct Node* temp = list->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->data;
}

// Returns the size of the linked list
int size(struct LinkedList* list) {
	return list->size;
}

// Returns the index of the first node with the given value
int indexOf(struct LinkedList* list, int value) {
	struct Node* temp = list->head;
	for (int i = 0; i < list->size; i++) {
		if (temp->data == value) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

// Returns the index of the last node with the given value
int lastIndexOf(struct LinkedList* list, int value) {
	struct Node* temp = list->tail;
	for (int i = list->size - 1; i >= 0; i--) {
		if (temp->data == value) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

// Returns the index of the node with the minimum value
int minIndex(struct LinkedList* list) {
	struct Node* temp = list->head;
	int min = temp->data;
	int index = 0;
	for (int i = 0; i < list->size; i++) {
		if (temp->data < min) {
			min = temp->data;
			index = i;
		}
		temp = temp->next;
	}
	return index;
}

// Returns the index of the node with the maximum value
int maxIndex(struct LinkedList* list) {
	struct Node* temp = list->head;
	int max = temp->data;
	int index = 0;
	for (int i = 0; i < list->size; i++) {
		if (temp->data > max) {
			max = temp->data;
			index = i;
		}
		temp = temp->next;
	}
	return index;
}

// Returns the minimum value in the linked list
int min(struct LinkedList* list) {
	struct Node* temp = list->head;
	int min = temp->data;
	for (int i = 0; i < list->size; i++) {
		if (temp->data < min) {
			min = temp->data;
		}
		temp = temp->next;
	}
	return min;
}

// Returns the maximum value in the linked list
int max(struct LinkedList* list) {
	struct Node* temp = list->head;
	int max = temp->data;
	for (int i = 0; i < list->size; i++) {
		if (temp->data > max) {
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}

// Returns the sum of all the nodes in the linked list
int sum(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

// Returns the product of all the nodes in the linked list
int product(struct LinkedList* list) {
	struct Node* temp = list->head;
	int prod = 1;
	for (int i = 0; i < list->size; i++) {
		prod *= temp->data;
		temp = temp->next;
	}
	return prod;
}

// Returns the mean of all the nodes in the linked list
double mean(struct LinkedList* list) {
	return (double)sum(list) / (double)list->size;
}

// Returns the median of all the nodes in the linked list
int median(struct LinkedList* list) {
	int mid = list->size / 2;
	if (list->size % 2 == 0) {
		return (get(list, mid) + get(list, mid - 1)) / 2;
	}
	return get(list, mid);
}

// Returns the mode of all the nodes in the linked list
int mode(struct LinkedList* list) {
	int maxCount = 0;
	int max = get(list, 0);
	for (int i = 0; i < list->size; i++) {
		int count = 0;
		for (int j = 0; j < list->size; j++) {
			if (get(list, i) == get(list, j)) {
				count++;
			}
		}
		if (count > maxCount) {
			maxCount = count;
			max = get(list, i);
		}
	}
	return max;
}

// Returns the standard deviation of all the nodes in the linked list
double stdDev(struct LinkedList* list) {
	double mean = (double)sum(list) / (double)list->size;
	double sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += pow(get(list, i) - mean, 2);
	}
	return sqrt(sum / (double)list->size);
}

// Returns the variance of all the nodes in the linked list
double variance(struct LinkedList* list) {
	return pow(stdDev(list), 2);
}

// Returns the skewness of all the nodes in the linked list
double skewness(struct LinkedList* list) {
	double mean = (double)sum(list) / (double)list->size;
	double sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += pow(get(list, i) - mean, 3);
	}
	return sum / pow(stdDev(list), 3);
}

// Returns the kurtosis of all the nodes in the linked list
double kurtosis(struct LinkedList* list) {
	double mean = (double)sum(list) / (double)list->size;
	double sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += pow(get(list, i) - mean, 4);
	}
	return sum / pow(stdDev(list), 4);
}

// Returns the median absolute deviation of all the nodes in the linked list
double medianAbsDev(struct LinkedList* list) {
	int mid = list->size / 2;
	if (list->size % 2 == 0) {
		return (double)abs(get(list, mid) - get(list, mid - 1)) / 2;
	}
	return (double)abs(get(list, mid));
}

// Returns the median absolute deviation of all the nodes in the linked list
double medianAbsDevP(struct LinkedList* list) {
	int mid = list->size / 2;
	if (list->size % 2 == 0) {
		return (double)abs(get(list, mid) - get(list, mid - 1)) / (double)list->size;
	}
	return (double)abs(get(list, mid)) / (double)list->size;
}

// Returns the range of all the nodes in the linked list
int range(struct LinkedList* list) {
	return max(list) - min(list);
}

// Returns the sum of all the nodes in the linked list
int absSum(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum;
}

// Returns the sum of all the nodes in the linked list
int absSumP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / list->size;
}

// Returns the sum of all the nodes in the linked list
int absSumS(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1);
}

// Returns the sum of all the nodes in the linked list
int absSumPS(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2);
}

// Returns the sum of all the nodes in the linked list
int absSumPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3);
}

// Returns the sum of all the nodes in the linked list
int absSumPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4);
}

// Returns the sum of all the nodes in the linked list
int absSumPPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4) / (list->size - 5);
}

// Returns the sum of all the nodes in the linked list
int absSumPPPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4) / (list->size - 5) / (list->size - 6);
}

// Returns the sum of all the nodes in the linked list
int absSumPPPPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4) / (list->size - 5) / (list->size - 6) / (list->size - 7);
}

// Returns the sum of all the nodes in the linked list
int absSumPPPPPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4) / (list->size - 5) / (list->size - 6) / (list->size - 7) / (list->size - 8);
}

// Returns the sum of all the nodes in the linked list
int absSumPPPPPPPP(struct LinkedList* list) {
	struct Node* temp = list->head;
	int sum = 0;
	for (int i = 0; i < list->size; i++) {
		sum += abs(temp->data);
		temp = temp->next;
	}
	return sum / (list->size - 1) / (list->size - 2) / (list->size - 3) / (list->size - 4) / (list->size - 5) / (list->size - 6) / (list->size - 7) / (list->size - 8) / (list->size - 9);
}

// Returns the sum of all the no