LIBRARY=liblogger.so

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
	-Iinclude\

SOURCE+=\
	src/Logger.cpp\
	src/data/Note.cpp\
	src/data/Importance.cpp\
	src/exception/logger/LoggerException.cpp\
	src/exception/logger/LoggerFileNotFound.cpp\
	src/exception/logger/LoggerWriteException.cpp\

OBJECTS := $(SOURCE:.cpp=.o)

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	g++ --shared $(CFLAGS) $^ -o $@

%.o: %.cpp
	g++ -c --std=c++$(STANDART) $(CFLAGS) $(INCLUDE) -fPIC $< -o $@

clean:
	rm -rf $(LIBRARY) $(OBJECTS)

.PHONY: all build