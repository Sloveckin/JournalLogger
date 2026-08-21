BINARY=JournalWriter
BUILD=debug

ifeq ($(BUILD),debug)
	CFLAGS+= \
		-g \
		-fsanitize=address \
		-fsanitize=pointer-compare \
		-fsanitize=pointer-subtract \
		-fsanitize=undefined \
		-fsanitize-address-use-after-scope
endif

ifeq ($(BUILD),release)
	CFLAGS+= \
		-O3
endif

INCLUDE+=\
	-Ilogger/include\

LDPATH+=\
	-Llogger\

LIBS+=\
	-llogger\

SOURCE+=\
	main.cpp

OBJECTS := $(SOURCE:.cpp=.o)

all: $(BINARY)

$(BINARY): $(OBJECTS)
	g++ $(CFLAGS) -o $@ $^ $(LDPATH) $(LIBS)

%.o:%.cpp
	g++ $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BINARY) $(OBJECTS)

.PHONY: all clean