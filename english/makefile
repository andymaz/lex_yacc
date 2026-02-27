# Name of the final executable
TARGET = sentence

# The default 'make' command
all: $(TARGET)


# Build the scanner
$(TARGET): sentence.l
	@flex sentence.l
	@# Compile the generated C file and link with the flex library
	@gcc -o $(TARGET) lex.yy.c -lfl  

# Clean up generated files
clean:
	@ rm -f $(TARGET) lex.yy.c sentence