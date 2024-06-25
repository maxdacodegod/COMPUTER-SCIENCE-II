#include <stdio.h>
#include "bit_flags.h"

int main(int argc, char* argv[])
{
    BIT_FLAGS hBit_flags = bit_flags_init_number_of_bits(2000000000);
    printf("Size: %d\n", bit_flags_get_size(hBit_flags));
    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    // Attempt to set a flag at position 2 billion
    if (bit_flags_set_flag(hBit_flags, 2000000000) == FAILURE) {
        printf("Failed to set flag at position 2 billion\n");
    }

    // Attempt to unset a flag at position 2 billion
    if (bit_flags_unset_flag(hBit_flags, 2000000000) == FAILURE) {
        printf("Failed to unset flag at position 2 billion\n");
    }
    
    
    bit_flags_destroy(&hBit_flags);
    return 0;
}

/*
int main(int argc, char* argv[])
{
    // Initialize a bit flag structure with 32 bits
    BIT_FLAGS hBit_flags = bit_flags_init_number_of_bits(32);
    if (hBit_flags == NULL) {
        printf("Failed to initialize bit flags.\n");
        return 1;
    }

    // Set the 101st bit
    if (bit_flags_set_flag(hBit_flags, 100) == FAILURE) {
        printf("Failed to set bit.\n");
        return 1;
    }

    // Check the 101st bit
    int check = bit_flags_check_flag(hBit_flags, 100);
    if (check == -1) {
        printf("Failed to check bit.\n");
        return 1;
    }
    printf("The value of the 101st bit is: %d\n", check);

    // Get the size and capacity
    printf("Size: %d\n", bit_flags_get_size(hBit_flags));
    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    // Unset the 101st bit
    if (bit_flags_unset_flag(hBit_flags, 100) == FAILURE) {
        printf("Failed to unset bit.\n");
        return 1;
    }

    // Check the 101st bit again
    check = bit_flags_check_flag(hBit_flags, 100);
    if (check == -1) {
        printf("Failed to check bit.\n");
        return 1;
    }
    printf("The value of the 101st bit after unsetting is: %d\n", check);

    // Get the size and capacity again
    printf("Size after unsetting: %d\n", bit_flags_get_size(hBit_flags));
    printf("Capacity after unsetting: %d\n", bit_flags_get_capacity(hBit_flags));

    // Destroy the bit flags structure
    bit_flags_destroy(&hBit_flags);
    if (hBit_flags!= NULL) 
    {
        printf("Failed to destroy bit flags.\n");
        return 1;
    }

    return 0;
}
*/

/*
int main(int argc, char* argv[])
{
    // Initialize a bit flag structure with 32 bits
    BIT_FLAGS hBit_flags = bit_flags_init_number_of_bits(32);
    if (hBit_flags == NULL) {
        printf("Failed to initialize bit flags.\n");
        return 1;
    }

    // Set the 1st, 10th, and 31st bits
    if (bit_flags_set_flag(hBit_flags, 0) == FAILURE ||
        bit_flags_set_flag(hBit_flags, 9) == FAILURE ||
        bit_flags_set_flag(hBit_flags, 30) == FAILURE) {
        printf("Failed to set bit.\n");
        return 1;
    }

    // Check the 1st, 10th, and 31st bits
    for (int i = 0; i < 32; i++) {
        int check = bit_flags_check_flag(hBit_flags, i);
        if (check == -1) {
            printf("Failed to check bit.\n");
            return 1;
        }
        printf("The value of the %d'th bit is: %d\n", i, check);
    }

    // Unset the 10th bit
    if (bit_flags_unset_flag(hBit_flags, 9) == FAILURE) {
        printf("Failed to unset bit.\n");
        return 1;
    }

    // Check the 10th bit again
    int check = bit_flags_check_flag(hBit_flags, 9);
    if (check == -1) {
        printf("Failed to check bit.\n");
        return 1;
    }
    printf("The value of the 10th bit after unsetting is: %d\n", check);

    // Get the size and capacity
    printf("Size: %d\n", bit_flags_get_size(hBit_flags));
    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    // Destroy the bit flags structure
    bit_flags_destroy(&hBit_flags);
    
    if (hBit_flags != NULL) {
        printf("Failed to destroy bit flags.\n");
        return 1;
    }

    return 0;
}
*/


/*
int main(int argc, char* argv[]) 
{
    // Initialize a bit flag structure with 10 bits
    BIT_FLAGS hBit_flags = bit_flags_init_number_of_bits(10);
    if (hBit_flags == NULL) {
        printf("Failed to initialize bit flags.\n");
        return 1;
    }

    // Set the 3rd bit
    if (bit_flags_set_flag(hBit_flags, 100) == FAILURE) {
        printf("Failed to set bit.\n");
        return 1;
    }

    // Check the 3rd bit
    int check = bit_flags_check_flag(hBit_flags, 100);
    if (check == -1) {
        printf("Failed to check bit.\n");
        return 1;
    }
    printf("The value of the n'th bit is: %d\n", check);

    // Unset the 3rd bit
    if (bit_flags_unset_flag(hBit_flags, 100) == FAILURE) {
        printf("Failed to unset bit.\n");
        return 1;
    }

    // Check the 3rd bit again
    check = bit_flags_check_flag(hBit_flags, 100);
    if (check == -1) {
        printf("Failed to check bit.\n");
        return 1;
    }
    printf("The value of the n'th bit after unsetting is: %d\n", check);

    // Get the size and capacity
    printf("Size: %d\n", bit_flags_get_size(hBit_flags));
    printf("Capacity: %d\n", bit_flags_get_capacity(hBit_flags));

    // Destroy the bit flags structure

    bit_flags_destroy(&hBit_flags);
    if (hBit_flags != NULL) {
        printf("Failed to destroy bit flags.\n");
        return 1;
    }

    return 0;
}
*/