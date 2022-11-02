# FA22-Assignment1
## Getting started with classes, the OCF, and basic stream I/O 
### Due Friday, October 7, 2022, 11:30p (PST)

This assignment will focus on the object lifecycle: creating, using, and destroying basic objects in C++.  The objective is for you to begin to understand how to model a real-world problem in C++, and to use proper technique to implement that model. We'll also get started with basic stream I/O in a very small testing framework.

> **NOTE:**  When you first consider this assignment, it can feel like it's "a lot".  Most of the discomfort you're going to feel is due to the fact that you haven't worked with C++ classes before.  **DON'T PANIC!**  Most of what you're going to implement are simple (standard) OCF methods. Additionally, we are going to talk through many of these issues during lecture and discussion section this week. You will get much more out of lecture and discussion if you've started to think and plan out potential solutions as soon as possible!

#### Orthodox Canonical Form

During lecture we emphasized that every class has to implement four required methods (the OCF) in order to meet requirements of the C-Runtime.  In this assignment, we'll work with code for an imaginary card game. You'll notice you have several classes files (in pairs):

```
  Card.hpp/Card.cpp
  Deck.hpp/Deck.cpp
  Game.hpp/Game.cpp
  Hand.hpp/Hand.cpp
  Player.hpp/Player.cpp
```

You'll declare and define the standard (OCF) methods for these classes in their respective .hpp and .cpp files.  You will also implement a few other methods for your classes in order to make your code meet specific objectives. Then you'll finish up with some code to help test your solution.  Generally speaking, the classes associated with this assignment will make up the core of a simple "card game".  Below is a "fancy" way of showing your cards -- but your version doesn't have to be fancy!

```
┌──┐ ┌──┐ ┌──┐ ┌──┐
│A♠│ │A♥│ │A♣│ │A♦│  
└──┘ └──┘ └──┘ └──┘
```

> While we provide some starter code, the key class files are mostly empty. It's up to you to complete these according to the requirements below.

## Review -- Implement the OCF methods for your core classes

Code tells a story, and the lifecycle of every object does too. In the beginning stage, we have allocation and initialization. Initialization happens only once when the object is first created, and you perform the necessary initialization steps in one of the class constructors. This is done to prepare the object for use.

You'll implement the following methods for each class:
```
1. default constructor
2. copy constructor
3. destructor
4. assignment operator
```


> NOTE: When you first try to compile (or test) your code, you'll notice that it won't compile. That's because many methods you are expected to write haven't been implemented. Once you've provided partial implementations, your code will compile.


### Default Constructor

The code for each class is typically contained within partial files: `xxx.hpp` and `xxx.cpp`.  We refer to the `.hpp` file as your _header_, and the `.cpp` file as your _implementation_. You are responsbile for writing the code in both of these files, and for writing code that compiles and runs correctly. The `.hpp` file contains the _declaration_ for a class, whereas the `.cpp` file is where you _define_ (implement) the class. 

For each of the classes in your project folder (card, deck, game, hand, and player), you need to declare/define a __default__ constructor. Recall that the signature for a default constructor either has zero arguments, or it can have one or more arguments, all of which have a default value.

```
class ExampleClass {
public:
   ExampleClass(); //look at me -- I have 0 arguments
};
```

Declare your default constructors in the .hpp file, and define (implement them) in the .cpp file. The implementation needs to initialize and data members that each class contains.


```
  ExampleClass::ExampleClass() {
    //initialize your data members here...
  }
```

### Copy Constructor

For this part, you will add a copy constructor to each of the classes in this assignment. The copy constructor is required by the C++ standard for OCF, so that objects may be constructed (cloned) from other objects of the same or a compatible type.  Like the default constructor, the copy constructor for a class matches the name of the class. The copy constructor accepts a single parameter, that is a __const__ reference to an object of your class. We provide examples in lecture 2 and 3, but here's the basic prototype for your copy constructor for the `ExampleClass`:

```
class ExampleClass {
public:
   ExampleClass(const ExampleClass &aCopy);  //can you explain why we pass a CONST reference?  (There are two parts to the answer)
};
```

Declare the copy constructors in the .hpp file, and define (implement) them in the .cpp file.

```
  ExampleClass::ExampleClass(const ExampleClass &aCopy) {
    //copy properties from aCopy into your local (in-scope) class...
  }
```


### Destructor

For this part, you will declare and define the destructor for the 5 classes in your project folder. The destructor is required by the C++ standard (OCF), so that objects may be properly destroyed/deconstructed at the end of their lifecycle.  A destructor shares the name of the class, preceded by a tilde character (~). 

```
class ExampleClass {
public:
   ~ExampleClass();
};
```

Declare your destructors in the .hpp file, and define (implement it) in the .cpp file.

```
  ExampleClass::~ExampleClass() {
  }
```

### Assignment operator (=)

For this part, you will declare and define the assignment operator for each of the classes in your project folder. The assignment operator is required by the C++ standard (OCF), so that objects may be properly assigned to other instances of that class type. You'll recall from lecture, that constructors are only called at the start of the object lifecycle when an object "comes into existance".  The assignment operator, on the other hand, can only be used once an object exists, and is used to assign the contents of one (pre-existing object) to another.

```
class ExampleClass {
public:
   ExampleClass& operator=(const ExampleClass& aCopy); //why do we return a reference in this method?
};
```

Declare your assignment operators in the .hpp file, and define (implement) them in the .cpp file.

```
  ExampleClass& ExampleClass::operator=(const ExampleClass &aCopy) {
    //add code here to copy the properties found in aCopy into your local object
    return *this;
  }
```


## Adding data members and methods

Now it's time to add our data members and methods to the custom classes in this assignment.  First, let's review how to add data members and methods to a sample class:

#### Example data members...

Notice the declaration of the _value_ and _price_ fields in the interface file `(ExampleClass.hpp)` below:

```
class ExampleClass {
public:
   ExampleClass(); //our default ctor() [other methods removed for clarity] 
        
   void setValue(int aValue); //this is how you declare a method that 'sets' an object data member

protected:
   int   value;  //this is an example of a protected field that acts as a data member
   float price;  //this another data member
};
```

### Challenge 1: Card Class 

The `Card` class needs to track the _face_ and the _suit_ for each card it represents. We've implemented most of this for you, as an example. However, you'll still have to teach the `Card` class how to output itself to a stream for viewing.

#### Add `Card` data members...

Notice that we already added the _suit_ and _face_ data members to the `Card` class header file `(card.hpp)`

#### Implement `Card` methods

Yay -- good news, nothing to implement on `Card` class. But take a moment to read the `Card.cpp` file - in particular, `operator<<` where the `Card` can show itself on the terminal. Take a moment to figure out what's going on there.

### Challenge 2: Hand Class 

The `Hand` class is a container of a small number of `Cards` objects, assigned to a given `Player`.  Notice that a `Hand` and a `Deck` both contain a set of `Card` objects. Perhaps there is a way to take advantage of that fact.  (hint hint)

As in the case of the `Deck` class, you'll need to choose a data structure to hold the cards that a given player has at the moment. In most card games, a `Hand` can contain a limited number of cards; the actual number is game dependent. In our example game, we expect the `Hand` to hold up to 5 cards.  You could use an array, but you might just want to explore "container classes in STL", such as a `vector` or a `deque`.  We'll go into these classes in great detail during this term. For now, maybe find something that makes sense to you, based on your understanding of basic card games. For example, we need to be able to add/remove cards from a `Hand`, as well as get a `Card` count.  Eventually, we'lll need to be able to search the `Cards` in your hand.  


#### Add `Hand` data members

You need to declare the `Hand` class in the `Hand.hpp` file as you have done with your other classes.  Each `Hand` object should contain a small collection of `Card` objects. Add a data member the `Hand` class for this purpose.  We recommend that you consider using an STL collection class for this purpose (e.g. `vector` or `deque`). No worries if you don't know what that is just yet.  We'll discuss this during lecture this week.

#### Add `Hand` methods

1. Update your `constructor()` and `copy constructor()` to properly initialize your `Card` collection data member
2. Add an `bool addCard(const Card &aCard)` method to the `Hand` class. Return true if it succeeded, false if it failed.
3. Add a `CardOpt discard(Faces aFace, Suits aSuit)` method to the `Hand` class. Return card if hand contains card, std::nullopt otherwise.
4. Add a `size_t count()` method to the `Hand` class that returns the number of `Card` objects the `Hand` contains.
5. Add a `bool contains(const Card& aCard)` method to the `Hand` class to determine if the `Hand` contains the given `Card`. 
6. Declare (.hpp) and implement (.cpp) the "stream inserter" method (<<) to show your `Hand`:
```
friend std::ostream& operator<<(std::ostream &anOutput,const Hand &aHand);
```

Since a `Hand` is a collection of `Card` objects, maybe you can reuse the `Card` method we provided to show a given `Card`, when you're asked to show your `Hand`. 

The purpose of most of these methods is pretty obvious. The last method (operator<<) is used to print the `Hand` to a stream (like the console). 


If you have a hard time outputing cards as shown above,  you can use a simpler format like this:
```
2H, QC, 4D, TS   (H=hearts, C=clubs, D=diamonds, S=spades) --  (T=ten, J=jack, Q=queen, K=king)
```

### Challenge 3: Deck Class 

#### Add a data member that represents a container of Card objects

The `Deck` class will initially hold a set of 52 `Card` objects.  When a deck is created, it needs to automatically add all the cards to its internal collection. By default, the cards are ordered (low to high) by suit:  CLUBS, SPADES, HEARTS, DIAMONDS. Update your constructor so that the `Deck` contains all 52 cards (after you add data members to hold the cards below). 

#### Add `Deck` data members...

Add a data member to your `Deck` class (in the header file) that contains all 52 cards (the data structure you choose for this is up to you. You *could* use and array -- but you really shouldn't. (Why?)  Instead, consider STL containers like vector, list, or set.  We're going to explore STL quite a bit this term. If you're really stuck, consider the "stl::deque" class. 

#### Add `Deck` methods...

Now declare the following methods in your `Deck` header file, and add an "empty" definition for each method in the `Deck.cpp` file. An _empty_ definition is a regular function/method where the code block `{...}` has no code just yet.

1. declare the `Deck` class in the `.hpp` file (should already be done)

2. Add a method called `void shuffle()` that can randomize the collection of `Card` objects in the `Deck` object

3. Add a method called `CardOpt take()` that removes the first/top `Card` from the `Deck` (used when dealing cards). Return an actual `Card` from the `Deck` if the `Deck` is not empty -- otherwise return `std::nullopt` (as discussed in class) - indicating there were not available cards to take.

4. Add a method called `bool discard(Card &aCard)` that pushes a `Card` object to the end (bottom) of the `Deck`. This method returns `true` if it successfully pushes a `Card` onto the `Deck`. This code will copy the given `Card` (aCard) into your data member that contains a list of `Cards`. What should happen if a user tries to discard the same `Card` more than once?

5. Add a method called `size_t count()` that returns the number of cards in the `Deck`. 

6. In your `Deck` constructor, you will add 52 cards to your deck; this includes the 13 `Face` cards for each of the four `Suits` (like a regular deck of cards). You may add these cards to your `Deck` in any order -- but it's common to iterate the faces and suits such that the cards in the `Deck` are semi-ordered.

6. Declare (.hpp) and implement (.cpp) the "stream interter" method (<<) to show your `Deck`:
```
friend std::ostream& operator<<(std::ostream &anOutput,const Deck &aDeck);
```

### Challenge 4: Player Class 

A `Player` class tracks each player of your game. This includes the `Card` objects they hold in the `Hand`, their current score (points), and their `name`. 

#### Add `Player` data members

1. Add a `name` data member to the `Player` class (for identification purposes) - should hold string data
2. Add a `Hand` data member to the `Player` class

Don't forget to initialize your data members in your ctor(). 

#### Add `Player` methods

Add the following methods to your `Player` class:

```
  const char* getName(); //get the player name
  void setName(const char* aName); //set the player name   
  friend std::ostream& operator<<(std::ostream &anOutput,const Player &aPlayer);
```

### Challenge 5: Game Class 

The `Game` class is the "top-level" contoller in this assignment. The `Game` class contains one `Deck`, and two `Player` objects.  This class provides a _starter_ class definition in the `Game.hpp` file. You can use this as a reference for the other classes you are defining and declaring.

#### Add `Game` data members

1. Add a `Deck` object as a data member of the `Game` class
2. Add two `Player` objects (player1, player2) as data members of the `Game` class

Make sure these members are properly initialized in your `Game` class constructors

#### Add `Game` methods

For now, we're just going to get our `Game` ready to play, by implementing the OCF methods.

And, like before, don't forget to initialize your data members (`deck`, `player`, `player2') in your ctors()


## Getting things to compile

So far -- we've written very little code for our main class files. Most of this is very standard (_boilerplate_) code you'll see in nearly every class you write.  Now it's time to get our code to compile. 

This version of your game won't really do much. In fact, the only code that actually "runs" is a method on your `Game` called `willStartGame()`. This is called for you in your `main.cpp` file, after do run the testing code. 

> Be patient. This can take some time the first time you try it in C++!

Getting all your C++ code to compile can be a challenge at first. One of the main reasons for this is that the error messages 
and warnings that C++ emits and it works can be very confusing. 

#### A few guidelines for getting your code to compile

1. Work incrementally. Be aware that if you get _many_ errors all at once, and many are _false indicators_ that occur because of prior errors. 
2. Make sure all your classes have implemented _all_ the methods required by the OCF 
3. Try working in one class file at a time, until you get that one to compile.
4. It's totally cool to ask a coding buddy to help you understand the errors you're seeing. Just don't ask for help writing (or fixing) the code itself.

##  Testing 

It's time to put your classes to use, and exercise their many features. In your `main()` function, you'll see we've provided testing code. Our auto-grader uses this logic to test your code. You can use it locally too -- by passing a command line argument to your program when you run it in your IDE (or on the command line).


## EXTRA Challenge 6 -- Adding Behaviors to the `Deck` class

In this final part, if you'd like to push yourself beyond the required assignment -- you will add two new behaviors to the `Deck` class. 

### Part 6A

In this part, you will implement a `Deck::shuffle()` methods that randomly reorders all the `Cards` in the given `Deck`. You may do this by writing the shuffling method yourself (yuck), or rely on algorithms found in the STL to do this for you. (hint hint). The `Shuffle` method may be called at any time (after the `Deck` constructor has been called), and as often as a given user would like. Make sure you code does a reasonable job of randomizing the cards in the deck after calling `shuffle()`. 

### Part 6B

In the final challenge, you will implement the `Deck::show(ostream &anOutput)` method.  This method will iterate the `Cards` in the `Deck` in sequential order, and print them out on the terminal.  For example, assume my `Deck` contained four `Cards` `(8♠ 10♥ 3♣ 10♦)` (for the sake of brevity).  Calling the `Deck::show()` method will cause them to be printed to the given output stream in this manner (all on one row):

```
┌──┐ ┌──┐ ┌──┐ ┌──┐
│8♠│ │T♥│ │3♣│ │T♦│  
└──┘ └──┘ └──┘ └──┘
```

> Please note that the symbol for a face value of 10 is 'T' (see above).  

If you have a hard time outputing cards as shown above,  you can use a simpler format like this:
```
2H, 3C, 4D, 5S   (H=hearts, C=clubs, D=diamonds, S=spades)
```

## Turn in your work by 11:30pm, Friday, October 7, 2022 

To test locally, we suggest you build a test project (like we did for Assignment #0) using your IDE. 

Once your code is completed and tested, you can check it back in to github to complete your assignment. 

If you're really stuck -- visit office hours and/or ask a question on the Discussion boards!
