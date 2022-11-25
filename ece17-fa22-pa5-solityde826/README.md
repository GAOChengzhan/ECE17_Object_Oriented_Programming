# FA22 Assignment 5
##  Statistics, compression, and practice with the STL

For this assignment, we're going to use all the skills we're developing for Object-oriented design, templates, iterators, STL and algorithms. 

## Introduction

In this assignment, you will read, analyze, compress, and decompress a text file. 

There are three parts to this assignment, briefly:

1. Conducting a basic statistical analysis on the words in the given text file (measured by accuracy)
2. Implementing you own creative ideas to compress the text in the given file (measured by compression ratio % )
3. Decompressing the compressed version, to restore the file to its original form (measured by accuracy against original)

Your methods need to complete within a reasonable amount of time and the autograder will set reasonable time limits. Make sure you're using the STL, iterators, and the STL algorithms wherever possible; they will enable you to implement your designs with less code then trying to code them up by "scratch."

### Overview -- Reading the given text file

In this assignment, you will write code to analyze and compress words in a file. The `main.cpp` will measure the time your code takes to complete the assigned tasks, and measure your overall results.   You will implement various methods in this class, and you may add your own member data and methods as needed. You must implement the methods described below.

The `main.cpp` file automatically creates an input stream for your code to use for each task. The methods for each of your tasks (statistical, compression, decompression) accept an input stream that contains the file contents.

> When your program runs we use an argument passed to the app, that is the full path to the file to be used for testing. We provided a file for you called `story.txt`.  For example, on our auto-grader, the path is `./story.txt`.  On your machine the path is likely to be different (and longer).  When you're testing on your own machine, you need to pass in the full filepath for your program to work. 
 
We run each of the methods described below separately, and we will measure the time it takes for your code to complete each task.  Across all sections of the assignment, you'll write a class called `WordAnalyzer` -- that implements the following methods:

```    
    size_t countWords(std::istream &anInput, std::ostream &anOutput);
    size_t getWordPairs(std::istream &anInput, std::ostream &anOutput);
    size_t compress(std::istream &anInput, std::ostream &anOutput);
    size_t decompress(std::istream &anInput, std::ostream &anOutput);    
```

### Part 1 -- Statistical Analysis  

For this part of the assignment, your code will need to perform a statistical analysis of words in the given file.  

Assume that words break on whitespace or sentence-based punctuation. Whitespace and punctuation should be ignored, and only full words should be included. Words with embedded apostrophes are considered whole words (e.g. "isn't","don't") and should not be broken apart at the apostrophe. Also, any word wrapped in quotes ("") should have the quotes removed. So `"Hello"` becomes `Hello`.

#### Step 1A -- Counting word usage

In this step, you'll implement the `WordAnalyzer::countWords()` method, where you will count how many times each word occurs in the given file. Word comparisons are to be performed in a case-insensitive manner, so "Hello" and "hello" are equivalent. Also, words should exclude punctuation (.,!?{}[]()). You can write any code you like, but you __must__ use STL containers to store any information you need. Try to use `iterator` objects from the STL collections as much as you can (within reason).  This method will return the total number of unique words that it found.

When this method is complete, it will output the total number of words you found (shown below as NNN), followed by the list of words and their associated counts, in alphabetic order.  Make sure you output your information in the format shown below.

```
Total Words: NNN
Apple: 11
Amazon: 7
...(more here...)
```

#### Step 1B -- Counting word pairs

In this step, you will implement the method, `WordAnalyzer.getWordPairs()`. This method returns the total number of word-pairs that it found. For this purpose, we define a "word pair" as a sequence of two words in the document, separated by whitespace or punctuation.  You must ignore all whitespace and sentence punctuation (comma, exclamation mark, semi-colon, question mark, etc). However, word conjuctions are permitted (as shown in the example below for the word "isn't"). This method will scan all the word-pairs in the document, and build a usage table. Given the sentence, `the best food to eat isn't always the best food`, your output is shown below. Notice that duplicate word pairs are denoted by a count>1, and that duplicate pairs are shown only once. Make sure to output your pairs alphabetically, in the format shown below:

```
Word Pairs (9)     Count 
always the          1
best food           2
eat isn't           1
isn't always        1 
food to             1
the best            2
to eat              1
```

### Part 2 -- Compressing the input file

In this step, you will implement the method, `WordAnalyzer.compress()`. You will implement your own creative approach to compressing the underying text data. Options include (but aren't limited to) -- a substitution cypher, dictionary compression (recommended), statistical compression (like LZW or Huffman encoding), and so on. If you use a published method, you must implement your own code from scratch-- and be prepared to prove you understand it. You will build classes that perform each type of compression you use (so yes, you can do more than one type to maximize compression).

The key to success in this step is to use creativity and research to find various techniques to compress your text. We really want to see you try multiple ideas (and combinations). 

Standard compression methods can reduce text files by 75% or more. You should aim to find a way to compress the filesize by 50% or more. You're expected to give this task some thought. Conduct internet research if necessary. Just do your own work to code up a solution, and try to keep is as simple as possible. Again, you may be asked to explain your solution if you employ a standard method. If you are using a standard method that you found via internet research, be sure to include a code comment with a reference to the web resource(s) used. 

#### -- A note on dictionary compression

This README.md file has more than 1000 words. But it has only about 400 unique words, which means that many words are used repeatedly. That observation enables dictionary compression.  Imagine that every unique word in this document is in a 400-word dictionary, and that each word has a unique integer-id (1..n). A _very simple_ dictionary compressor looks at each word in the document (in order):

1. If we haven't seen the word yet, add it to the dictionary, and then write the word to the output stream
2. If we have see the word before, write the word-id (from dictionary) to the output stream (if word-id is shorter than word)

The resulting document will therefore be a combination of words, interspersed with word-ids.  Since the word-id is small (2 bytes), it occupies much less space that the actual word (5-6 characters long, on average).  As an example, given this input file:

```The best food is the best food for your body```  

Using a trivial dictionary compressor, the rewritten output looks like this (nearly an 20% reduction):

```the best food is 1 2 3 for your body```  

> The embedded numbers are word id's (1=the, 2=best, 3=food). 

The STL collections and algorithms can make a task like this much easier, so explore them before you write your code.

#### -- Additional ideas to further reduce content size

A very powerful technique for further compression is to reduce compound words to roots and suffixes. For example, your actual input file is a short document about "skateboarding" (root=skateboard). Rather than storing the words: `skateboard`, `skateboarding`, `stakeboarder` (etc) in the dictionary, you can store the root (skateboard) in the dictionary. Then as you see words like `skateboarding` you output the root word-id (for `skateboard`) and the suffix "ing" -- which may also be a word id. If your input file says:

```
skateboarding requires the stakeboarder to balance on her skateboard
```

...and your compressed output (33% compression) looks like this:

```
stakeboard 1-ing requires the 1-er to balance on her 1
```

A another excellent techinque worth considering, is to reduce repeating word-pairs to dictionary entries. For larger documents, this technique can pay a considerable benefit. You don't have to limit yourself to simple word pairs (bi-grams) either. Since writers commonly repeat word combinations, you might discover that larger word sequences are repeated too, and can improve compression even further.

### Part 3 -- Decompressing your compressed version

In this step, you will implement the method, `WordAnalyzer.decompress()`. This method will accept an input stream that contains the compressed output you generated earlier.  You task here is to decompress this content, so that it is equivalent to the original version of the file. Your output from this step is also captured and compared against the original. 

## Testing

We encourage you to write your own validation functions for each part of this assignment. Our autograder tests are by no means exhaustive and do NOT test full functionality (e.g. the tests included in the starter code for `countWords()` is simply testing the return value of the function and the number of lines printed to the output stream). Be sure to take a look at the code in `main.cpp` and `Testing.hpp` to understand what the autograder tests are checking (and not checking). For example, when you find word counts, you should call your own validaton function that confirms that your word counts are correct. For grading we will use our own version of this validation logic -- and your code will be compared again against this baseline.  We want you to start practicing writing your own tests for the code you write. 

### Grading 

1. Code compiles: 5%
2. Word Count: 30%
3. Word Pairs: 30%
4. Compress/decompress: 35%

