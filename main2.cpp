#include "header.h"

using namespace std;

void RAR_File()
{
    ifstream rar_file("Example.rar", ios::binary);

    if (rar_file.is_open())
    {
        rar_file.seekg(0, ios::end);
        int fileSize = rar_file.tellg();
        cout << fileSize << endl;

        rar_file.seekg(0, ios::beg);

        vector<char> rar_data(fileSize, 0);

        rar_file.read(rar_data.data(), fileSize);
    }
}
