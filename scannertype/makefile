# Name of the final executable
TARGET = scannertype

# Default target
all: $(TARGET)

# Build the scanner
$(TARGET): codescanner.l scannertype.c scannertype.h
	flex codescanner.l
	gcc -o $(TARGET) scannertype.c lex.yy.c -lfl

# Clean up generated files
clean:
	rm -f $(TARGET) lex.yy.c
