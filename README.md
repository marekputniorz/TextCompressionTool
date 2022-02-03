# TextCompressionTool
Complex tool for text compression

## How does the program work?

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

./zipper -i text.txt -o text.zip
./zipper -i text.txt -o text.zip -b

./zipper -d -i text.zip -b -o text.txt
