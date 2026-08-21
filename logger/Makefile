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
	src/Logger.cpp\
	src/data/Note.cpp\
	src/exception/logger/LoggerException.cpp\
	src/exception/logger/LoggerFileNotFound.cpp\
	src/exception/logger/LoggerWriteException.cpp\

OBJECTS := $(SOURCE:.cpp=.o)

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	g++ --shared $(CFLAGS) $^ -o $@

%.o: %.cpp
	g++ -c $(CFLAGS) $(INCLUDE) -fPIC $< -o $@

clean:
	rm -rf $(LIBRARY) $(OBJECTS)

.PHONY: all build