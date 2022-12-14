CXX = g++
CXXFLAGS += -I external
CXXFLAGS += -I src

BDIR = build
$(shell mkdir -p $(BDIR)) # create the directory if it doesn't exist

EXE_NAME = qrng-service.out
EXECUTABLE = $(BDIR)/$(EXE_NAME)

OBJS += $(BDIR)/main.o
OBJS += $(BDIR)/prng.o
OBJS += $(BDIR)/qrng.o
OBJS += $(BDIR)/loguru.o

$(EXECUTABLE): $(OBJS)
	g++ -o $@ -l qrng $^

$(BDIR)/main.o: src/main.cpp
	g++ -c $(CXXFLAGS) -o $@ src/main.cpp

$(BDIR)/prng.o: src/prng.cpp src/prng.hpp src/rng.hpp
	g++ -c $(CXXFLAGS) -o $@ src/prng.cpp

$(BDIR)/qrng.o: src/prng.cpp src/prng.hpp src/rng.hpp
	g++ -c $(CXXFLAGS) -o $@ src/qrng.cpp

$(BDIR)/loguru.o: external/loguru/loguru.cpp external/loguru/loguru.hpp
	g++ -c $(CXXFLAGS) -o $@ external/loguru/loguru.cpp

run: $(EXECUTABLE)
	$(EXECUTABLE)

INSTALL_DIR:=/opt/qrng-service
SERVICE_DIR:=/etc/systemd/system

SERVICE:=./systemd/qrng.service

install: $(EXECUTABLE)
	mkdir -p $(INSTALL_DIR)
	cp $(EXECUTABLE) $(INSTALL_DIR)
	cp $(SERVICE) $(SERVICE_DIR)
	systemctl start qrng
	systemctl enable qrng
	systemctl status qrng

clean:
	rm -rf ./build