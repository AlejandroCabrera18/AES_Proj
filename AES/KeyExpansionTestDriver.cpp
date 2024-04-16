#include "aes_128_Common.h"

int main()
{
    byte *key = string_to_byte_array("FLORIDAPOLYUNIV");
    cout << "The original key is: ";

    print_byte_array(key);

    cout << "The expanded key is: " << endl;

    g_function(key);
    print_byte_array(key);

    return 0;
}
