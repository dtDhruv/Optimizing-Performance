#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

struct node {
    int key;
    struct node *left, *right;

    // Constructor
    node(int item) : key(item), left(nullptr), right(nullptr) {}

    // Destructor
    ~node() {
        // Recursive deletion of left and right subtrees
        if (left != nullptr) {
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            delete right;
            right = nullptr;
        }
    }
};

// A function to create a new BST node
struct node* newNode(int item)
{
    return new struct node(item);
}

struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == nullptr)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

// Utility function to search a key in a BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

int main()
{
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Intertion and Searching in Binary Search Tree Starting Now: " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    struct node* root = nullptr;
    const int numElements = 40001;

    auto startInsert = high_resolution_clock::now();

    for (int i = 0; i < numElements; ++i) {
        root = insert(root, i);
    }

    auto stopInsert = high_resolution_clock::now();
    auto durationInsert = duration_cast<microseconds>(stopInsert - startInsert);
    std::cout << "-----------------------------------------------------------" << std::endl;
    cout << "Time taken to insert " << numElements << " elements: " << durationInsert.count() << " microseconds" << endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    // Search for an element in the BST
    std::cout << "-----------------------------------------------------------" << std::endl;
    cout << "Searching for 40000"<< endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    int keyToSearch = 40000;

    auto startSearch = high_resolution_clock::now();
    struct node* foundNode = search(root, keyToSearch);
    auto stopSearch = high_resolution_clock::now();
    auto durationSearch = duration_cast<microseconds>(stopSearch - startSearch);

    if (foundNode == nullptr)
        cout << keyToSearch << " not found" << endl;
    else
        cout << keyToSearch << " found" << endl;

    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    cout << "Time taken to search: " << durationSearch.count() << " microseconds" << endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "BST Implementation Over" << std::endl;
    int buff;
    std::cin>>buff;
    // Delete the BST and free memory using the destructor
    delete root;

    return 0;
}
