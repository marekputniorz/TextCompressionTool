# TextCompressionTool
Complex tool for text compression

## How does the program work?
Compression works by taking a sequence of the same characters in a row and replacing it with a pair containing the number of characters and the given character.

### Compiling
Compiling a program is very easy. Just type **cmake .** and then **make** in the command line and the program will be compiled.

### Starting the program
The program accepts only the following parameters:

- -i input - input file
- -o output - output file
- -b - binary mod
- -d - perform decompression

If the -d parameter is specified, decompression occurs.
If the -b parameter is not specified, (de) compression will take place in text mode.

### Example:

#### Text compression
./zipper -i text.txt -o text.zip
#### Text decompression
./zipper -d -i text.txt -o text.zip
#### Binary compression
./zipper -i text.txt -o text.zip -b
#### Binary decompression
./zipper -d -i text.zip -b -o text.txt
