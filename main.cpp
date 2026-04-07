#include <cstdint>	// fixed-width types
#include <fstream>	// file system manipulation

const unsigned int PC_START_ADDRESS = 200;
const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int FONTSET_SIZE = 80;

uint8_t fontset[FONTSET_SIZE] = {	// Built-in characters (0-F). Sprites of 5 bytes each
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

class Chip8 {
public:
	uint8_t V[16]{};			// registers
	uint8_t memory[4096]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[16]{};
	uint8_t sp{};
	uint8_t delaytimer{};
	uint8_t soundtimer{};
	uint8_t keypad[16]{};
	uint32_t gfx[64 * 32]{};
	uint16_t opcode;

	Chip8();
	void LoadROM(const char* filename);
};

Chip8::Chip8() 
	: randGen(std::chrono::system_clock::now().time_since_epoch().count()),
	  randByte(0, 255U)
{
	pc = PC_START_ADDRESS;

	for(unsigned int i = 0; i < FONTSET_SIZE; i++) {
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
};

void Chip8::LoadROM(const char* filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if(file.is_open()) {
		std::streampos size = file.tellg();
		char* buffer = new char[size];

		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();

		for(long i = 0; i < size; i++) {
			memory[PC_START_ADDRESS + i] = buffer[i];
		}

		delete[] buffer;
	}
}

int main() {
	

	return 0;
}