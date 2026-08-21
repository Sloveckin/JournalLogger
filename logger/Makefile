LIBRARY=liblogger.so

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
	-Iinclude\

SOURCE+=\
	src/data/Note.cpp
	src/data/excpetion/LoggerFileNotFound.cpp

OBJECTS := $(SOURCE:.cpp=.o)

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	g++ --shared $(CFLAGS) $^ -o $@

%.o: %.cpp
	g++ -c $(CFLAGS) $(INCLUDE) -fPIC $< -o $@

clean:
	rm -rf $(LIBRARY) $(OBJECTS)

.PHONY: all build