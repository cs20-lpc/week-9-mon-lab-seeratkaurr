template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    this->length = 0;
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    if (copyObj.isEmpty()) {
        head = nullptr;
        last = nullptr;
        this->length = 0;
        return;
    }

  
    head = new Node(copyObj.head->value);
    Node* currNew = head;
    Node* currOld = copyObj.head->next;

    
    while (currOld != nullptr) {
        currNew->next = new Node(currOld->value);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    last = currNew;
    this->length = copyObj.getLength();
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Queue is empty");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;

    if (this->length == 0) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);

    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }

    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return head->value;
}


