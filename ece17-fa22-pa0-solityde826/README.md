# FA22-Assignment0
## Setting Up with C++ - Due Monday, Sept 26, 11:30pm (PST)

## Preliminaries

### Setup your build environment

We will be using CLion as our IDE. You may be familiar with other IDEs, but we all want to be on the same IDE to share tips and tricks! CLion runs on MacOS, Windows, and Linux. If you have a strong desire to use another IDE, feel free to do so as long as it has an integrated debugger -- however, we may be limited in our ability to help if you get stuck.

See links and resources on TritonEd for getting setup.

Estimated newbie time: < 15 minutes.

### On Writing Code
You’re going to be writing and debugging lots of code in this class. In nearly every case, we have two objectives in mind:

1. To give you experience with the many new [idioms](https://en.wikipedia.org/wiki/Programming_idiom) in Object-oriented development with C++
2. To help you to learn to think like a software developer.

As important as learning the C++ language may be, we believe that it’s even more important that you learn the conceptual language of software design. How you think about the problems you’ll face is often the most important factor in whether you can craft a software solution.

Take time to reflect on these assignments, and consider the larger concepts — before you start writing any code. Remember that a fundamental advantage of object-oriented programming is that these techniques allow us to more easily reason about the problem space. So, take some time to consider the relationships between key elements in the problem space, and how you might synthesize them into a working model. During this phase, it’s a great idea to chat with peers and instructors on concepts you’re working through. Software design is a team sport.

Remember that while it's ok to discuss your ideas with others, it's never ok to share code or specific design details without permission. Doing so would be a violation of ethical standards of integrity you've agreed to as a UCSD student. 

### Assigned Reading (reminder)

Read chapters 1 and 2 in the textbook: C++ Primer. For the sake of improving this course, please track how much time the reading takes you.  Estimated time: 1 hour.

![alt text](/primer.png "C++ Primer")


## Assignment Details

### Overview --
In this assignment you will write a little bit of code for your first class -- called `AboutMe`.  You'll get your code to compile and run in your IDE (and on the command line if you can).  When your program runs as a "command-line" program (without a GUI), it will output information about you on the terminal. 

### Before you begin
By now, you should have installed an integrated development environment for C++ (Visual Studio, XCode, CLion, or gcc/gdb command line tools.). Generally speaking, we find that most students can complete this task in about 15 minutes. Your mileage may vary.  You may choose any IDE you like (although we provide guidance for CLion) -- so long as it has a full C++ debugger available. 

### What's included in this assignment
In your project folder, you'll find a few files:

1. main.cpp -- entry point of your program and high-level logic. You will modify this file in Part 2.
2. CMakeLists.txt -- configuration file so the IDE (or command line tools) know how to compile your code
3. `AboutMe.hpp` and `AboutMe.cpp` -- header file and implementation of the `AboutMe` class. You will modify this file in Part 1.
4. `testing.hpp` -- code for testing your implementations. You won't modify this file, but we recommend trying to read this file. Writing tests is a critical skill in software engineering and often a required first step in professional engineering environments! You probably won't understand all of the syntax in this file -- but by the end of this quarter you will.

### Part 1 - Implement the `AboutMe.cpp` methods

In this step, you will finish implementing the methods inside the `AboutMe.cpp` file, that we declared for you in your `AboutMe.hpp` file . We've setup `AboutMe.cpp` for you to make it easy to get started. All you have to do is replace the strings we provided for you with your own meanginful values.

Look for the constructor for this class, and change the default `name`, `pid` and `years_at_ucsd` data members to reflect your bio.

### Part 2 -- Implement basic looping in `main.cpp` functions

In this challenge, you're going to write three loops (`for`, `while` and `do-while`).  

Open the `main.cpp` file and look for the following functions:

```
void forTest(size_t aCount, std::ostream &anOutput);
void whileTest(size_t aCount, std::ostream &anOutput);
void doWhileTest(size_t aCount, std::ostream &anOutput);
```

Notice that each function accepts two arguments:  `aCount` and `anOutput`.  The `aCount` argument tells you how many times to iterate -- while `anOutput` is an output stream where you will write your output (in C you used `printf` for this purpose). We discussed stream output (cin/cout) in the first lecture.

In the `forTest`,  you will write a `for loop` that iterates N times (where N==`aCount`). Each time through the loop, you want to output the word "for" with the value of your for loop. Your output might look like this:

```
for 0
for 1
...etc.. 
```

Make sure to end each line with "\n", which emits a "newline". 

You'll follow the same pattern for the other two methods. In the `whileTest`, you will iterate using a "while" loop, whereas in the "dowhiletest"  you will iterate using "do-while" looping statements. 

> **NOTE:**  It is essential that your program compiles without any errors. Look at the output provided by github to confirm you have zero warnings.

### Part3 -- Check your working solution back into git 

As we’ve said in lecture, you will turn your work in using github. Github is an online code repository.  Managing code can be very confusing, but github makes the process fairly easy. And the way we’re going to handle code in this class is even simpler still.  More on that later.

With that said, please understand that when you submit your work via github, your changes are automatically timestamped. Meta data in the code repository makes it plainly obvious to humans and computers alike when your submission arrived.  This is worth mentioning, because the github timestamps on your submissions will be used to to arbitrate whether you turned your work in on time or not. 

Your homework will usually be auto-graded by “Vlad the Compiler” — otherwise known as our software-based auto-grader.  Vlad can be a bit harsh when it comes to scoring homework (see the syllabus), but he does have a somewhat casual relationship with deadlines.  During Grad-school, Vlad often spent spring-break in Cabo-San-Lucas where he learned to enjoy siestas.  Most nights, Vlad awakens from his last-afternoon siesta around midnight, to begin the process of grading your assignments. In other words, you can generally count on a 30 minute grace period for turning in your work. We strongly suggest that you do not test Vlad's patience. :)

### Part 4 -- Screenshot your IDE Running This Program

We want to make sure that everyone has their IDE installed, and can run their debugger. We'll show you how to do this in class, and in the lab on Monday if you don't already know. Do the following steps:

1. Complete Parts 1-3 above
2. Compile your Assignment0 source code
3. Run your program in the IDE
4. When the program stops (waiting for input), take a screenshot of the program running in the IDE
5. Add this image to your repository for PA 0

#### GRADING
```
Compile test: 50pts
Basic test: 50pts
```
There will be a 10% deduction if your code emits warnings.

