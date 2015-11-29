data-structures
=============

This code is free to use and abuse as you like - I dont care if you use it for monetory gain, in your project or otherwise. Go ahead and knock yourself out! This is an example implmenetation of commonly used data structures in computer science courses taught as "Algorithms and Data Structures". I chose to implement these in C. Motivation for this is to make it easy for students learning computer science OR for those preparing for job interviews to have some example references of implmentation.

For people utilizing this to learn, I recommend downloading the code and re-writing some of the core functions yourself for practice. Software is never learnt by just looking at examples, its learnt by writing software yourself.

Download and Executing (on a bash prompt)
============
I assume you have gcc, and make installed. If not, get them.
```
$ git clone https://github.com/ashishbajaj99/data-structures
$ cd data-structures
$ make
$ ./test-example linked-list
$ ./test-example bst
$ ./test-example linked-list bst avl-tree
```
Here are my tools versions, in case you are using different versions, please make changes in the Makefile (its fairly well documented):
```
$ make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
$ gcc --version
gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 7.0.0 (clang-700.1.76)
Target: x86_64-apple-darwin14.5.0
Thread model: posix

```

File Structure and Code
============
main.c - This contains the entry point to test the data-structure code.
asciiList.c/.h - This contains functions to print the contents of a linked list to a console
asciiTree.c/.h - This contains functions to print the contents of a binary search tree to a console
linkedList.c/.h - This contains functions to add/remove/find/clear linked list


Note: The asciitree.c file was downloaded from the internet - its not my code. Its a nifty little piece of software for humanly readable representation of a binary tree on a console. For more details see the stackoverflow question here: [how to draw a binary tree to the console](http://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console)

License
==========
The MIT License (MIT)

Copyright (c) 2015 Ashish Bajaj bajaj.ashish@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
