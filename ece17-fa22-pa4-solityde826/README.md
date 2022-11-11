# FA22 Assignment 4
Let's convert our linked-list to a template. 

## Overview

We built a pretty neat LinkedList class in Assignment 3. However, there were a few shortcomings with our previous version. For example, it could only hold values of type `int`.  In this assignment, we'll upgrade our `LinkedList` to be a **template**, so that our list can contain values of any datatype.  Next, we'll derive two new container classes -- `Stack` and `Queue` from our `LinkedList`.  Then, we'll add an iterator, so that we can use our data more effectively.

## 1. Converting the LinkedList from Assignment 3 to a template

We can convert an existing class into a template with a standard process.  As discussed in class, a **template** begins with the `template` keyword, followed by the `typename` keyword, and then a type identifier. For example, a templatized array class that holds 100 elements of any type, could be declared as shown below. 
```
template <typename T>
class Array100 {
  Array100() {} 
protected:
  T ary[100]; //holds an array of 100 elements of type T
};

int main() {
  Array100<float> theArray; //this templatized array can hold 100 floats...
}
```

Note that within this template, the identifier `T` is used as a placeholder that represents the type of data the array will contain.  Notice in our template heading `<>`, we declare a `typename T`, and then in the protected section of the class, we declare an array of 100 `T` elements.  `T` will get substituted for whatever type you actually use later (shown in the main function as `float`) in this example. So our usage here creates an array of 100 floats.


For this part of the assignment you will copy your `LinkedList` class from Assignment 3 into this current assignment.  We're going to convert your `LinkedList` into a template.

### 1A. Add the template declaration to the top of your LinkedList class 

Start by adding the template declaration at the top of your `LinkedList` class (see prior example). Use the identifier `T` to indicate the typename. 

### 1B. Move the Node struct declaration _inside_ your `LinkedList` class as a "nested declaration"  

This won't change how your `Node` works at all, but it makes it easier for you to work with the `LinkedList` and `Node` classes.  We recommend you put this right after the `public:` access specifier in the `LinkedList` class, and before you declare your OCF methods. Technically, it really doesn't matter where you declare the `Node` class, as long as that happens before code in which you try to use it in your `LinkedList` class.

### 1C. Change the Node.value field from `int` to  `T`

This step allows your new `LinkedList` class (and `Node`) to use a generic type provided at compile-time, rather than being fixed as holding `int` values.  

### 1D. Remove New/Delete operators from Node

In this version, we won't be checking memory management. You can feel free to remove the new/delete operators from the `Node` class, and the `static nodeCount` variable we added. If you prefer to keep these in your code, of course, you may do so as they may help you test your code. But we won't be directly testing this functionality for this assignment.

Now work to get your code to compile. If you followed the steps correctly, it will just work. If not, you'll notice that error messages from templates can be quite confusing.  Be paient and make sure you've followed the instructions above correctly. 

## 2. Building a Stack class

In this step, you'll make a new `Stack` class template.  We've provided a (mostly empty) file for you for this purpose -- called Stack.hpp. 

### 2A. Start by declaring a template type for your `Stack` class

Just like we did in Step 1A, add a template declaration header to your `Stack` class. See the `Array100` sample code given above for an example.

### 2B. Add a data member called `items` that is of type `LinkedList<T>`. 

Add a data member to the `Stack` class template called `items`, of type `LinkedList<T>`. Since your `LinkedList` is now a template, you'll have to provide the datatype you want your `LinkedList` to contain. That will match the datatype specified after the `typename` keyword in your `Stack` template declaration.  (See the `Array100` example above for an example, as shown in the main() function).

### 2C. Add the following methods to your `Stack` class

Next you'll add the common `Stack` methods listed below. You'll also need to implement these in the stack.hpp file.
```
Stack& push(const T &anItem);
T& peek(); 
void pop(); 
```

When you implement these methods, you will actually just call methods on the `LinkedList<T>` data member (`items`) to actually do the work.  We say that you `Stack` "HAS-A" `LinkedList` data property.  The Stack delegates all the real work to the nested `LinkedList` object by calling `LinkedList` methods.

> NOTE: As we will discuss in lecture, your `peek` method will "throw an out-of-range exception" if your user tries to call the `peek()` method when the `Stack` is empty.

## 3. Building a Queue class

Building your `Queue` class will be similar to the steps you just took to implement your `Queue` class. 

### 3A. Start by declaring a template type

Just like we did in step 2A, add a template declaration headaer to your `Queue` class. See the `Array100` sample code given above for an example.

### 3B. Add a data member called `items` to your `Queue` class

As before, the `items` data member you add will be of type `LinkedList<T>`, so the `LinkList` type will match the type passed into the `Queue` template declaration.

### 3C. Add the following methods to your `Queue` class

```
Queue& push(const T& aValue);
T&     front();
T&     back();
void   pop();
```

As with the `Stack` class, you'll need to implement these by calling relevant methods on the `LinkedList<T>` class.

You'll need to implement these in the queue.hpp file, like you did with the `LinkedList` class.

> NOTE: As we will discuss in lecture, your `front` and `back (peeknig) methods will "throw an out-of-range exception" if your user tries to call `peekFrnot()` when the `Queue` is empty.

## 4. Implement the Visitor Pattern for your `LinkedList`

The `Visitor` pattern is used to provide a way to perform some action on all the elements in your container, without having to change your container class (`LinkedList` in this case).

### 4A. Declare the interface `INodeVisitor` 

Create an interface (class with only pure virtual methods) called  `INodeVisitor` in your linkedlist.hpp file.  Give your interface one method, called `visit` as shown below:

```
void visit(const Node& aNode) {//fill this in}
```

Soon you will sub-class this interface, and that's where the magic will happen. You'll be able to add custom functionality using all the elements in your list, without any changes to the `LinkedList` or the `Node` class.  


### 4B. Add the `visitWith` method on your `LinkedList`

Add the `visitWith` method to your `LinkedList` class.  This is where you will implement the visitor pattern. This method will "visit" all the elements in the collection, by calling operator() for each `Node` and passing along the given `InodeVisitor`.  Refer to the example we provided from the lecture. 

```
LinkedList& visitWith(INodeVisitor &aVisitor) {
  //walk through your list of nodes and call Node::operator() //function call op...
}

```

### 4C. Overload `operator()` on your Node class

The final step is to overload `operator()`. This method will accept one argument (a reference to an INodeVisitor). When called, your overloaded operator will call `visitor.visit()` and pass along the `Node` as an argument.

> Note: We test your implementation of the visitor pattern in the `doVisitorTest` method in your main.cpp.  You might find it helpful to read and understand this code!

## Testing your classes

We provide a version of `LinkedList` tests as we did in Assignment 3. We also provide simple tests for your `Stack` and `Queue` classes. 

Your code will be graded as follows:

1. compiles: 25pts
2. basic test (linkedlist): 15pts
3. random test (linkedlist): 15pts
4. stack tests: 15pts
5. queue tests: 15pts
6. visitor test: 15pts

