# CS 4280: Program Translation Project 0

A program to build a tree and print it using the following traversals:

* Preorder
* Inorder
* Postorder

## How to Run
`./P0 [file]`

* Where *file* is an optional argument.
* If the *file* argument is not given, then the program reads data from the keyboard.
* If the *file* argument is given, then the program reads data from the file specified. (*file* is any name and the extension is implicit)

### Example Invocations
* `PO` - Read from the keyboard until simulated EOF.
* `PO < somefile` - Redirecting from *somefile* instead of keyboard input.
* `PO somefile` - Read from *somefile*.

## Output
* The program outputs **3 files** corresponding to the 3 traversals:
  * `file.preorder`
  * `file.inorder`
  * `file.postorder`
* *file* is the name of input if given, and "*out*" if the input is from the keyboard.

