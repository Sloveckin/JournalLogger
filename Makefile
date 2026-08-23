BINARY=JournalWriter
BUILD=debug

STANDART=17

ifeq ($(BUILD),debug)
	CFLAGS+= \
		-g \
		-fsanitize=thread
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

library:
	$(MAKE) -C logger BUILD=$(BUILD)


$(BINARY): $(OBJECTS)
	g++ $(CFLAGS) -o $@ $^ $(LDPATH) $(LIBS)

%.o:%.cpp
	g++ -c --std=c++$(STANDART) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	$(MAKE) -C logger clean
	rm -rf $(BINARY) $(OBJECTS)

.PHONY: all clean

