# FA22-PA3
Getting started with LinkedLists

## - Introduction

In this assignment, you will implement a Linked-List class that is capable of holding simple integers. 

As we discussed, a linked-list is dynamic collection class, that can contain an arbitrary number of homogenous elements.  You might use a LinkedList to store a collection of integers, for example, but you're more likely to store a collection of objects. Unlike an array, a LinkedList does not store information in contiguous blocks of memory. While an array offers direct (constant time) access to any member element, the addressing scheme of a LinkedList requires iteration of the chain of "linked" Nodes in order to access the element you've requested (in linear time). Prepending an object to a LinkedList (adding an item to the beginning of the list) is fast (constant time), but **appending** an item to a Linked-List (adding an item to the end of the list) first requires traversal of the chain of Nodes to retrieve that last stored item.  A new Node is appended to the last Node in the chain. Therefore, appending items is slower than prepending items (linear time). The time it takes to insert items in a Link-List falls somewhere in the middle of these two extremes. 

## - Project Files 

You'll notice that for this assignment, there are only two source files:

```
main.cpp   -- which holds your startup code and testing logic
LinkedList.hpp  -- which will contain ALL of your LinkList code
```

## - Part 1 - Implementing the nested `Node` struct 

Before you can implement a LinkedList, you'll need a data structure to hold your actual data and manage the internal collection of elements. That struct is called a `Node`. Each `Node` will contain a pointer to the next node, and it will contain a given data value (integer). Trivial structures like this are generally built using a "struct" rather than a "class", because all struct members are public by default (and thus easier to express). Otherwise, structs and classes are identical.  Here's the starting point for your `Node` class. You may change this in any way you like.

```
struct Node {
  //Add OCF methods here... 
  
  Node *next;
  int  value;
};
```

### 1A - Define your `Node` class

To complete this step, open your `linkedlist.hpp` file, and add the `Node` struct at the top of the file (you'll see a comment). 
Make sure to think through and implement your OCF methods on the `Node` class if necessary. 

## - Part 2 - Implement Your LinkedList Class

We've given you a starting point for this assignment. Open your `LinkedList.hpp` class (take a look at that class now).  Here's the interface for this class:

```
class LinkedList {
public:
  
  //You'll add OCF Methods here... 
  
  Node*   first();  //retrieve first node in the list.
  size_t  size();   //return # of items in the list...
  Node*   find(const int &aValue, Node *anOrigin=nullptr);
  Node*   append(const int &aValue);
  Node*   insertAfter(const int &aValue, Node *anOrigin=nullptr);
  Node*   remove(const int &aValue);
    
protected:
  Node    *root;
  //other members?
};
```

It's important to realize that prepending, inserting, and appending operations (as well as searching and removing items) generally require distinct algorithms. They aren't complex, but they aren't particularly reusable either. We'll find ways to redesign and improve on this in a later assignment.

### 2A - Implement OCF methods for the LinkedList class
You know the drill.  Think through and, if necessary, add the OCF methods to your `LinkedList` class, and make sure they're fully implemented.  HINT: You might wait until after you've completed some of the methods below to actually _implement_ your `copy-ctor` and `operator=`, since they might make good use of other code you haven't written yet.  :)

### 2B - Implement the `first` method for the `LinkedList` class

One of the easiest methods to implement. When called this method will return the `root` pointer stored in your `LinkedList` object.   If your `LinkedList` is empty, the `root` pointer will be a `nullptr`, otherwise, it will point to the first `Node` object in your list. 

### 2C - Implement the `size` method for the `LinkedList` class

When called, this method will return the current number of `Nodes` that are linked together in your list (starting with `root`). To provide an actual count, you could iterate all the `Nodes` in your list and count how many you encounter. But a better way is to maintain an internal variable (`count`). Whenever someone calls `insertAfter`, `append`, or `remove`, update the `count` variable incrementally.  You're free to implement this any way you like.

### 2D - Implement the `find` method for the `LinkedList` class

The `find(const int &aValue, Node* anOrigin)` method is used to search your `LinkedList` to find a `Node` that contains a given value. If found, return a pointer to the first `Node` found that contains the search value. Note that your list may contain more than one `Node` with the given value.  The 2nd argument provided to this method indicates a `Node` in your list where your search should begin. If the user calls this method with a `nullptr` value, it means to start the search from the root of your list.  If a non-null value is passed, it means you start your search at the given `Node`. If the value is not found, then return a `nullptr`.

### 2E - Implement the `append` method for the `LinkedList` class

The `LinkedList::append(const int &aValue)` method allows a user to add a new value to the **END** of the Linked-List.   The algorithm for appending an item to the LinkedList depends on whether your list is empty. If the list IS EMPTY, then appending an item is the same as adding your first item to the list. Set your root pointer equal to the newly created Node. If your list is NOT empty, you need to append you new `Node` the last item in the sequence of `Node`s your `LinkedList` object already contains. That requires you traverse the `Node` list to find the last one. Then link the last `Node` with your new `Node` (via the `next` pointer). Return a pointer to the new `Node`.

### 2F - Implement the `insertAfter` method for the `LinkedList` class

The `LinkedList::insertAfter(const int &aValue, Node *anOrigin)` method allows you to insert a new `Node` after another `Node`, already in the list. If the user calls this method and passes `nullptr` as the `anOrigin` value, the new item should be inserted at the **front** of the list.  Otherwise, this method may insert a `Node` between two existing `Node` objects in the list, or, after the **last** `Node` in your list (an edge case).

There are three cases to consider when writing this logic. First, what to do if someone call this method and passes `nullptr` as the 2nd argument. The second case relates to inserting a `Node` between two existing `Node` objects. The third case occurs if the insertion point would cause the new `Node` to be appended to the end of the list.  Our auto-testing logic will exercise each of these scenarios.

Return a pointer to the newly inserted `Node`.

### 2G - Implement the `remove` method for the `LinkedList` class

The `LinkedList::remove(const int &aValue)` method allows you to remove a `Node` that contains a given value. Begin by calling your own `find` method to locate a `Node` containing the given value. If found, remove that `Node`. Note that the return value for this method is a pointer to the removed `Node` (the caller is responsible for reusing or deleting that `Node`). If you can't find a `Node` that contains the given value, do nothing, and return `nullptr`. 

There are three cases to consider when writing this logic (presume you have a list of `Nodes` already in hand).  First, what should you do if the given value refers to the first item in your list?  Second, how do you handle removing a `Node` that exists between two other `Node` objects?  The third case occurs when a caller tries to delete the **last** `Node` in the list.  Our auto-testing logic will exercise each of these scenarios.

> NOTE: Users of your class are free to add duplicate values to the list. Therefore more than one `Node` may contain the same value.  Each call to the `remove` method will remove a maximum of one `Node` (presuming the associated value exists in your list).  If your list contains duplicates, it's up to the caller to make multiple calls to `remove`.

## - Part 3 - Add memory leak tracking for your `LinkedList` 

In this section, we'll add a tiny amount of code to enable memory-leak tracking.  Our goal is to determine whether we're properly managing dynamically allocated memory in our `LinkedList` class.   To accomplish this task, we need to declare a counter (of currently allocated `Node` objects), and a way increment or decrement that counter when `Node` objects are created or destroyed. 

Our `LinkedList` class uses dynamic memory (HEAP) when a caller tries to `append`, `insert` or `remove` `Node` objects. Since each of these operations involve a `Node` object, it may be easiest to accomplish this task by overloading the `new` and `delete` operator for the `Node` class itself.  

This code will involve two idioms we've already discussed in class:
1. overloading the `new` and `delete` operators on a per-class basis
2. using a static data member for the `Node` class

### - 3A -- Overload `new` and `delete` on the `Node` class

Add the following two methods to the `Node` class:

```
void * operator new(size_t size) {
  nodeCount++;
  return ::new Node;
}
      
void operator delete(void * aNode) {
   nodeCount--;
   free(aNode);  //it's ok to call free _inside_ the delete method...
}
```

### - 3B - Add a new static data member called `nodeCount` to the `Node` class

Declare a new `nodeCount` static data member inside the `Node` class:

```
static size_t nodeCount;
```

### - 3C - Initialize the static data member `nodeCount`

At the bottom of the `linkedlist.hpp` file (but still inside the ECE17 namespace) add the following static data member initializer:

```
  size_t Node::nodeCount = 0; //initialize static member...
```

## - Testing your Code

How do we ensure that the code we write is correct? If you're lucky, we can compare our implementation against another implementation and compare results. That's what' we're going to do here.

It turns out the STL (standard template library) has a LinkedList class called "list".  In a test of each of our methods, we will will compare our results those provided by the `STL List` class. This work has already been done for you in two methods you'll find in the `main.cpp` file. The `doBasicTest` function performs specific tests against your class to ensure that basic functionality is working.  The `doRandomTests()` function performs a large number of random operations on your list, acting as a stress-test. In both cases, we the tests also check for memory leaks.

In your `main.cpp`, we've provided a very simple testing framework to test the basic functionality of your `LinkedList`. Checkout the `runCountTests()` function to see how to build a small (but useful) test of a given feature (count). You can use this example to complete the tests for `prepend()`, `append()` and `remove()` methods of your `LinkedList` class. 

The autograder calls both `doBasicTest` and `doRandomTest`.  The autograder will run your code twice, passing a command line argument ("basic" or "random") to invoke the associated test.  If your code works, the test will output a message like, "Passed xxxxx test".  You are free to add your own additional tests to `main()`. 

FYI: Our reference implementation is about 130 lines of code. Does that seem like a lot to you?

