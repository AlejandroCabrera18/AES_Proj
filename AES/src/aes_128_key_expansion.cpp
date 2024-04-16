/*#include "AES128_keyexpand.h"
#include "aes_128_Common.h"
*/

#include "../include/aes_128_key_expansion.h"
#include "../include/aes_128_common.h"

// Circular Left Shift (Rotate Left)
void circular_left_shift(byte* byte_word) {
	byte temp;

	temp = byte_word[0];
	byte_word[0] = byte_word[1];
	byte_word[1] = byte_word[2];
	byte_word[2] = byte_word[3];
	byte_word[3] = temp;
}

// Add Round Constant
void add_round_constant(byte* byte_word, unsigned char round_number) {
	unsigned char c = 1;
	for (int i = 0; i < round_number - 1; i++)
	{
		c = (c << 1) ^ (((c >> 7) & 1) * 0x1b);
	}

	byte_word[0] = c;
	byte_word[1] = byte_word[2] = byte_word[3] = 0;
}


// The g function of the AES key expansion
byte * g_function(byte * byte_word)
{
	byte* g_return_word = new byte[4];
	byte key = get_round_key();
	byte w[44];
	byte temp;

	for (int i = 0; i < 4; i++)
	{
		w[i] = (key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
	}

	for (int i = 0; i < 44; i++)
	{
		temp = w[i - 1];
		if (i mod 4 = 0)
		{
			temp = substitute_bytes(circular_left_shift(byte_word)) ^ add_round_constant();
		}
		w[i] = w[i - 4] ^ temp;
	}
	g_return_word = w;

	return g_return_word;
}


// Get round key
// Note: Don't forget to delete the return og the g_function once you are done using it
byte* get_round_key(byte * key_bytes, unsigned char round_number) {
	byte* round_key = new byte[16];

	for (unsigned char round_number = 1; round_number <= 10; round_number++)
	{
		*round_key = substitute_bytes(*key_bytes) ^ add_round_constant(*key_bytes, round_number);
	}

	return round_key;
}

