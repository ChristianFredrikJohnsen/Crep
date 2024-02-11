#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct {
  int x;
  int y;
  int z;
} Point;

Point *init(int elems) {
    int size = elems * sizeof(Point);

    // allocating memory using syscalls directly

    /*
    /dev/zero is a special file that provides as many null characters (0x00) as are read from it
    O_RDWR is for read and write
    fd is the file descriptor returned by open
    */
	int fd = open("/dev/zero", O_RDWR);
    
    /*
    0 means that the kernel will choose the address at which to create the mapping
    PROT_READ|PROT_WRITE means that the memory can be read and written
    MAP_PRIVATE means that the changes to the memory will not be visible to other processes
    fd is the file descriptor returned by open
    0 is the offset in the file where the mapping should start (0 means the beginning of the file)
    */
    
    Point *array = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);

    if (array == MAP_FAILED) {
        printf("Could not map memory: %s\n", strerror(errno));
		return NULL;
    }    
	
	for (int i = 0; i < size; ++i) {
        array[i].x = i;
        array[i].y = -i;
        array[i].z = i*i;
    }

    return array;
}

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        fprintf(stderr, "Usage: crash hello [NUM ELEMS]\n");
        return -1; // Indicates error
    }

    if (strcmp(argv[1], "hello")) {
        fprintf(stderr, "Second argument must be hello.\nThe second argument was: %s\n", argv[1]);
        return -1; // Indicates error
    }

    char *p;
    errno = 0;
    int elems = strtol(argv[2], &p, 10); // Converts the third argument from string to int

    if (*p != 0 || errno) {
        fprintf(stderr, "Invalid third argument: %s\n", argv[2]);
        return -1; // Indicates error
    }

    Point *points = init(elems);
    for(int i = 0; i < elems; i++) {
        printf("Point(%d, %d, %d)\n", points[i].x, points[i].y, points[i].z);
    }
    return 0;
}
