Playing around with xxd and it's ability to generate C headers from binary 
files. It's an easy way to embed binary data into an executable.

    xxd -i nic.jpeg > nic.h  # I already did this
    gcc -o embed embed.c
    ./embed 
    display cage_out.jpeg

