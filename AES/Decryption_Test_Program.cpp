#include <iostream>
#include "include/aes_128_common.h"
#include "include/aes_128_decrypt.h"

using namespace std;

int main() {
	byte* key = string_to_byte_array("FLORIDAPOLYUNIV");
	byte* ciphertext_block = string_to_byte_array("5oykHkdVKtRQJjIBeAtRrQtwWVraBStTDn3KB0j2vRM");
	newline();
	cout << "Key: ";
	print_byte_array(key, 16);

	newline();
	cout << "Ciphertext block:" << endl;
	print_state(ciphertext_block);

	byte* plaintext_block = decrypt_aes_128(ciphertext_block, key);
	cout << "Plaintext Returned:" << endl;
	print_state(plaintext_block);

	delete key;
	delete ciphertext_block;

	return 0;
}
