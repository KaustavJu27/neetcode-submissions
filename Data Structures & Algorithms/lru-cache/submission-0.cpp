class LRUCache {
   public:
    // Doubly Linked List Node
    class Node {
       public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;  // key -> node

    Node* head;  // Dummy head
    Node* tail;  // Dummy tail

    // Constructor
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head (Most Recently Used)
    void addNode(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    // Remove a node from the linked list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Return value if key exists
    int get(int key) {
        // Key not found
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        // Move accessed node to front
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    // Insert or update key-value pair
    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        // Cache full
        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        addNode(newNode);

        mp[key] = newNode;
    }
};