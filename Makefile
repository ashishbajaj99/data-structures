# The MIT License (MIT)
# Copyright (c) 2015 Ashish Bajaj bajaj.ashish@gmail.com

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
# associated documentation files (the "Software"), to deal in the Software without restriction, including 
# without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
# copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the 
# following conditions:
# The above copyright notice and this permission notice shall be included in all copies or substantial 
# portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
# LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
# THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# A Makefile for the data-structures ANSI C project
# This Makefile demonstrates and explains:
# 1. Macros
# 2. Targets and Dummy Targets
# 3. Dependencies, and Pattern Rules

# Toolchain Macro Definitions
CC = gcc
LINK_FLAGS = -g
COMPILE_FLAGS = -g -c
DEP_FLAGS = -MMD -MP -c -w

# Final Target Macro Definition
LINK_TARGET = test-example

# List of Object files. One per source file should be listed here.
OBJS =  linkedList.o \
		asciiList.o  \
		binaryTree.o \
		asciiTree.o  \
		queue.o      \
		sorting.o    \
		main.o

# $(macro-name) does a textual replacement in Makefiles
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# all is the dummy target that will cause the complete build to kick start 
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all: $(LINK_TARGET)


# $@ expands to the rule's target, in this case "test-example".
# $^ expands to the rule's dependencies, in this case the list of object files
$(LINK_TARGET): $(OBJS)
	$(CC) $(LINK_FLAGS) $^ -o $@

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .c suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o: %.c
	$(CC) $(COMPILE_FLAGS) $< -o $@ 

# Clean is a dummy target to clean up build files generated via the build process
clean: 
	rm -f $(REBUILDABLES)

# Clean is a dummy target to clean up all the temporary files generated via the build process
clean-all: 
	rm -f $(REBUILDABLES) *~ *.DS_Store* *.d *.log

# Automated dependency generator
# First Make will include all the .d files and generate them
%.d: %.c
	$(CC) $(DEP_FLAGS) $<

# Include all the .d files only when NOT cleaning
ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), clean-all)
-include $(OBJS:.o=.d)
endif
endif

