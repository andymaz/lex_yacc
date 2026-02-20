TARGET = calculate

all: $(TARGET)

$(TARGET): calculate.l calculate.y
	bison -d calculate.y
	flex calculate.l
	# Use calculate.tab.c to match bison's default output
	gcc -o $(TARGET) calculate.tab.c lex.yy.c -lfl

clean:
	rm -f $(TARGET) lex.yy.c calculate.tab.c calculate.tab.h
