# Theory




## 1)
What do you have to do before you can run your C-program? Which steps do you have to
repeat if you change anything in your code such that the changed code is executed?

You have to compile the code before you can run it. If you change anything in your code, you have to recompile it before you can run it again.

## 2)

As we highlighted in the exercise lecture, the compiler is your friend. With what can the
compiler help you? Which things can the compiler not help you with? Which other tools
can you use if the compiler cannot provide support?


To a certain extent, the IDE (VSCode in my case) does some of the work which originally was done by the compiler. The compiler can help you with:

- Syntax errors
- Type checking
- Warnings
- Error reporting (stack smashing, variable redeclaration, etc.)

The compiler cannot help you with:
- Logical errors (doing the wrong thing, but the code is syntactically correct and logically consistent)
- Runtime errors (e.g. division by zero)
- Memory management errors (e.g. memory leaks)


The tools which we are supposed to use in this course are:
- Valgrind
- GDB

Valgrind is for memory management errors and GDB is for runtime errors. First, a bit about what Valgrind checks for specifically:

- Use of uninitialized memory
- Memory leaks (allocated but not freed)
- Incorrect freeing of memory (e.g. freeing the same memory twice)

We use the command:

```bash
valgrind --leak-check=full ./a
```

to check for memory leaks in the compiled program of the file **a.c**









## 3)


