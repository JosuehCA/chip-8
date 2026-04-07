#include <cstdint>	// fixed-width types
#include <fstream>	// file system manipulation

const unsigned int PC_START_ADDRESS = 200;

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