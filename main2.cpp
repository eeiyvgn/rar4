#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "header.h"

using namespace std;

void RAR_File()
{
    ifstream rar_file("Example.rar", ios::binary);

    if (rar_file.is_open())
    {
        rar_file.seekg(0, ios::end);
        int fileSize = rar_file.tellg();

        rar_file.seekg(0, ios::beg);

        vector<char> rar_data(fileSize, 0);

        rar_file.read(rar_data.data(), fileSize);

        size_t offset = 7;

        while (offset < rar_data.size())
        {
            const VolumeHeaderFormat* volume_header = reinterpret_cast<VolumeHeaderFormat*>(&rar_data[offset]);

            if (volume_header->header_type == 0x74)
            {
                const FileHead* file_head = reinterpret_cast<FileHead*>(&rar_data[offset + sizeof(VolumeHeaderFormat)]);

                size_t offset_name = offset + sizeof(VolumeHeaderFormat) + sizeof(FileHead);

                string file_name(reinterpret_cast<const char*>(&rar_data[offset_name]), file_head->NameSize);

                cout << file_name << endl;

                offset += volume_header->header_size + file_head->PackSize;
            }

            else
            {
                offset += volume_header->header_size;
            }
        }
    }
}
