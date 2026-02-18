# Name of the final executable
TARGET = calc

# The default 'make' command
all: $(TARGET)

$(TARGET): lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	gcc -o $(TARGET) parser.tab.c lex.yy.c

# Clean up generated files
clean:
	rm -f $(TARGET) lex.yy.c parser.tab.c parser.tab.h