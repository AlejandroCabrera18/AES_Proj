#include <iostream>
#include "include/aes_128_common.h"
#include "include/aes_128_encrypt.h"

using namespace std;

int main() {
	byte* key = string_to_byte_array("FLORIDAPOLYUNIV");
	byte* plaintext_block = string_to_byte_array("AES-128 is great!");
	newline();
	cout << "Key: ";
	print_byte_array(key, 16);

	newline();
	cout << "Plaintext block:" << endl;
	print_state(plaintext_block);

	byte* ciphertext_block = encrypt_aes_128(plaintext_block, key);
	cout << "Ciphertext Returned:" << endl;
	print_state(ciphertext_block);

	delete key;
	delete plaintext_block;

	return 0;
}
