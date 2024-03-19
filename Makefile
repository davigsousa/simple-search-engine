CXX = g++  # Adjust if your compiler is different (e.g., clang++)
CXXFLAGS = -Wall -std=c++17  # Adjust flags as needed (-Wall enables warnings, -std=c++17 sets language standard)

# Target - name of your executable
TARGET = output/search_engine

# Object files - built from source files
SOURCES = $(shell find src -name "*.cpp")
OBJECTS = $(patsubst src/%.cpp,output/%.o,$(SOURCES))

# Rule to build the executable
$(TARGET): $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $(TARGET) $^

# Rule to build object files from source files (uses pattern rule)
output/%.o: src/%.cpp
		@mkdir -p $(@D)
		$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target for clean (won't build anything)
.PHONY: clean

# Rule to clean up object files
clean:
		rm -f $(OBJECTS) $(TARGET)
		rm -rf ./output

# Rule to run the program
start:
		@$(TARGET) $(ARGS)