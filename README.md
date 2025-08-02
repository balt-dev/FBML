# FBML
A codemod loader for Fractal Block World. Written in C.

## TODO
[ ] Add API for hooking and calling functions (start with one for testing)
[ ] Populate hook API with helpers for all functions in game
	[ ] Write Ghidra script to make updating this not hell in a handbasket when the game updates
	- Calling an original game function probably looks like `FBW_<function name>(...)`
	- API needs to support chaining hooks
