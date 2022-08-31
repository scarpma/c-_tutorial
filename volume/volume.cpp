// Modifies the volume of an audio file

#include <iostream>
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

void print_binary(uint8_t *p, int start, int end, int group) {
    // p is the pointer to uint8_t array
    // start is from where to start printing
    // end is where to stop
    // group is the size of each group (just for printing style)

    for (int i=start;i<end;i++) {
        if ((i-start)%group != 0 or i==start) {
            cout << p[i];
        } else {
            cout << " " << p[i];
        }
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, input);    // read byte per byte
    fwrite(header, 1, HEADER_SIZE, output);  // read byte per byte
    cout << "header content in ascii: ";
    print_binary(header, 0, HEADER_SIZE, 4); // copy header to output file

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    int count = 0;
    while (fread(&buffer, 1, sizeof(int16_t), input)) { // read 2 bytes (sizeof(int16_t)) at a time
        buffer *= factor;
        fwrite(&buffer, 1, sizeof(int16_t) , output);
        count++;
    }

    cout << "found " << count << " samples, 16-bits each." << endl;

    // Close files
    fclose(input);
    fclose(output);
}











