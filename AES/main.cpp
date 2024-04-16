#include <iostream>
#include "include/aes_128_common.h"

using namespace std;

int main() {

    /**********************************************************
     * The content of this function can be completely replaced
     **********************************************************/
    byte *key = string_to_byte_array("FLORIDAPOLYUNIV");
    byte *plaintext_block = string_to_byte_array("AES-128 is great!");

    newline();
    cout << "Key: ";
    print_byte_array(key, 16);

    newline();
    cout << "Plaintext block:" << endl;
    print_state(plaintext_block);


    delete key;
    delete plaintext_block;

    return 0;
}
