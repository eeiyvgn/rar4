#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

#pragma pack(push, 1)

struct VolumeHeaderFormat
{
    uint16_t header_crc;
    uint8_t header_type;
    uint16_t header_flags;
    uint16_t header_size;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
