gcc -g -fpic --shared $(python-config --includes) greet.c -o greet.so
