#include <cstdint>	// fixed-width types

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
};

int main() {
	

	return 0;
}