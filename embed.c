#include <stdio.h>
#include "nic.h"

#define CHUNK_SIZE 1024

int main(int argc, char *argv[]) {
    printf("Get ready for Cage!\n");

    FILE *f = fopen("cage_out.jpeg", "wb");
    unsigned int total_bytes_read = 0;
    size_t bytes_written;
    unsigned char *p = nic_jpeg;

    while (total_bytes_read + CHUNK_SIZE < nic_jpeg_len) {
      bytes_written = fwrite(p, 1, CHUNK_SIZE, f);
      total_bytes_read += bytes_written;
      p += bytes_written;
    }
    // last chunk
    fwrite(p, 1, nic_jpeg_len - total_bytes_read, f);

    fclose(f);
}
