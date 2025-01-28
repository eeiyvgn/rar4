#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <cstdint>

#pragma pack(push, 1)

struct VolumeHeaderFormat
{
    uint16_t header_crc;
    uint8_t header_type;
    uint16_t header_flags;
    uint16_t header_size;
};

struct FileHead
{
    uint32_t PackSize;
    uint32_t UnpSize;
    uint8_t HostOS;
    uint32_t FileCRC;
    uint32_t FileTime;
    uint8_t UnpVer;
    uint8_t Method;
    uint16_t NameSize;
    uint32_t FileAttr;
};

#pragma pack(pop)

#endif // HEADER_H_INCLUDED
