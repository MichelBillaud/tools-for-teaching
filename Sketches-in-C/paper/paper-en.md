% A Processing-like environment for teaching C to beginners
% Michel Billaud 
% 16 january 2020

(c) Michel Billaud, <michel.billaud@laposte.net>, 2020

# Motivation for this work

## Beginners need interesting exercices

- Learning computer programming involve a lot of practice,
- So exemples and exercises given to students must
be interesting,
- and sufficiently attractive to them, so they are motivated
to imagine and realize their own programs.

During the 50-60's, computer programming was mostly taught to student
with a scientific background, so they can develop their own number
crunching examples in FORTRAN.  Their background allowed examples with
some level of
mathematical computations (statistics, linear algebra, arithmetics,
différential equation solving etc.).

Nowadays, such examples are much less motivating for our students who
start learning how to program.  Multiplying two matrices is only a
good exercice with embedded loops, only if you don't have to
waste precious time explaining what a matrix is.


## Avoid mysteries

Even the traditional `HelloWorld` first program in Java involves a
large number of notions: `class`, `Main` method as en entry point,
`static`, the `System.out` object and its methods etc.

Teachers usually don't try to provide explanations et this point,
anyway these are details that can't be ignored.  This disturbs the
students, leaving them with the impression that the programming is
full of magic spellings.

## Why Processing is a success

This explains the success of an environment like  Processing, 
where  

- simple  programs can be written
by beginners without much explanations.
- graphics and animations can be done easily.

Practice, and hence the motivation to practice, is the key for a successful
learning of computer programmine.

This type of exemples/exercices is much more likely to motivate their
own exercices, at home then the traditional solving of second-degree
equations or summing the elements of an array.

## So ?

We're trying to develop something similar for C programming,
with a library hiding the complexity of SDL.
