# FIFO and FIFO_Type#

## FIFO ##

The `FIFO` class implements a _FIFO_ (first-in/first-out buffer) with a fixed capacity of bytes.  The FIFO is implemented with a [ring buffer](https://en.wikipedia.org/wiki/Circular_buffer "ring buffer").

Bytes are "pushed" into a FIFO one at a time, and they are "popped" back out with their push order preserved (first in, first out).  Pushes and pops may happen in any order, with two conditions.

1. Pushing into a full FIFO will cause the oldest byte in the FIFO to be lost.
2. Popping from an empty FIFO will return a zero byte.

If these behaviors are not desired, methods are provided to test if a FIFO is full or empty; it will often be neither.
An additional method is available to clear the current contents of the FIFO, leaving it empty.

Beware of creating a FIFO that's too large; because it resides in the processor's RAM, you're constrained by available RAM.  For example, an Arduino Uno has only 2048 bytes of RAM, and some of that will be used by other variables in your code and the libraries you use.

## FIFO_Type ##

The `FIFO_Type` class is a _template class_ built upon the byte-oriented `FIFO` class.  `FIFO_Type` allows the FIFO to work with any of these types rather than just bytes:

- `bool`
- `byte` (same as `FIFO`)
- `word`
- `size_t`
- `char` and `unsigned char`
- `short` and `unsigned short`
- `int` and `unsigned int`
- `long` and `unsigned long`

A `FIFO_Type` object is declared by appending the class type with the data type to be used.

```
	FIFO byte_stuff(4);					// FIFO object of bytes, capacity of 4
	FIFO_Type<long> long_stuff(5);		// FIFO object of longs, capacity of 5
```
Keep in mind that `byte_stuff` will take up 4 bytes of RAM storage for the data, while `long_stuff` will require 5 * `sizeof(long)` or 20 bytes to hold its data.

## Dependencies ##

The `FIFO` library has no dependencies on any other libraries.

## Examples ##

The `examples` directory contains two sample sketches. `FIFO_Test.ino` shows how the `FIFO` class is used, while `FIFO_Type_Test.ino` demonstrates the `FIFO_Type` template class.  The example sketches have no dependencies besides the `FIFO` library.

## Installation ##

Instructions for installing the `FIFO` class can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/FIFO-library/blob/main/INSTALL.md](https://github.com/twrackers/FIFO-library/blob/main/INSTALL.md).

## Note ##

The `FIFO` library replaces the `RingBuffer` library (now deprecated) at [https://github.com/twrackers/RingBuffer-library](https://github.com/twrackers/RingBuffer-library).  New projects should use the `FIFO` library instead of `RingBuffer`.
